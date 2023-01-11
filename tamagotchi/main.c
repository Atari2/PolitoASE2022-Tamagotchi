/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The GLCD application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             Paolo Bernardi
** Modified date:           03/01/2020
** Version:                 v2.0
** Descriptions:            basic program for LCD and Touch Panel teaching
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "GLCD/GLCD.h"
#include "drawing/drawing.h"
#include "RIT/RIT.h"
#include "joystick/joystick.h"
#include "TouchPanel/TouchPanel.h"
#include "adc/adc.h"
#include "timer/timer.h"
#include <stdlib.h>

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

volatile _Bool reset_clicked = 0;

void start_game() {
	Coords origin = {0, 0};
	Coords text_origin = {0, 0};
	const char mealTxt[] = "Meal";
	const char snackTxt[] = "Snack";
	const char happTxt[] = "Happiness";
	const char satTxt[] = "Satiety";
	const uint16_t bgColor = RGB565CONVERT(0xFF, 0xA5, 0x00);					// orange
	LCD_Clear(White);

	// draw top
	text_origin.x = 0;
	text_origin.y = 30;
	center_text_in_rect(&text_origin, 120, 40, sizeof(happTxt) - 1, 1);
	draw_text(text_origin.x, text_origin.y, happTxt, Black, 1);
	
	text_origin.x = 120;
	text_origin.y = 30;
	center_text_in_rect(&text_origin, 120, 40, sizeof(satTxt) - 1, 1);
	draw_text(text_origin.x, text_origin.y, satTxt, Black, 1);
	
	// draw boxes
	origin.x = 0;
	origin.y =	LCD_HEIGHT - 60 - 1;
	draw_rect(origin, 120, 60, 2, Black, &bgColor); 
	origin.x += 120;
	draw_rect(origin, 120, 60, 2, Black, &bgColor); 
	
	// draw text
	text_origin.x = 0;
	text_origin.y = LCD_HEIGHT - 60 - 1;
	center_text_in_rect(&text_origin, 120, 60, sizeof(mealTxt) - 1, 2);
	draw_text(text_origin.x, text_origin.y, mealTxt, Black, 2);
	
	text_origin.x = 120;
	text_origin.y = LCD_HEIGHT - 60 - 1;
	center_text_in_rect(&text_origin, 120, 60, sizeof(snackTxt) - 1, 2);
	draw_text(text_origin.x, text_origin.y, snackTxt, Black, 2);
	
	// start animation
	enable_RIT();
	enable_timer(Timer0);
	enable_timer(Timer1);
}

int main(void)
{	
	float anim_timer = 1000 ms;
	float frame_timer = 50 ms;
  SystemInit();  												/* System Initialization (i.e., PLL)  */
  LCD_Initialization();
	TP_Init();
	ADC_init();
	// SetSpeaker(1);
	#ifndef SIMULATOR	// this is too slow to do every time
	TouchPanel_Calibrate();
	#endif
	init_RIT(frame_timer, 1);
	init_timer(Timer0, anim_timer, SCALE(1), 2);
	init_timer(Timer1, frame_timer, SCALE(1), 3);
	joystick_init(JoySelect | JoyLeft | JoyRight);
	reset_clicked = 1;
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);	

  while (1)	
  {
		if (reset_clicked) {
			start_game();
			reset_global_timer_state();
			reset_global_rit_state();
			reset_clicked = 0;
		}
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
