/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           RIT.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_RIT, funct_RIT, IRQ_RIT .c files
** Correlated files:    lib_RIT.c, funct_RIT.c, IRQ_RIT.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#ifndef __RIT_H
#define __RIT_H
#include <stdint.h>
/* init_RIT.c */
#define ms *1.0f
enum {
	ButtonNone = 0,
	ButtonMeal = 1,
	ButtonSnack = 2
} typedef SelectedButton;
extern int init_RIT(float millis, uint32_t priority);
extern void enable_RIT( void );
extern void disable_RIT( void );
extern void reset_RIT( void );
extern void set_rit_frequency(uint32_t frequency);
extern void reset_global_rit_state(void);
/* IRQ_RIT.c */
extern void RIT_IRQHandler (void);

#endif /* end __RIT_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
