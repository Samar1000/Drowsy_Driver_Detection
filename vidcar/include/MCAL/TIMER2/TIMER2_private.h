/*
 * TIMER0_private.h
 *
 *  Created on: Aug 18, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_


#define TCCR2 (*(volatile u8 *)0x45)
#define TCNT2 (*(volatile u8 *)0x44)
#define OCR2  (*(volatile u8 *)0x43)
#define TIMSK (*(volatile u8 *)0x59)
#define TIFR  (*(volatile u8 *)0x58)



#endif /* INCLUDE_MCAL_TIMER2_TIMER2_PRIVATE_H_ */
