/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	TWI					***************/
/**************************************************************/
/**************************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_


#define START_ACK				0x80		/*A START condition has been sent*/
#define	REP_START_ACK 			0X10		/*A repeated START condition has been sent*/
#define SLAVE_ADDR_AND_WR_ACK	0X18		/*Master transmit (slave address + write request)*/
#define SLAVE_ADDR_AND_RD_ACK	0X40		/*Master transmit (slave address + read request)*/
#define MSTR_WR_BYTE_ACK		0X28		/*Master transmit data ACK*/
#define MSTR_RD_BYTE_WITH_ACK	0X50		/*Master receive data  with ACK*/
#define MSTR_RD_BYTE_WITH_NACK	0x58		/*Master receive data  with not ACK*/
#define SLAVE_ADDR_RCVD_RD_REQ	0XA8		/*Means that slave address is received with read request*/
#define SLAVE_ADDR_RCVD_WR_REQ	0x60		/*Means that slave address is received with write request*/
#define SLAVE_DATA_RECEIVED		0X80		/*Means that a byte is received*/
#define SLAVE_BYTE_TRANSMITTED	0XB8		/*Means that the written byte is transmitted*/



#endif /*TWI_PRIVATE_H_*/