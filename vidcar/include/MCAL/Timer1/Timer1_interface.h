/*
 * Timer1_interface.h
 *
 *  Created on: Oct 7, 2022
 *      Author: hp
 */

#ifndef INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_
#define INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_


#define FALLING_EDGE 2
#define RISING_EDGE  3

void MTIMER1_voidInit(void);
void MTIMER1_voidSetOCR1AValue(u8 A_u8Value);
void MTIMER1_voidSetTCNT1Value(u16 A_u16Value);
u16 MTIMER1_voidReadTCNT1Value(void);
void ICU_Callback(void(*ptr_fun)(void));
void ICU_Init(void);
void ICU_Trigger(u8 A_u8Mode);
u16 MTIMER1_voidReadICUValue(void);
void ICU_DisEnable(void);

//my funs
void MTIMER1_voidSetTccr1aValue(u8 A_u8Value);
void MTIMER1_voidClearIcpFlag(void);
void ICU_Rising(void);
void ICU_Falling(void);
void MTIMER1_voidSetTccr1bValue(u8 A_u8Value);
u8 MTIMER1_u8GetPin5Value(void);
#endif /* INCLUDE_MCAL_TIMER1_TIMER1_INTERFACE_H_ */
