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
#include "../timer/timer.h"
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
extern volatile enum PlayerState player_state; 
extern volatile _Bool reset_clicked;

enum {
	ButtonNone = 0,
	ButtonMeal = 1,
	ButtonSnack = 2
} typedef SelectedButton;

static SelectedButton selected = ButtonNone;

void reset_global_rit_state(void) {
	selected = ButtonNone;
}


void RIT_IRQHandler (void)
{			
	Coords origin = {0, 0};
	origin.x = 0;
	origin.y =	LCD_HEIGHT - 60 - 1;
	
	// Food selection during eating is disabled.
	if (start_food_animation || start_snack_animation)
		return;

	if (JOYSTICK_SELECT) {
		if (player_state == Stopped) {
			// reset was clicked
			reset_clicked = 1;
			disable_RIT();
			disable_timer(Timer0);
			disable_timer(Timer1);
			return;
		}
		switch (selected) {
			case ButtonNone:
				// select was pressed but nothing was selected
				break;
			case ButtonMeal:
				start_food_animation = 1;
			  disable_RIT();
				break;
			case ButtonSnack:
			  start_snack_animation = 1;
			  disable_RIT();
				break;
			default:
				// how did we even end up here?
				break;
		}
	} else if (JOYSTICK_LEFT && player_state == Idle) {
		if (selected != ButtonMeal) {
			draw_rect(origin, 120, 60, 2, Red, NULL); 
			origin.x += 120;
			draw_rect(origin, 120, 60, 2, Black, NULL); 
			selected = ButtonMeal;
		}
	} else if (JOYSTICK_RIGHT && player_state == Idle) {
		if (selected != ButtonSnack) {
			draw_rect(origin, 120, 60, 2, Black, NULL); 
			origin.x += 120;
			draw_rect(origin, 120, 60, 2, Red, NULL); 
			selected = ButtonSnack;
		}
	}
	
	reset_RIT();
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
}

/******************************************************************************
**                            End Of File
******************************************************************************/
