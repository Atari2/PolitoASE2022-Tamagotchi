																			 /*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_joystick, funct_joystick .c files
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#define JOYSTICK_SELECT (LPC_GPIO1->FIOPIN & (1<<25)) == 0
#define JOYSTICK_LEFT (LPC_GPIO1->FIOPIN & (1<<27)) == 0
#define JOYSTICK_RIGHT (LPC_GPIO1->FIOPIN & (1<<28)) == 0

/* lib_joystick */
void joystick_init(void);
