/*
 * MOTOR_interface.h
 *
 *  Created on: Feb 22, 2023
 *      Author: hp
 */

#ifndef INCLUDE_HAL_MOTOR_INTERFACE_H_
#define INCLUDE_HAL_MOTOR_INTERFACE_H_

#define MOTOR1_DRI1  1
#define MOTOR2_DRI1  2
#define MOTOR1_DRI2  3
#define MOTOR2_DRI2  4

#define FORWARD  1
#define BACKWARD 2
#define RIGHT    3
#define LEFT     4

void HMotor_voidSpeed(u8 A_u8Value);
void HMotor_voidDirection(u8 A_u8Dir);
void HMotor_voidStop(void);
void HMotor_voidParkVehicle(void);
#endif /* INCLUDE_HAL_MOTOR_INTERFACE_H_ */
