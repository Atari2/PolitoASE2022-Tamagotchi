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

volatile int8_t seconds = -1; // starts from second -1 to simulate second 0
volatile int8_t minutes = 0;
volatile int8_t hours = 0;
static const uint8_t tot_bars = 8;
volatile uint8_t full_bars = tot_bars + 1;
volatile _Bool start_food_animation = 0;
volatile _Bool start_snack_animation = 0;

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

void handle_eating_animations() {
	if (start_food_animation) {
		GUI_Text(10, 190, (uint8_t*)foodTxt, Black, White);
	} else if (start_snack_animation) {
		GUI_Text(10, 190, (uint8_t*)snackTxt, Black, White);
	}
	// TODO: do the whole animation
	start_food_animation = 0;
	start_snack_animation = 0;
	enable_RIT();
}

const char deathTxt[] = "DEATH!";

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
	static _Bool already_on_screen = 0;
	// each frame is 1 second, uint32_t should be enough for ~136 years
	static uint32_t frame_counter = 0;
	advance_time();
	if ((seconds % 5) == 0) {
		draw_batteries(tot_bars, --full_bars);		
		if (full_bars == 0) {
			// TODO: death
			// for now we just loop
			GUI_Text(100, 100, (uint8_t*)deathTxt, Black, White);
			while (1) {}
		}
	}
	if ((seconds & 1) == 0) {
		draw_image_diff(MARIO1_WIDTH, MARIO1_HEIGHT, already_on_screen ? PASS_TO_DRAWING(mario2Matrix) : NULL, PASS_TO_DRAWING(mario1Matrix));
	} else {
		draw_image_diff(MARIO2_WIDTH, MARIO2_HEIGHT, PASS_TO_DRAWING(mario1Matrix), PASS_TO_DRAWING(mario2Matrix));
	}
	if (start_food_animation || start_snack_animation) {
		handle_eating_animations();
	}
	already_on_screen = 1;
	++frame_counter;
  LPC_TIM0->IR = 1;			/* clear interrupt flag */
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
void TIMER1_IRQHandler (void)
{	
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
