/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	USART				***************/
/**************************************************************/
/**************************************************************/


#include "PLATFORM_TYPES.h"
#include "BIT_MATH.h"

#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"

void USART_voidInit(void)
{
	u8 Local_u8UCSRCValue = 0;

	/*Select UCSRC Regsiter*/
	SET_BIT(Local_u8UCSRCValue ,UCSRC_URSEL);

	/*Set character size (to 8-bit)*/
	SET_BIT(Local_u8UCSRCValue , UCSRC_UCSZ1);
	SET_BIT(Local_u8UCSRCValue , UCSRC_UCSZ0);

	UCSRC = Local_u8UCSRCValue;

	/*Setting buad rate value*/
	UBRRL = 51;		//baud rate 9600

	/*Enable Receiver*/
	SET_BIT(UCSRB , UCSRB_RXEN);

	/*Enable Transmitter*/
	SET_BIT(UCSRB , UCSRB_TXEN);

}

void USART_voidSendData(u8 Copy_u8Data)
{
	while(	(GET_BIT(UCSRA , UCSRA_UDRE)) == 0);	/*wait until transmit data is empty*/
	UDR = Copy_u8Data;
}

u8 USART_voidRecieveData(void)
{
	while(	(GET_BIT(UCSRA , UCSRA_RXC)) == 0);		//Polling, waiting until Receive Complete
	return UDR;
}
