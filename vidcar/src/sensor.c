/*
 * sensor.c
 *
 *  Created on: Mar 2, 2023
 *      Author: hp
 */
#include <util/delay.h>

#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

#include "../include/MCAL/DIO/DIO_interface.h"
#include "../Include/HAL/MOTOR/MOTOR_interface.h"

#include "../include/MCAL/EXTI/EXTI_Interface.h"
#include "../include/MCAL/TIMER2/TIMER2_interface.h"
#include "../include/MCAL/TIMER2/TIMER2_private.h"

#include "../include/HAL/LED/LED_interface.h"
#include "../include/HAL/sensor/sensor_configration.h"


u8 static sensor_working=0;
u8 static rising_edge=0;
u8 distance_str[10];
u32 static timer_counter=0;
u32 distance;

void ultrasonic_init(void){
	MDIO_voidSetPinDirection (DIO_PORTD, PIN4, DIO_OUTPUT); //change 0->4
	MDIO_voidSetPinDirection (DIO_PORTD, PIN3, DIO_INPUT);
	MDIO_voidSetPinValue (DIO_PORTD, PIN3, DIO_PULLUP);
	enable_ex_interrupt();
	timer2_init();
}


void enable_ex_interrupt(void){
	MEXTI_voidConfig (EXTI1, ON_CHANGE);		// Trigger INT1 on any logic change.
	MEXTI_voidEnable(EXTI1);		           // Enable INT1 interrupts.
}


void ultra_triger(void){
  if(!sensor_working){
	  MDIO_voidSetPinValue (DIO_PORTD, PIN4, DIO_HIGH); //change 0->4
	  _delay_us(15);
	  MDIO_voidSetPinValue (DIO_PORTD, PIN4, DIO_LOW); //change 0->4
	  sensor_working=1;
  }
}



u32 ISR_INT1 (void){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT2=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else{
    distance=(timer_counter*256+TCNT2)/466;
  	_delay_ms(40);
    timer_counter=0;
    rising_edge=0;
  }//try put return
}
  return distance;
}

void ISR_CallBack (void){
 MEXTI_voidSetCallBack(EXTI1, ISR_INT1);
}


void ISR_TIMER2_OVF(void){
    timer_counter++;
    if(timer_counter >730){
      TCNT2=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}


void ISR_TIMER2CallBack(void){
MTIMER2_voidsetCallBackOVF(ISR_TIMER2_OVF);
}


