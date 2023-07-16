/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_


#define EXTI0	0
#define EXTI1	1
#define EXTI2	2

#define LOW_LEVEL    0
#define ON_CHANGE    1
#define FALLING_EDGE 2
#define RISING_EDGE  3



void MEXTI_voidConfig (u8 A_u8EXTI, u8 A_u8SenseMode);
void MEXTI_voidEnable(u8 A_u8EXTI);
void MEXTI_voidDisable(u8 A_u8EXTI);
void MEXTI_voidClearFlag (u8 A_u8EXTI);
void MEXTI_voidSetCallBack (u8 A_u8EXTI, void(*ptrToFunc)(void));






#endif /* INCLUDE_MCAL_EXTI_EXTI_INTERFACE_H_ */
