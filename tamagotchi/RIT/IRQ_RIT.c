/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../joystick/joystick.h"
#include "../drawing/drawing.h"
#include "../GLCD/GLCD.h"
#include <stdlib.h>
/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

extern volatile _Bool start_food_animation;
extern volatile _Bool start_snack_animation;

void RIT_IRQHandler (void)
{			
	static uint8_t selected = 0;		// 0: nothing selected, 1: meal, 2 snack
	Coords origin = {0, 0};
	origin.x = 0;
	origin.y =	LCD_HEIGHT - 60 - 1;
	
	// Food selection during eating is disabled.
	if (start_food_animation || start_snack_animation)
		return;

	if (JOYSTICK_SELECT) {
		switch (selected) {
			case 0:
				// select was pressed but nothing was selected
				break;
			case 1:
				start_food_animation = 1;
			  disable_RIT();
				break;
			case 2:
			  start_snack_animation = 1;
			  disable_RIT();
				break;
			default:
				// how did we even end up here?
				break;
		}
	} else if (JOYSTICK_LEFT) {
		draw_rect(origin, 120, 60, 2, Red, NULL); 
		origin.x += 120;
		draw_rect(origin, 120, 60, 2, Black, NULL); 
		selected = 1;
	} else if (JOYSTICK_RIGHT) {
		draw_rect(origin, 120, 60, 2, Black, NULL); 
		origin.x += 120;
		draw_rect(origin, 120, 60, 2, Red, NULL); 
		selected = 2;
	}
	
	reset_RIT();
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
}

/******************************************************************************
**                            End Of File
******************************************************************************/
