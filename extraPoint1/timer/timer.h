/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           timer.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_timer, funct_timer, IRQ_timer .c files
** Correlated files:    lib_timer.c, funct_timer.c, IRQ_timer.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#ifndef __TIMER_H
#define __TIMER_H
#include <stdint.h>
/* init_timer.c */

#define ms *1.0f
#define MHz *1u
#define SCALE(x) (x-1)
#define LAB10

enum TimerNo {
	Timer0 = 0,
	Timer1 = 1,
	Timer2 = 2,
	Timer3 = 3
} typedef TimerNo;

extern int init_timer( TimerNo timer_num, float millis, uint32_t prescale, uint32_t priority);
extern int enable_timer( TimerNo timer_num );
extern int disable_timer( TimerNo timer_num );
extern int reset_timer( TimerNo timer_num );
extern void set_timer_frequency(uint32_t frequency);
/* IRQ_timer.c */
extern void TIMER0_IRQHandler (void);
extern void TIMER1_IRQHandler (void);
extern void TIMER2_IRQHandler (void);
extern void TIMER3_IRQHandler (void);

#endif /* end __TIMER_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/