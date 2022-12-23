/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        Atomic joystick init functions
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "joystick.h"

/*----------------------------------------------------------------------------
  Function that initializes joysticks and switch them off
 *----------------------------------------------------------------------------*/

void joystick_init(void) {
	/* joystick Select functionality */
	
	const uint32_t joystick_functionality = (3 << 18) | (3 << 22) | (3 << 24);
	const uint32_t joystick_fiodir = (1 << 25) | (1 << 27) | (1 << 28);
	
  LPC_PINCON->PINSEL3 &= ~joystick_functionality;	//PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR   &= ~joystick_fiodir;	//P1.25 Input (joysticks on PORT1 defined as Input) 
}
