/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : EXTI DRIVER                      */
/*   DATE        : 23 SEP 2022                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* EXTI Directives								    */
/****************************************************/
#include "../include/MCAL/EXTI/EXTI_Interface.h"
#include "../include/MCAL/EXTI/EXTI_private.h"
#include "../include/MCAL/EXTI/EXTI_configuration.h"

#define NULL 0

void (*EXTI0_CallBack) (void) = NULL;
void (*EXTI1_CallBack) (void) = NULL;
void (*EXTI2_CallBack) (void) = NULL;

void MEXTI_voidConfig (u8 A_u8EXTI, u8 A_u8SenseMode)
{
	if (A_u8SenseMode <= RISING_EDGE)
	{
		switch (A_u8EXTI)
		{
			case EXTI0: MCUCR &= ~(SENSE_MODE_MASK<<EXTI0_SENSE_BIT1);
						MCUCR |= (A_u8SenseMode<<EXTI0_SENSE_BIT1);
						break;
			case EXTI1: MCUCR &= ~(SENSE_MODE_MASK<<EXTI1_SENSE_BIT1);
						MCUCR |= (A_u8SenseMode<<EXTI1_SENSE_BIT1);
						break;
			case EXTI2: switch (A_u8SenseMode)
						{
						case FALLING_EDGE: CLR_BIT(MCUCSR,EXTI2_SENSE_BIT1); break;
						case RISING_EDGE : SET_BIT(MCUCSR,EXTI2_SENSE_BIT1); break;
						}
						break;
		}
	}
}



void MEXTI_voidEnable(u8 A_u8EXTI)
{
	switch (A_u8EXTI)
	{
		case EXTI0: SET_BIT(GICR,EXTI0_ENABLE_BIT);
					break;
		case EXTI1: SET_BIT(GICR,EXTI1_ENABLE_BIT);
					break;
		case EXTI2: SET_BIT(GICR,EXTI2_ENABLE_BIT);
					break;
	}
}

void MEXTI_voidDisable(u8 A_u8EXTI)
{
	switch (A_u8EXTI)
	{
		case EXTI0: CLR_BIT(GICR,EXTI0_ENABLE_BIT);
					break;
		case EXTI1: CLR_BIT(GICR,EXTI1_ENABLE_BIT);
					break;
		case EXTI2: CLR_BIT(GICR,EXTI2_ENABLE_BIT);
					break;
	}
}

void MEXTI_voidClearFlag (u8 A_u8EXTI)
{
	switch (A_u8EXTI)
	{
		case EXTI0: SET_BIT(GIFR,EXTI0_FLAG_BIT);
					break;
		case EXTI1: SET_BIT(GIFR,EXTI1_FLAG_BIT);
					break;
		case EXTI2: SET_BIT(GIFR,EXTI2_FLAG_BIT);
					break;
	}
}

void MEXTI_voidSetCallBack (u8 A_u8EXTI, void(*ptrToFunc)(void))
{
	if (ptrToFunc != NULL)
	{
		switch (A_u8EXTI)
		{
			case EXTI0: EXTI0_CallBack = ptrToFunc;
						break;
			case EXTI1: EXTI1_CallBack = ptrToFunc;
						break;
			case EXTI2: EXTI2_CallBack = ptrToFunc;
						break;
		}
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if (EXTI0_CallBack != NULL)
	{
		EXTI0_CallBack();
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (EXTI1_CallBack != NULL)
	{
		EXTI1_CallBack();
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (EXTI2_CallBack != NULL)
	{
		EXTI2_CallBack();
	}
}
