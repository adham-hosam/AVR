/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/ 
/**************		Layer:  MCAL				***************/
/**************		SWC: 	PORT				***************/
/**************************************************************/
/**************************************************************/

#ifndef PORT_REGISTE_H_
#define PORT_REGISTE_H_

#define DDRA		*((volatile u8*)0x3A)
#define DDRB		*((volatile u8*)0x37)
#define DDRC	    *((volatile u8*)0x34)
#define DDRD	    *((volatile u8*)0x31)

#define PORTA		*((volatile u8*)0x3B)
#define PORTB		*((volatile u8*)0x38)
#define PORTC	    *((volatile u8*)0x35)
#define PORTD		*((volatile u8*)0x32)




#endif /* PORT_REGISTE_H_ */