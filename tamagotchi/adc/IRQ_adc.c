/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_adc.c
** Last modified Date:  20184-12-30
** Last Version:        V1.00
** Descriptions:        functions to manage A/D interrupts
** Correlated files:    adc.h
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "adc.h"
#include "../GLCD/GLCD.h"
#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/

unsigned short AD_current;   
unsigned short AD_last = 0xFF;     /* Last converted value               */
int volume = 50;

void ADC_IRQHandler(void) {
  	
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);/* Read Conversion Result             */
  if(AD_current != AD_last){
		uint16_t diff = abs(AD_current - AD_last);
		if (diff < 41) /* 41 == 1% */ {
			return;
		}
		volume = AD_current*100 / 0xFFF;
		char buf[10];
		snprintf(buf, 10, "%3d %%", volume);
		GUI_Text(5, 15, (uint8_t*)buf, Black, White);
		AD_last = AD_current;
  }	
}
