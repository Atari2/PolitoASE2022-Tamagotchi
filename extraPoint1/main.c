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
#endif

int main(void)
{
	Coords origin = {0, LCD_HEIGHT - 60 - 1};
  SystemInit();  												/* System Initialization (i.e., PLL)  */
  LCD_Initialization();
	
	LCD_Clear(White);
	
	init_timer(Timer0, 100 ms, SCALE(1), 3); 						    /* 8us * 25MHz = 200 ~= 0xC8 */
	
	enable_timer(Timer0);
	LPC_SC->PCON |= 0x1;									/* power-down	mode										*/
	LPC_SC->PCON &= ~(0x2);	

	
	draw_rect(origin, 120, 60, 2, 0xEBC1, NULL); 
	origin.x += 120;
	draw_rect(origin, 120, 60, 2, 0xEBC1, NULL); 
	
  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
