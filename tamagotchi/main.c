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
#include "timer/timer.h"
#include <stdlib.h>
#define SIMULATOR 1

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
const float anim_timer = 100 ms;		// 100 ms == 1 second in emulator
#else
const float anim_timer = 1000 ms;
#endif

int main(void)
{
	Coords origin = {0, 0};
	Coords text_origin = {0, 0};
	const char mealTxt[] = "Meal";
	const char snackTxt[] = "Snack";
	const char happTxt[] = "Happiness";
	const char satTxt[] = "Satiety";
	const uint16_t bgColor = 0xfa83;					// orange
	
  SystemInit();  												/* System Initialization (i.e., PLL)  */
  LCD_Initialization();
	
	LCD_Clear(White);
	
	init_RIT(anim_timer, 1);
	init_timer(Timer0, 50 ms, SCALE(1), 3);
	init_timer(Timer1, 50 ms, SCALE(1), 2);
	joystick_init();
	

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
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);	

  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
