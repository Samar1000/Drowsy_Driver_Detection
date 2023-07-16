/*
 * TIMER0_interface.h
 *
 *  Created on: Aug 18, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_


void timer2_init(void);



void MTIMER2_voidsetCallBackOVF (void (*ptrToFunc) (void));


#endif /* INCLUDE_MCAL_TIMER2_TIMER2_INTERFACE_H_ */
