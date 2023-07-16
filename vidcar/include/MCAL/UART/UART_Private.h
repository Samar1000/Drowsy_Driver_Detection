/*
 * UART_Private.h
 *
 *  Created on: Feb 1, 2022
 *      Author: abdelrahmanhossam
 */

#ifndef INCLUDE_MCAL_UART_UART_PRIVATE_H_
#define INCLUDE_MCAL_UART_UART_PRIVATE_H_

/*address of UART Control and status register A*/
#define UART_u8_UCSRA *((volatile u8*)0x2B)

/*address of UART Control and status register B*/
#define UART_u8_UCSRB *((volatile u8*)0x2A)

/*address of UART Control and status register C*/
#define UART_u8_UCSRC *((volatile u8*)0x40)

/*address of USART I/O register*/
#define UART_u8_UDR   *((volatile u8*)0x2C)

#define UART_u8_UBRRL *((volatile u8*)0x29)
#define UART_u8_UBRRH *((volatile u8*)0x40)

/* The equation to calculate the UBBR value */
#define BAUD_RATE_EQUATION (F_CPU/16/BaudRate-1)

#define DOUBLE_SPEED_ON		1
#define DOUBLE_SPEED_OFF	0

# define INTERRUPT_ENABLE   1
# define INTERRUPT_DISABLE  0


#define UCSRA_U2X_BIT	        1
#define UCSRA_UDRIE_BIT	        5
#define UCSRA_TXCIE_BIT	        6
#define UCSRA_RXCIE_BIT	        7

#define UCSRB_TX_ENABLE_BIT	    3
#define UCSRB_RX_ENABLE_BIT	    4
#define UCSRB_UDRIE_ENABLE_BIT  5
#define UCSRB_TXCIE_ENABLE_BIT	6
#define UCSRB_RXCIE_ENABLE_BIT	7

#define ENABLE_TX				1
#define ENABLE_RX				1

#define DONOT_CARE_BIT          0

#define CHAR_FIVE_BIT  5
#define CHAR_SIX_BIT   6
#define CHAR_SEVEN_BIT 7
#define CHAR_EIGHT_BIT 8
#define CHAR_NINE_BIT  9

#define UCSRC_REGISTER_SELECT   1

#define ASYNCHRONOUS_OPERATION  0
#define SYNCHRONOUS_OPERATION   0

#define PARITY_DISABLE   0
#define PARITY_EVEN  	 2
#define PARITY_ODD 		 3

#define BIT_SET		     1
#define BIT_CLEARED		 0

#define ONE_STOP_BIT	 0
#define TWO_STOP_BIT	 1

#define RISING_THEN_FALING 0
#define FALING_THEN_RISING 1

#define FLAG_DOWN          0
#define FLAG_UP            1
#endif /* INCLUDE_MCAL_UART_UART_PRIVATE_H_ */
