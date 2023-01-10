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
#include "../timer/timer.h"
#include "../TouchPanel/TouchPanel.h"
#include "../drawing/drawing.h"
#include "../images/imagedata.h"
#include "../GLCD/GLCD.h"
#include "../adc/adc.h"
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
Coords player_coords = {0, 0};

volatile SelectedButton selected = ButtonNone;

void reset_global_rit_state(void) {
	selected = ButtonNone;
}

_Bool in_image_bounds() {
	_Bool horz_bound = display.x > player_coords.x && display.x < player_coords.x + IDLE_WIDTH*PX_RT;
	_Bool vert_bound = display.y > player_coords.y && display.y < player_coords.y + IDLE_HEIGHT*PX_RT;
	return horz_bound && vert_bound;
}

void RIT_IRQHandler (void)
{
	// Food selection during eating is disabled.
	if (start_food_animation || start_snack_animation) {
		reset_RIT();
		LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
		return;
	}

	if (poll_joystick(JoySelect)) {
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
	} else if (poll_joystick(JoyLeft) && player_state == Idle && selected != ButtonMeal) {
		selected = ButtonMeal;
	} else if (poll_joystick(JoyRight) && player_state == Idle && selected != ButtonSnack) {
		selected = ButtonSnack;
	}
	if (player_state == Idle) {
		if (getDisplayPoint(&display, Read_Ads7846(), &matrix)) {
			if (in_image_bounds()) {
				player_state = Cuddling;
			}
		}
	}
	ADC_start_conversion();
	
	reset_RIT();
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
}

/******************************************************************************
**                            End Of File
******************************************************************************/
