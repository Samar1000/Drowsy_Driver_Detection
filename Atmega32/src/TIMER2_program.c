/*
 * TIMER0_program.c
 *
 *  Created on: Aug 18, 2022
 *      Author: abdelrahmanhossam
 */

#include "../include/MCAL/TIMER2/TIMER2_configuration.h"
#include "../include/MCAL/TIMER2/TIMER2_interface.h"
#include "../include/MCAL/TIMER2/TIMER2_private.h"
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#define NULL 0

void (*TIMER2_OVF_CallBack)(void)= NULL;

void timer2_init(void)
{
	/* Disable Timer 0 */
	TCCR2 = DISABLE_MODULE_VALUE;
	/* Setting pre scaler */
	TCCR2 = (PRESCLR1_VALUE);
	/* Initializing the timer with zero */
	TCNT2 = ZER0_INITIALIZER;
	/* Timer overflow interrupt enable*/
	SET_BIT(TIMSK,6);
	CLR_BIT(TIMSK,7);
}




void MTIMER2_voidsetCallBackOVF (void (*ptrToFunc) (void))
{
	if (ptrToFunc!=NULL)
	{
		TIMER2_OVF_CallBack=ptrToFunc;
	}
}


void __vector_5(void)  __attribute__((signal));
void __vector_5(void)
{
	if (TIMER2_OVF_CallBack!= NULL)
	{
		TIMER2_OVF_CallBack();
	}
}
