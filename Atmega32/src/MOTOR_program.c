/*
 * MOTOR.c
 *
 *  Created on: Feb 22, 2023
 *      Author: hp
 */
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/TIMER0/TIMER0_interface.h"
#include "../Include/HAL/MOTOR/MOTOR_interface.h"
#include "../Include/HAL/MOTOR/MOTOR_private.h"
#include "../Include/HAL/MOTOR/MOTOR_configration.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include <util/delay.h>




void HMotor_voidSpeed(u8 A_u8Value)
{
	 MTIMER0_voidSetOCR0Value( A_u8Value);
}

void HMotor_voidDirection(u8 A_u8Dir)
{
	switch (A_u8Dir)
		{
		case FORWARD:	//MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI1, DIO_LOW);
						//MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI1, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI1, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI1, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_CLK_DRI1, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_ACLK_DRI1, DIO_LOW);

						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI2, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI2, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_CLK_DRI2, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_ACLK_DRI2, DIO_LOW);
		break;

		case BACKWARD: 	MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI1, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI1, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_CLK_DRI1, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_ACLK_DRI1, DIO_HIGH);

						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI2, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI2, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_CLK_DRI2, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_ACLK_DRI2, DIO_HIGH);
		break;

		case RIGHT:
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI1, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI1, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_CLK_DRI1, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_ACLK_DRI1, DIO_HIGH);


						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI2, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI2, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_CLK_DRI2, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_ACLK_DRI2, DIO_LOW);
		break;

		case LEFT:

						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI1, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI1, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_CLK_DRI1, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_ACLK_DRI1, DIO_LOW);

						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_CLK_DRI2, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR1_ACLK_DRI2, DIO_HIGH);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_CLK_DRI2, DIO_LOW);
						MDIO_voidSetPinValue (DIO_PORTA, MOTOR2_ACLK_DRI2, DIO_HIGH);
		break;
		}
}

void HMotor_voidStop(void)
{
	MDIO_voidSetPortValue (DIO_PORTA,DIO_LOW);
}

void HMotor_voidParkVehicle(void){

	HMotor_voidDirection(BACKWARD);
	_delay_ms(3000);
	HMotor_voidDirection(RIGHT);
	_delay_ms(400);
	HMotor_voidDirection(FORWARD);
	_delay_ms(1000);
	HMotor_voidDirection(LEFT);
	_delay_ms(400);
	HMotor_voidStop();
}
