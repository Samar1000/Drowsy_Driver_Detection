/****************************************************/
/*   AUTHOR      : Abdelrahman Hossam               */
/*   Description : DIO DRIVER                       */
/*   DATE        : 03 SEP 2022                      */
/*   VERSION     : V01                              */
/****************************************************/

/****************************************************/
/* Library Directives							    */
/****************************************************/
#include "../include/LIB/STD_TYPES.h"
#include "../include/LIB/BIT_MATH.h"

/****************************************************/
/* DIO Directives								    */
/****************************************************/
#include "../include/MCAL/DIO/DIO_interface.h"
#include "../include/MCAL/DIO/DIO_private.h"
#include "../include/MCAL/DIO/DIO_configuration.h"


void MDIO_voidInit(void)
{
	DDRA_REG = CONC_BIT(PORTA_PIN7_DIRECTION,PORTA_PIN6_DIRECTION
					   ,PORTA_PIN5_DIRECTION,PORTA_PIN4_DIRECTION
					   ,PORTA_PIN3_DIRECTION,PORTA_PIN2_DIRECTION
					   ,PORTA_PIN1_DIRECTION,PORTA_PIN0_DIRECTION);

	DDRB_REG = CONC_BIT(PORTB_PIN7_DIRECTION,PORTB_PIN6_DIRECTION
					   ,PORTB_PIN5_DIRECTION,PORTB_PIN4_DIRECTION
					   ,PORTB_PIN3_DIRECTION,PORTB_PIN2_DIRECTION
					   ,PORTB_PIN1_DIRECTION,PORTB_PIN0_DIRECTION);

	DDRC_REG = CONC_BIT(PORTC_PIN7_DIRECTION,PORTC_PIN6_DIRECTION
					   ,PORTC_PIN5_DIRECTION,PORTC_PIN4_DIRECTION
					   ,PORTC_PIN3_DIRECTION,PORTC_PIN2_DIRECTION
					   ,PORTC_PIN1_DIRECTION,PORTC_PIN0_DIRECTION);

	DDRD_REG = CONC_BIT(PORTD_PIN7_DIRECTION,PORTD_PIN6_DIRECTION
					   ,PORTD_PIN5_DIRECTION,PORTD_PIN4_DIRECTION
					   ,PORTD_PIN3_DIRECTION,PORTD_PIN2_DIRECTION
					   ,PORTD_PIN1_DIRECTION,PORTD_PIN0_DIRECTION);

	PORTA_REG = CONC_BIT(PORTA_PIN7_VALUE,PORTA_PIN6_VALUE
					    ,PORTA_PIN5_VALUE,PORTA_PIN4_VALUE
					    ,PORTA_PIN3_VALUE,PORTA_PIN2_VALUE
					    ,PORTA_PIN1_VALUE,PORTA_PIN0_VALUE);

	PORTB_REG = CONC_BIT(PORTB_PIN7_VALUE,PORTB_PIN6_VALUE
						,PORTB_PIN5_VALUE,PORTB_PIN4_VALUE
						,PORTB_PIN3_VALUE,PORTB_PIN2_VALUE
						,PORTB_PIN1_VALUE,PORTB_PIN0_VALUE);

	PORTC_REG = CONC_BIT(PORTC_PIN7_VALUE,PORTC_PIN6_VALUE
						,PORTC_PIN5_VALUE,PORTC_PIN4_VALUE
						,PORTC_PIN3_VALUE,PORTC_PIN2_VALUE
						,PORTC_PIN1_VALUE,PORTC_PIN0_VALUE);

	PORTD_REG = CONC_BIT(PORTD_PIN7_VALUE,PORTD_PIN6_VALUE
						,PORTD_PIN5_VALUE,PORTD_PIN4_VALUE
						,PORTD_PIN3_VALUE,PORTD_PIN2_VALUE
						,PORTD_PIN1_VALUE,PORTD_PIN0_VALUE);
}

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
void MDIO_voidSetPinDirection (u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Direction)
{
	switch (A_u8PortId)
	{
	case DIO_PORTA:
					switch (A_u8Direction)
					{
					case DIO_INPUT : CLR_BIT(DDRA_REG,A_u8PinId); break;
					case DIO_OUTPUT: SET_BIT(DDRA_REG,A_u8PinId); break;
					}
					break;
	case DIO_PORTB:
					switch (A_u8Direction)
					{
					case DIO_INPUT : CLR_BIT(DDRB_REG,A_u8PinId); break;
					case DIO_OUTPUT: SET_BIT(DDRB_REG,A_u8PinId); break;
					}
					break;
	case DIO_PORTC:
					switch (A_u8Direction)
					{
					case DIO_INPUT : CLR_BIT(DDRC_REG,A_u8PinId); break;
					case DIO_OUTPUT: SET_BIT(DDRC_REG,A_u8PinId); break;
					}
					break;
	case DIO_PORTD:
					switch (A_u8Direction)
					{
					case DIO_INPUT : CLR_BIT(DDRD_REG,A_u8PinId); break;
					case DIO_OUTPUT: SET_BIT(DDRD_REG,A_u8PinId); break;
					}
					break;
	}
}


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

void MDIO_voidSetPinValue (u8 A_u8PortId, u8 A_u8PinId, u8 A_u8Value)
{
	switch (A_u8PortId)
	{
	case DIO_PORTA:
			switch (A_u8Value)
			{
			case DIO_HIGH: SET_BIT(PORTA_REG,A_u8PinId); break;
			case DIO_LOW : CLR_BIT(PORTA_REG,A_u8PinId); break;
			}
			break;
	case DIO_PORTB:
			switch (A_u8Value)
			{
			case DIO_HIGH: SET_BIT(PORTB_REG,A_u8PinId); break;
			case DIO_LOW : CLR_BIT(PORTB_REG,A_u8PinId); break;
			}
			break;
	case DIO_PORTC:
			switch (A_u8Value)
			{
			case DIO_HIGH: SET_BIT(PORTC_REG,A_u8PinId); break;
			case DIO_LOW : CLR_BIT(PORTC_REG,A_u8PinId); break;
			}
			break;
	case DIO_PORTD:
			switch (A_u8Value)
			{
			case DIO_HIGH: SET_BIT(PORTD_REG,A_u8PinId); break;
			case DIO_LOW : CLR_BIT(PORTD_REG,A_u8PinId); break;
			}
			break;
	}
}

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
void MDIO_voidSetPortDirection (u8 A_u8PortId,u8 A_u8Direction)
{
	switch (A_u8PortId)
	{
	case DIO_PORTA: DDRA_REG=A_u8Direction; break;
	case DIO_PORTB: DDRB_REG=A_u8Direction; break;
	case DIO_PORTC: DDRC_REG=A_u8Direction; break;
	case DIO_PORTD: DDRD_REG=A_u8Direction; break;
	}
}

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
void MDIO_voidSetPortValue (u8 A_u8PortId,u8 A_u8Value)
{
	switch (A_u8PortId)
	{
	case DIO_PORTA: PORTA_REG=A_u8Value; break;
	case DIO_PORTB: PORTB_REG=A_u8Value; break;
	case DIO_PORTC: PORTC_REG=A_u8Value; break;
	case DIO_PORTD: PORTD_REG=A_u8Value; break;
	}
}

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
u8 MDIO_u8GetPinValue(u8 A_u8PortId, u8 A_u8PinId)
{
	u8 local_u8PinValue=255;
	switch (A_u8PortId)
	{
	case DIO_PORTA: local_u8PinValue = GET_BIT(PINA_REG,A_u8PinId); break;
	case DIO_PORTB: local_u8PinValue = GET_BIT(PINB_REG,A_u8PinId); break;
	case DIO_PORTC: local_u8PinValue = GET_BIT(PINC_REG,A_u8PinId); break;
	case DIO_PORTD: local_u8PinValue = GET_BIT(PIND_REG,A_u8PinId); break;
	}

	return local_u8PinValue;
}

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
void MDIO_voidTogglePinValue (u8 A_u8PortId, u8 A_u8PinId)
{
	switch (A_u8PortId)
	{
	case DIO_PORTA: TOGGLE_BIT(PORTA_REG,A_u8PinId); break;
	case DIO_PORTB: TOGGLE_BIT(PORTB_REG,A_u8PinId); break;
	case DIO_PORTC: TOGGLE_BIT(PORTC_REG,A_u8PinId); break;
	case DIO_PORTD: TOGGLE_BIT(PORTD_REG,A_u8PinId); break;
	}
}
