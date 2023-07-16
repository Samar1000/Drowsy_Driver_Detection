/*
 * Timer1_program.c
 *
 *  Created on: Oct 7, 2022
 *      Author: hp
 */

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/Timer1/Timer1_interface.h"
#include "../Include/MCAL/Timer1/Timer1_private.h"
#include "../Include/MCAL/Timer1/Timer1_configration.h"
#define NULL 0

void (*Callback_ICU_fun) (void) = NULL;

void MTIMER1_voidInit(void){
	/*//mode -->14
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	//non-inverting
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);

	ICR1 =19999;
	OCR1A=1500;*/
    //prescalar
	/*CLR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,0);*/

	//no pre
	CLR_BIT(TCCR1B,2);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,0);



}

void MTIMER1_voidSetOCR1AValue(u8 A_u8Value)
{
	OCR1A=A_u8Value;
}

void MTIMER1_voidSetTCNT1Value(u16 A_u16Value){
	TCNT1 = A_u16Value;
}

u16 MTIMER1_voidReadTCNT1Value(void){
	return TCNT1;
}


void ICU_Init(void){
	SET_BIT(TCCR1B ,6);
	SET_BIT(TIMSK ,5);
}
void ICU_DisEnable(void){
	CLR_BIT(TIMSK ,5);
}
/*ICES1 --> selects triggered edge
SET_BIT(TCCR1B ,6); //rising
CLR_BIT(TCCR1B ,6); //falling

//enable interrupt of input capture
SET_BIT(TIMSK ,5);*/

//new functions i added

void MTIMER1_voidSetTccr1aValue(u8 A_u8Value)
{
	TCCR1A=A_u8Value;
}

void MTIMER1_voidSetTccr1bValue(u8 A_u8Value)
{
	TCCR1B=A_u8Value;
}

/* Clear ICF (Input Capture flag)  */

void MTIMER1_voidClearIcpFlag(void){
	SET_BIT(TIFR,5);
}

void ICU_Rising(void){
	SET_BIT(TCCR1B ,6);
}

void ICU_Falling(void){
	CLR_BIT(TCCR1B ,6);
}

u8 MTIMER1_u8GetPin5Value(void)
{
	u8 local_u8PinValue=255;
    local_u8PinValue = GET_BIT(TIFR,5);
	return local_u8PinValue;
}

//end of my funs

void ICU_Callback(void(*ptr_fun)(void)){
	if(ptr_fun != NULL){
	Callback_ICU_fun =*ptr_fun;
	}
}

void ICU_Trigger(u8 A_u8Mode){
	switch(A_u8Mode){
	case  RISING_EDGE : SET_BIT(TCCR1B ,6); break;
	case FALLING_EDGE : CLR_BIT(TCCR1B ,6); break;
	}
}
u16 MTIMER1_voidReadICUValue(void){
	return ICR1;
}
void __vector_6(void) __attribute__((signal));
void __vector_6(void){
	if(Callback_ICU_fun != NULL){
		Callback_ICU_fun();
	}
}



void HSERVO_voidSetAngle(u8 A_u8Angle){
	u16 local_u16OCRValue = ((A_u8Angle*1000UL)/100)+ 999;
	MTIMER1_voidSetOCR1AValue(local_u16OCRValue);

}
