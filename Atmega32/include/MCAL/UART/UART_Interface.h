/*
 * UART_Interface.h
 *
 *  Created on: Feb 1, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_



#define USART_TX_INTERRUPT   0
#define USART_RX_INTERRUPT   1
#define USART_UDRE_INTERRUPT 2

void UART_voidInit(void);
void UART_voidSendByteSynchNonBlocking (u8 copy_u8Byte);
void UART_voidSendByteSynchBlocking (u8 copy_u8Byte);
void UART_voidSendByteAsynch(u8 copy_u8Byte);
u8 UART_u8READByteSynchBlocking (void);
u8 UART_u8READByteSynchNonBlocking (void);
u8 UART_u8READByteAsynch (void);
void UART_voidSetCallBack(u8 copy_u8InterruptType, void (*copy_PtrFunc)(void));



#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
