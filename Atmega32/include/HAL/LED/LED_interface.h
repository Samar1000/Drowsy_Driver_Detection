
#ifndef INCLUDE_HAL_LED_LED_INTERFACE_H_
#define INCLUDE_HAL_LED_LED_INTERFACE_H_

#define LED_ON 1
#define LED_OFF 0

void HLED_voidTurnOn(u8 A_u8PortID, u8 A_u8PinId);
void HLED_voidTurnOff(u8 A_u8PortID, u8 A_u8PinId);
// LED_ON - LED_OFF
void HLED_voidSetLedStatus(u8 A_u8PortID, u8 A_u8PinId, u8 A_u8LedStatus);

void HLED_voidToggleLed(u8 A_u8PortID, u8 A_u8PinId);
#endif /* INCLUDE_HAL_LED_LED_INTERFACE_H_ */
