/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	USART				***************/
/**************************************************************/
/**************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);

void USART_voidSendData(u8 Copy_u8Data);

u8 USART_voidRecieveData(void);



#endif /*USART_INTERFACE_H_*/
