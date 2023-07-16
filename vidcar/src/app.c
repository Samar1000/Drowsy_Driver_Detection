/*
 * app.c
 *
 *  Created on: Feb 22, 2023
 *      Author: hp
 */
#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "HAL/LED/LED_interface.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/MOTOR/MOTOR_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "MCAL/UART/UART_Interface.h"
#include "MCAL/TIMER2/TIMER2_interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GI/GI_interface.h"
#include "HAL/sensor/sensor_interface.h"
#include "HAL/sensor/sensor_configration.h"
//#include<string.h>
//#include <stdlib.h>
#define F_CPU 8000000UL

extern u32 distance;

int main (void)
{

	u8 local_u8Read=225;
//	u8 local_u8Read1=225;
	MDIO_voidInit();
	UART_voidInit();
	MTIMER0_voidInit();
	ultrasonic_init();
	ISR_CallBack();
	ISR_TIMER2CallBack();
	MGI_voidEnable();

	while (1) // Super-Loop
	{

		ultra_triger();
		_delay_ms(15);

//		local_u8Read = UART_u8READByteSynchNonBlocking();
//
//		if (local_u8Read == 's' || local_u8Read == 'S'){
//			_delay_ms(3500);
//			HMotor_voidSpeed(55);
//			HMotor_voidDirection(FORWARD);

			local_u8Read = UART_u8READByteSynchNonBlocking();

			if (local_u8Read == 'a' || local_u8Read == 'A'){
				ultra_triger();
				_delay_ms(15);
				HMotor_voidSpeed(85);
				HLED_voidToggleLed(DIO_PORTB,PIN0); //red led
				MDIO_voidSetPinValue(DIO_PORTB,PIN5,DIO_HIGH);//buzzer
				 if(distance>20 && distance <= 40){//green
					HLED_voidToggleLed(DIO_PORTB,PIN1);
					HMotor_voidDirection(RIGHT);
					_delay_ms(115);
					HMotor_voidDirection(FORWARD);
					_delay_ms(110);
					HMotor_voidDirection(LEFT);
					_delay_ms(120);
					HMotor_voidDirection(FORWARD);
					_delay_ms(100);
					HMotor_voidStop();
				}
				else if((distance > 40)){//yellow
					HLED_voidToggleLed(DIO_PORTB,PIN2);
					HMotor_voidDirection(RIGHT);
					_delay_ms(110);
					HMotor_voidDirection(FORWARD);
					_delay_ms(100);
					HMotor_voidDirection(LEFT);
					_delay_ms(120);
					HMotor_voidDirection(FORWARD);
					_delay_ms(150);
                    HMotor_voidDirection(RIGHT);
					_delay_ms(110);
					HMotor_voidDirection(FORWARD);
					_delay_ms(100);
					HMotor_voidDirection(LEFT);
					_delay_ms(120);
					HMotor_voidDirection(FORWARD);
					_delay_ms(100);
					HMotor_voidStop();
				}
			}
		}
}
