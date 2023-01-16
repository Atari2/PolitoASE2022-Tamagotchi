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
#include "../images/imagedata.h"
#include "../drawing/drawing.h"
#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------
  A/D IRQ: Executed when A/D Conversion is ready (signal from ADC peripheral)
 *----------------------------------------------------------------------------*/

unsigned short AD_current;   
unsigned short AD_last = 0xFF;     /* Last converted value               */
int32_t volume = 0;

void ADC_IRQHandler(void) {
  AD_current = ((LPC_ADC->ADGDR>>4) & 0xFFF);/* Read Conversion Result             */
  if(AD_current != AD_last){
		int32_t new_volume = AD_current * 100 / 0xFFF;
		if (abs(new_volume - volume) <= 1) {
			AD_last = AD_current;
			return;
		}
		volume = new_volume;
		Coords draw_coords = {5, 5};
		set_scale(2);
		const int max_vol = 100;
		const int min_vol = 0;
		const int one_third_vol = max_vol / 3;
		const int two_thirds_vol = max_vol / 3 * 2;
		if (volume == min_vol) {
			// 0%
			draw_image(draw_coords, MUTE_WIDTH, MUTE_HEIGHT, muteMatrix);
		} else if (volume < one_third_vol) {
			// 1% - 33%
			draw_image(draw_coords, VOLUME1_WIDTH, VOLUME1_HEIGHT, volume1Matrix);
		} else if (volume < two_thirds_vol) {
			// 34% - 66%
			draw_image(draw_coords, VOLUME2_WIDTH, VOLUME2_HEIGHT, volume2Matrix);
		} else {
			// 67% - 100%
			draw_image(draw_coords, VOLUME3_WIDTH, VOLUME3_HEIGHT, volume3Matrix);
		}
		reset_scale();
		AD_last = AD_current;
  }	
}
