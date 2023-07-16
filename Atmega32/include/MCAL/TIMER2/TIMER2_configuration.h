/*
 * TIMER0_configuration.h
 *
 *  Created on: Aug 18, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_TIMER2_TIMER2_CONFIGURATION_H_
#define INCLUDE_MCAL_TIMER2_TIMER2_CONFIGURATION_H_



#define DISABLE_MODULE_VALUE 		      0x00
#define ZER0_INITIALIZER                0x00
/*
 * 0b000  No clock source (Timer/Counter stopped).
 * 0b001  clkI/O /(No prescaling)
 * 0b010  clkI/O /8 (From prescaler)
 * 0b011  clkI/O /64 (From prescaler)
 * 0b100  clkI/O /256 (From prescaler)
 * 0b101  clkI/O /1024 (From prescaler)
 * 0b110  External clock source on T0 pin. Clock on falling edge.
 * 0b111  External clock source on T0 pin. Clock on rising edge.
 * */
#define PRESCLR1_VALUE 		            0x01


#endif /* INCLUDE_MCAL_TIMER2_TIMER2_CONFIGURATION_H_ */
