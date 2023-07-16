/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : DIO DRIVER                       */
/*   DATE        : 03 SEP 2022                      */
/*   VERSION     : V01                              */
/****************************************************/

#ifndef INCLUDE_MCAL_DIO_DIO_INTERFACE_H_
#define INCLUDE_MCAL_DIO_DIO_INTERFACE_H_

#define DIO_OUTPUT   1
#define DIO_INPUT    0

#define DIO_HIGH     1
#define DIO_LOW      0

#define DIO_PULLUP   1
#define DIO_FLOATING 0

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


void MDIO_voidInit(void);

/******************************************************************************/
/* Function: MDIO_voidSetPinDirection                        				  */
/* I/P Parameters: Port ID,  Pin ID, Pin Direction			          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given pin				       	  */
/******************************************************************************/
/* Options																	  */
/******************************************************************************/
/* A_u8PortId   : DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD 			  */
/* A_u8PinId    : PIN0 ... PIN7                                 			  */
/* A_u8Direction: DIO_INPUT - DIO_OUTPUT                        			  */
/******************************************************************************/
void MDIO_voidSetPinDirection (u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Direction);

/******************************************************************************/
/* Function: MDIO_voidSetPinValue	                        				  */
/* I/P Parameters: Port ID,  Pin ID, Pin Value				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given pin					       	  */
/******************************************************************************/
/* Options																	  */
/* A_u8PortId   : DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD    			  */
/* A_u8PinId    : PIN0 ... PIN7                             			      */
/* A_u8Value    : DIO_HIGH - DIO_LOW - DIO_PULLUP               			  */
/******************************************************************************/
void MDIO_voidSetPinValue (u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Value);


/******************************************************************************/
/* Function: MDIO_voidSetPortDirection                        				  */
/* I/P Parameters: Port ID,   Port Direction				          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the direction of a given port			       	  */
/******************************************************************************/
/* Options																	  */
/* A_u8PortId   : DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD    			  */
/* A_u8Direction: Set the Direction in hex format 						  	  */
/******************************************************************************/
void MDIO_voidSetPortDirection (u8 A_u8PortId,u8 A_u8Direction);

/******************************************************************************/
/* Function: MDIO_voidSetPortValue	                        				  */
/* I/P Parameters: Port ID,   Port Value					          		  */
/* Returns:it returns No thing                                				  */
/* Desc:This Function Sets the Value of a given port				       	  */
/******************************************************************************/
/* Options																	  */
/* A_u8PortId   : DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD    			  */
/* A_u8Value: Set the Direction in hex format 					  		  	  */
/******************************************************************************/
void MDIO_voidSetPortValue (u8 A_u8PortId,u8 A_u8Value);

/******************************************************************************/
/* Function: MDIO_u8GetPinValue		                        				  */
/* I/P Parameters: Port ID,  Pin ID							          		  */
/* Returns:it returns u8 value of pin                          				  */
/* Desc:This Function Gets the Value of a given pin					       	  */
/******************************************************************************/
/* Options																	  */
/* A_u8PortId   : DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD    			  */
/* A_u8PinId    : PIN0 ... PIN7                             			      */
/******************************************************************************/
u8 MDIO_u8GetPinValue(u8 A_u8PortId, u8 A_u8PinId);

/******************************************************************************/
/* Function: MDIO_voidTogglePinValue                        				  */
/* I/P Parameters: Port ID,  Pin ID							          		  */
/* Returns:it returns nothing                               				  */
/* Desc:This Function toggles pin value 							       	  */
/******************************************************************************/
/* Options																	  */
/* A_u8PortId   : DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD    			  */
/* A_u8PinId    : PIN0 ... PIN7                             			      */
/******************************************************************************/
void MDIO_voidTogglePinValue (u8 A_u8PortId, u8 A_u8PinId);
#endif /* INCLUDE_MCAL_DIO_DIO_INTERFACE_H_ */
