

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"


#include "../Include/HAL/LED/LED_interface.h"
#include "../Include/HAL/LED/LED_private.h"
#include "../Include/HAL/LED/LED_configurations.h"

void HLED_voidTurnOn(u8 A_u8PortID, u8 A_u8PinId)
{
    MDIO_voidSetPinValue(A_u8PortID, A_u8PinId, LED_ON);
}
void HLED_voidTurnOff(u8 A_u8PortID, u8 A_u8PinId)
{
    MDIO_voidSetPinValue(A_u8PortID, A_u8PinId, LED_OFF);
}

// LED_ON - LED_OFF
void HLED_voidSetLedStatus(u8 A_u8PortID, u8 A_u8PinId, u8 A_u8LedStatus)
{
    MDIO_voidSetPinValue(A_u8PortID, A_u8PinId, A_u8LedStatus);
}

void HLED_voidToggleLed(u8 A_u8PortID, u8 A_u8PinId)
{
	MDIO_voidTogglePinValue(A_u8PortID, A_u8PinId)	;
}
