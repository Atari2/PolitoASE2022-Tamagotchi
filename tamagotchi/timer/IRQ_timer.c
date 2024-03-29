/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../GLCD/GLCD.h"
#include "../drawing/drawing.h"
#include "../images/imagedata.h"
#include "../RIT/RIT.h"
#include "../adc/adc.h"
#include "../sound/libsound.h"
#include <stdlib.h>
#include <stdio.h>

extern volatile _Bool drawing;
extern volatile SelectedButton selected;

static const uint8_t tot_bars = 8;

volatile int8_t seconds = -1; // starts from second -1 to simulate second 0
volatile int8_t minutes = 0;
volatile int8_t hours = 0;
volatile uint8_t full_bars_happ = tot_bars + 1;
volatile uint8_t full_bars_sat = tot_bars + 1;
volatile _Bool start_food_animation = 0;
volatile _Bool start_snack_animation = 0;
volatile enum PlayerState player_state = Idle;
volatile enum SoundType current_sound = S_None;
static int32_t running_animation_frame_counter = 0;
static int32_t eating_animation_frame_counter = 0;
static int32_t cuddling_animation_frame_counter = 0;
static uint32_t generic_animation_counter = 0;
extern Coords player_coords;
extern int volume;

void reset_global_timer_state() {
	seconds = -1; // starts from second -1 to simulate second 0
	minutes = 0;
	hours = 0;
	full_bars_happ = tot_bars + 1;
	full_bars_sat = tot_bars + 1;
	start_food_animation = 0;
	start_snack_animation = 0;
	player_state = Idle;
	running_animation_frame_counter = 0;
	eating_animation_frame_counter = 0;
	cuddling_animation_frame_counter = 0;
	generic_animation_counter = 0;
}

static const char numbers[60][3] = {
	"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", 
	"20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", 
	"40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59"
};

void format_time(char buf[14]) {
	snprintf(buf, 14, "Age: %s:%s:%s", numbers[hours], numbers[minutes], numbers[seconds]);
}

void advance_time() {
	char tmp[14];
	Coords text_origin = {0, 10};
	if (++seconds == 60) {
		seconds = 0;
		if (++minutes == 60) {
			minutes = 0;
			++hours;
		}
	}
	format_time(tmp);
	center_text_in_rect(&text_origin, 240, 20, sizeof(tmp) - 1, 1);
	draw_text_bg(text_origin.x, text_origin.y, tmp, Black, White);
}

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER0_IRQHandler (void)
{
	Coords center = {0, 0};
	if (player_state != Idle) {
		LPC_TIM0->IR = 1;			// in theory we should never get here but this is a failsafe
		return;
	}
	advance_time();
	if ((seconds % 5) == 0) {
		--full_bars_happ;
		--full_bars_sat;
		if (full_bars_happ == tot_bars && full_bars_sat == tot_bars) {
			draw_batteries(tot_bars, full_bars_happ, full_bars_sat);
		} else {
			draw_single_bar(full_bars_happ, 0, 0);
			draw_single_bar(full_bars_sat, 1, 0);
		}
		if (full_bars_happ == 0 || full_bars_sat == 0) {
			// bars empty, tamagotchi starts running
			disable_RIT();
			disable_timer(Timer0); 	// disable self
			current_sound = S_Running;
			player_state = Running;
			LPC_TIM0->IR = 1;			// clear interrupt flag and return early
			return;
		}
	}
	center_rect_in_rect(&center, LCD_WIDTH / PX_RT, LCD_HEIGHT / PX_RT, IDLE_WIDTH, IDLE_HEIGHT);
	player_coords.x = center.x * PX_RT;
	player_coords.y = center.y * PX_RT;
	if ((seconds & 1) == 0) {
		draw_image(center, IDLE_WIDTH, IDLE_HEIGHT, idleMatrix);
	} else {
		draw_image(center, IDLE_2_WIDTH, IDLE_2_HEIGHT, idle_2Matrix);
	}
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}

void draw_running_animation(uint32_t animation_counter) {
	const int8_t FRAME_TICKS = 8;
	const int32_t disl_base = 8;
	const int32_t disl = disl_base * PX_RT;
	const uint16_t boxBgColor = RGB565CONVERT(0xFF, 0xA5, 0x00);
	uint16_t width = RUNNING1_WIDTH;
	uint16_t height = RUNNING1_HEIGHT;
	const char stoppedTxt[] = "Mario ran away :(";
	const char resetTxt[] = "Reset";
	Coords center = {0, 0};
	
	if (animation_counter % FRAME_TICKS == 0) {
		// every 10 ticks of frame counter, we do a frame of animation
		center_rect_in_rect(&center, (LCD_WIDTH - (running_animation_frame_counter * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
		switch (running_animation_frame_counter) {
			case 0:
			case 2:
				draw_image(center, width, height, running1Matrix);
				break;
			case 1:
			case 3:
				draw_image(center, width, height, running2Matrix);
				break;
			default:
				if ((running_animation_frame_counter & 1) == 0) {
					draw_image(center, width, height, running6Matrix);
				} else {
					draw_image(center, width, height, running5Matrix);
				}
				break;
		}

		if (center.x <= (disl_base - width)) {
			running_animation_frame_counter = 0;
			player_state = Stopped;
			center.x = 0;
			center.y = 0;
			center_rect_in_rect(&center, LCD_WIDTH, LCD_HEIGHT, LCD_WIDTH - 40, 50);
			draw_rect(center, LCD_WIDTH - 40, 50, 2, Black, NULL);
			center_text_in_rect(&center, LCD_WIDTH - 40, 50, sizeof(stoppedTxt) - 1, 1);
			draw_text(center.x, center.y, stoppedTxt, Black, 1);
			center.x = 0;
			center.y =	LCD_HEIGHT - 60 - 1;
			draw_rect(center, LCD_WIDTH, 60, 2, Red, &boxBgColor); 
			center_text_in_rect(&center, LCD_WIDTH, 60, sizeof(resetTxt) - 1, 2);
			draw_text(center.x, center.y, resetTxt, Black, 2);
			disable_timer(Timer1);
			enable_RIT();
			return;
		}
		running_animation_frame_counter++;
	}
}

void draw_eating_animation(uint32_t animation_counter) {
	const int8_t FRAME_TICKS = 8;	// considering setting this to 5, 1 frame tick is 50 ms
																// so 50ms*5 = 250ms per frame of animation
																// if there are 7 frames, 250ms*7 = 1.75 sec
																// it's currently at 50ms*8*7 = 2.8 sec
																// 8 is also a cool number because n % 8 can be transformed into
																// n & (8-1) by the compiler which is way faster.
	const int32_t disl = 8 * PX_RT;
	const uint16_t bgColor = White;
	uint16_t width = RUNNING1_WIDTH;
	uint16_t height = RUNNING1_HEIGHT;
	Coords center = {0, 0};
	Coords food_coords = {15, 180};
	_Bool done = 0;
	if (!start_food_animation) {
			food_coords.y += 5;
	}
	if (eating_animation_frame_counter == 0) {
		draw_image_noscale(food_coords, PIZZA_WIDTH, PIZZA_HEIGHT, start_food_animation ? pizzaMatrix : donutMatrix);
	}
	if (animation_counter % FRAME_TICKS == 0) {
		// every 10 ticks of frame counter, we do a frame of animation
		switch (eating_animation_frame_counter) {
			case 0:
			case 2:
				center_rect_in_rect(&center, (LCD_WIDTH - (eating_animation_frame_counter * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image(center, width, height, running1Matrix);
				break;
			case 1:
				center_rect_in_rect(&center, (LCD_WIDTH - disl) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image(center, width, height, running2Matrix);
				break;
			case 3:
				current_sound = S_Eating;
				center_rect_in_rect(&center, (LCD_WIDTH - (3 * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image(center, width, height, crouchedMatrix);
				break;
			case 4:
				center_rect_in_rect(&center, (LCD_WIDTH - (3 * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image(center, width, height, start_food_animation ? eatingpizzaMatrix : eatingdonutMatrix);
				break;
			case 7:
			case 5:
				center_rect_in_rect(&center, (LCD_WIDTH - ((8-eating_animation_frame_counter) * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image_flipped(center, width, height, running1Matrix);
				break;
			case 6:
				center_rect_in_rect(&center, (LCD_WIDTH - 2*disl) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image_flipped(center, width, height, running2Matrix);
				break;
			default:
				done = 1;
				break;
		}
		if (eating_animation_frame_counter == 2) {
			draw_image_noscale(food_coords, PIZZA_WIDTH, PIZZA_HEIGHT, start_food_animation ? pizzaMatrix : donutMatrix);
		} else if (eating_animation_frame_counter == 4) {
			food_coords.y += 3;
			food_coords.x -= 5;
			draw_rect(food_coords, 15, 24, 1, White, &bgColor);
		}
		eating_animation_frame_counter++;
	}
	if (done) {
		_Bool have_to_redraw = 1;
		if (start_food_animation) {
			full_bars_sat++;
			if (full_bars_sat > tot_bars) {
				full_bars_sat = tot_bars;
				have_to_redraw = 0;
			}
		} else if (start_snack_animation) {
			full_bars_happ++;
			if (full_bars_happ > tot_bars) {
				full_bars_happ = tot_bars;
				have_to_redraw = 0;
			}
		}
		if (have_to_redraw) {
			if (start_food_animation) {
				draw_single_bar(full_bars_sat - 1, 1, 1);
			} else {
				draw_single_bar(full_bars_happ - 1, 0, 1); 
			}
		}
		start_food_animation = 0;
		start_snack_animation = 0;
		player_state = Idle;
		eating_animation_frame_counter = 0;
		enable_RIT();
	}
}

void draw_cuddling_animation(uint32_t animation_counter) {
	const int8_t FRAME_TICKS = 8;
	const int32_t total_anim_frames = 5;
	// duration = 50 ms * 8 * 5 = 2000 ms -> 2 seconds
	_Bool done = 0;
	
	Coords center = {0, 0};
	if (animation_counter % FRAME_TICKS == 0) {
		center_rect_in_rect(&center, LCD_WIDTH / PX_RT, LCD_HEIGHT / PX_RT, IDLE_WIDTH, IDLE_HEIGHT);
		if (cuddling_animation_frame_counter == 0) {
			draw_image(center, TOUCHED1_WIDTH, TOUCHED1_HEIGHT, touched1Matrix);
		} else if (cuddling_animation_frame_counter & 1) {
			draw_image(center, TOUCHED2_WIDTH, TOUCHED2_HEIGHT, touched2Matrix);
		} else {
			draw_image(center, TOUCHED3_WIDTH, TOUCHED3_HEIGHT, touched3Matrix);
		}
		++cuddling_animation_frame_counter;
		if (cuddling_animation_frame_counter == total_anim_frames) {
			done = 1;
		}
	}
	if (done) {
		full_bars_happ++;
		if (full_bars_happ > tot_bars) {
			full_bars_happ = tot_bars;
		} else {
			draw_single_bar(full_bars_happ - 1, 0, 1); 
		}
		player_state = Idle;
		cuddling_animation_frame_counter = 0;
		enable_RIT();
	}
}

void handle_joystick_input() {
	static SelectedButton previous_value = ButtonNone;
	Coords origin = {0, LCD_HEIGHT - 60 - 1};
	if (previous_value != selected) {
		switch (selected) {
			case ButtonMeal:
				origin.x = 120;
				draw_rect(origin, 120, 60, 2, Black, NULL); 
				origin.x = 0;
				draw_rect(origin, 120, 60, 2, Red, NULL); 
			  break;
			case ButtonSnack:
				draw_rect(origin, 120, 60, 2, Black, NULL); 
				origin.x += 120;
				draw_rect(origin, 120, 60, 2, Red, NULL); 
				break;
			case ButtonNone:
			default:
				break;
		}
		previous_value = selected;
	}
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
	if (!drawing) {
		switch (player_state) {
			case Idle:
				if (start_food_animation || start_snack_animation) {
					player_state = Eating;
				}
				generic_animation_counter = 0;
				handle_joystick_input();
				break;
			case Eating:
				draw_eating_animation(generic_animation_counter++);
				break;
			case Running:
				draw_running_animation(generic_animation_counter++);
				break;
			case Stopped:
				break;
			case Cuddling:
				draw_cuddling_animation(generic_animation_counter++);
				break;
			default:
				break;
		}
	}
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

const Sound sounds[5] = {
	{0, 0, {{N_None, L_4}}},		// silence
	{3, 120, {{N_Fa, L_16}, {N_None, L_32}, {N_Do, L_16}}},		// click
	{14, 100, {{N_B, L_16}, {N_None, L_64}, {N_F, L_32}, {N_None, L_64}, {N_None, L_16}, {N_F, L_16}, {N_F, L_8}, {N_E, L_8}, {N_D, L_8}, {N_C, L_16}, {N_E, L_16}, {N_G, L_16}, {N_E, L_16}, {N_C, L_4}}},		// running
	{11, 180, {{N_E, L_8}, {N_E, L_8}, {N_None, L_8}, {N_E, L_8}, {N_None, L_8}, {N_C, L_8}, {N_E, L_4}, {N_G, L_4}, {N_None, L_4}, {N_G, L_4}, {N_None, L_4}}},		// eating
	{11, 200, {{N_D, L_16}, {N_G, L_16}, {N_B, L_16}, {N_None, L_8}, {N_E, L_16}, {N_A, L_16}, {N_C, L_16}, {N_None, L_8}, {N_F, L_16}, {N_B, L_16}, {N_D, L_16}}}
};

void TIMER2_IRQHandler (void)
{
	if (play_sound(&sounds[current_sound])) {
		current_sound = S_None;
	}
	LPC_TIM2->IR = 1;
  return;
}

/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/



void TIMER3_IRQHandler (void)
{
	next_sound_tick();
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
