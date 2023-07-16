/*
 * sensor_interface.h
 *
 *  Created on: Mar 2, 2023
 *      Author: hp
 */

#ifndef INCLUDE_HAL_SENSOR_SENSOR_INTERFACE_H_
#define INCLUDE_HAL_SENSOR_SENSOR_INTERFACE_H_

void ultrasonic_init(void);
void enable_ex_interrupt(void);
void ultrasonic_triger(void);
void ISR_CallBack (void);
u32 ISR_INT1 (void);
void ISR_TIMER2CallBack(void);
void ISR_TIMER2_OVF(void);

#endif /* INCLUDE_HAL_SENSOR_SENSOR_INTERFACE_H_ */
