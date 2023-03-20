/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	TWI					***************/
/**************************************************************/
/**************************************************************/

#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_

#define TWBR 			*((volatile u8*)0x20)		/*TWI Bit Rate Register*/

#define TWCR			*((volatile u8*)0x56)		/*TWI Control Register*/
#define TWCR_TWINT		7							/*Interrupt Flag*/
#define TWCR_TWEA      	6                           /*Enable Acknowledge Bit*/
#define TWCR_TWSTA      5                           /*START Condition Bit*/
#define TWCR_TWSTO      4                           /*STOP Condition Bit*/
#define TWCR_TWWC       3                           /*Write Collision Flag*/
#define TWCR_TWEN       2                           /*Enable Bit*/
#define TWCR_TWIE       0                           /*Interrupt Enable*/

#define TWSR 			*((volatile u8*)0x21)		/*TWI Status Register*/
#define TWSR_TWPS0		0							/*Prescaler Bits*/
#define TWSR_TWPS1		1							

#define TWDR 			*((volatile u8*)0x23)		/*TWI Data Register*/

#define TWAR			*((volatile u8*)0x22)		/*TWI (Slave) Address Register*/
#define TWAR_TWGCE		0							/*General Call Recognition Enable Bit*/


#endif /*TWI_REGISTER_H_*/