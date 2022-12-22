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
#include "timer/timer.h"
#include <stdlib.h>
#define SIMULATOR 1

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
const float anim_timer = 100 ms;
#else
const float anim_timer = 1000 ms;
#endif

int main(void)
{
	Coords origin = {0, LCD_HEIGHT - 60 - 1};
	Coords text_origin = {0, 0};
	const char mealTxt[] = "Meal";
	const char snackTxt[] = "Snack";
	const uint16_t bgColor = 0xfa83;					// dark orange
	const uint16_t borderColor = 0xf963; // orange
	
  SystemInit();  												/* System Initialization (i.e., PLL)  */
  LCD_Initialization();
	
	LCD_Clear(White);
	
	init_timer(Timer0, anim_timer, SCALE(1), 3); 						    /* 8us * 25MHz = 200 ~= 0xC8 */
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);	

	// draw boxes
	draw_rect(origin, 120, 60, 2, borderColor, &bgColor); 
	origin.x += 120;
	draw_rect(origin, 120, 60, 2, borderColor, &bgColor); 
	
	// draw text
	text_origin.x = 0;
	text_origin.y = LCD_HEIGHT - 60 - 1;
	center_text_in_rect(&text_origin, 120, 60, sizeof(mealTxt) - 1);
	draw_text(text_origin.x, text_origin.y, mealTxt, Black);
	
	text_origin.x = 120;
	text_origin.y = LCD_HEIGHT - 60 - 1;
	center_text_in_rect(&text_origin, 120, 60, sizeof(snackTxt) - 1);
	draw_text(text_origin.x, text_origin.y, snackTxt, Black);
	
	// start animation
	enable_timer(Timer0);
  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
