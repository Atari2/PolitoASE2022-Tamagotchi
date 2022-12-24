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
#include <stdlib.h>
#include <stdio.h>

extern volatile _Bool drawing;

static const uint8_t tot_bars = 8;

volatile int8_t seconds = -1; // starts from second -1 to simulate second 0
volatile int8_t minutes = 0;
volatile int8_t hours = 0;
volatile uint8_t full_bars_happ = tot_bars + 1;
volatile uint8_t full_bars_sat = tot_bars + 1;
volatile _Bool start_food_animation = 0;
volatile _Bool start_snack_animation = 0;
volatile enum PlayerState player_state = Idle;
static int32_t running_animation_frame_counter = 0;
static int32_t eating_animation_frame_counter = 0;
static _Bool already_on_screen = 0;
static uint32_t generic_animation_counter = 0;

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
	already_on_screen = 0;
	generic_animation_counter = 0;
}

void format_time(char buf[14]) {
	snprintf(buf, 14, "Age: %02d:%02d:%02d", hours, minutes, seconds);
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
	GUI_Text(text_origin.x, text_origin.y, (uint8_t*)tmp, Black, White);
}

const char foodTxt[] = "FOOD!";
const char snackTxt[] = "SNACK!";
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
		draw_batteries(tot_bars, --full_bars_happ, --full_bars_sat);		
		if (full_bars_happ == 0 || full_bars_sat == 0) {
			// bars empty, tamagotchi starts running
			player_state = Running;
			disable_RIT();
			disable_timer(Timer0); 	// disable self
			LPC_TIM0->IR = 1;			// clear interrupt flag and return early
			return;
		}
	}
	center_rect_in_rect(&center, LCD_WIDTH / PX_RT, LCD_HEIGHT / PX_RT, IDLE_WIDTH, IDLE_HEIGHT);
	if ((seconds & 1) == 0) {
		draw_image_diff(center, IDLE_WIDTH, IDLE_HEIGHT, already_on_screen ? PASS_TO_DRAWING(idle_2Matrix) : NULL, PASS_TO_DRAWING(idleMatrix));
	} else {
		draw_image_diff(center, IDLE_2_WIDTH, IDLE_2_HEIGHT, PASS_TO_DRAWING(idleMatrix), PASS_TO_DRAWING(idle_2Matrix));
	}
	already_on_screen = 1;
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
  return;
}

void draw_running_animation(uint32_t animation_counter) {
	const uint32_t counter_tick = 500 / 100;
	const int32_t disl = 8 * PX_RT;
	const uint16_t bgColor = White;
	const uint16_t boxBgColor = 0xfa83;
	uint16_t width = RUNNING1_WIDTH;
	uint16_t real_width = width * PX_RT;
	uint16_t height = RUNNING1_HEIGHT;
	div_t res = div(animation_counter, counter_tick);
	const char stoppedTxt[] = "Mario ran away :(";
	const char resetTxt[] = "Reset";
	Coords center = {0, 0};
	
	if (res.rem == 0) {
		// every 10 ticks of frame counter, we do a frame of animation
		center_rect_in_rect(&center, (LCD_WIDTH - (running_animation_frame_counter * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
		switch (running_animation_frame_counter) {
			case 0:
			case 2:
				draw_image(center, width, height, PASS_TO_DRAWING(running1Matrix));
				break;
			case 1:
			case 3:
				draw_image(center, width, height, PASS_TO_DRAWING(running2Matrix));
				break;
			default:
				if ((running_animation_frame_counter & 1) == 0) {
					draw_image(center, width, height, PASS_TO_DRAWING(running6Matrix));
				} else {
					draw_image(center, width, height, PASS_TO_DRAWING(running5Matrix));
				}
				break;
		}

		center.x *= PX_RT;
		center.x += real_width;
		center.y *= PX_RT;
		if (center.x < 0) {
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
			enable_RIT();
			return;
		}
		draw_rect(center, disl, height * PX_RT, 1, White, &bgColor);
		running_animation_frame_counter++;
	}
}

void draw_eating_animation(uint32_t animation_counter) {
	const uint32_t counter_tick = 500 / 100;
	const int32_t disl = 8 * PX_RT;
	const uint16_t bgColor = White;
	uint16_t width = RUNNING1_WIDTH;
	uint16_t real_width = width * PX_RT;
	uint16_t height = RUNNING1_HEIGHT;
	div_t res = div(animation_counter, counter_tick);
	Coords center = {0, 0};
	Coords food_coords = {10, 190};
	_Bool done = 0;
	const uint16_t* food = start_food_animation ? PASS_TO_DRAWING(pizzaMatrix) : PASS_TO_DRAWING(donutMatrix);
	if (eating_animation_frame_counter == 0) {
		draw_image_noscale(food_coords, PIZZA_WIDTH, PIZZA_HEIGHT, food);
	}
	if (res.rem == 0) {
		// every 10 ticks of frame counter, we do a frame of animation
		switch (eating_animation_frame_counter) {
			case 0:
			case 2:
				center_rect_in_rect(&center, (LCD_WIDTH - (eating_animation_frame_counter * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image(center, width, height, PASS_TO_DRAWING(running1Matrix));
				break;
			case 1:
				center_rect_in_rect(&center, (LCD_WIDTH - disl) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image(center, width, height, PASS_TO_DRAWING(running2Matrix));
				break;
			case 3:
				center_rect_in_rect(&center, (LCD_WIDTH - (3 * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image(center, width, height, PASS_TO_DRAWING(crouchedMatrix));
				break;
			case 4:
				center_rect_in_rect(&center, (LCD_WIDTH - (3 * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image(center, width, height, PASS_TO_DRAWING(eatingMatrix));
				break;
			case 7:
			case 5:
				center_rect_in_rect(&center, (LCD_WIDTH - ((7-eating_animation_frame_counter) * disl)) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image_flipped(center, width, height, PASS_TO_DRAWING(running1Matrix));
				break;
			case 6:
				center_rect_in_rect(&center, (LCD_WIDTH - disl) / PX_RT, LCD_HEIGHT / PX_RT, width, height);
				draw_image_flipped(center, width, height, PASS_TO_DRAWING(running2Matrix));
				break;
			default:
				done = 1;
				break;
		}
		if (eating_animation_frame_counter == 2) {
			draw_image_noscale(food_coords, PIZZA_WIDTH, PIZZA_HEIGHT, food);
		} else if (eating_animation_frame_counter == 4) {
			draw_rect(food_coords, 15, 24, 1, White, &bgColor);
		}
		center.y *= PX_RT;
		if (eating_animation_frame_counter > 0 && eating_animation_frame_counter < 4) {
			center.x *= PX_RT;
			center.x += real_width;		
			draw_rect(center, disl, height * PX_RT, 1, White, &bgColor);
		} else if (eating_animation_frame_counter > 4 && eating_animation_frame_counter < 8) {
			center.x *= PX_RT;
			center.x -= disl;
			draw_rect(center, disl, height * PX_RT, 1, White, &bgColor);
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
		if (have_to_redraw)
			draw_batteries(tot_bars, full_bars_happ, full_bars_sat);
		start_food_animation = 0;
		start_snack_animation = 0;
		player_state = Idle;
		eating_animation_frame_counter = 0;
		enable_RIT();
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
				break;
			case Eating:
				draw_eating_animation(generic_animation_counter++);
				break;
			case Running:
				draw_running_animation(generic_animation_counter++);
				break;
			case Stopped:
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
void TIMER2_IRQHandler (void)
{
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
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
