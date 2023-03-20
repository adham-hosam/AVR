/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	SPI				***************/
/**************************************************************/
/**************************************************************/

#include "PLATFORM_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"

void SPI_voidInitMaster(void)
{
	/*Master initialization*/
	SET_BIT(SPCR , SPCR_MSTR);

	/*Clk prescaler devide by 16*/
	SET_BIT(SPCR , SPCR_SPR0);
	CLR_BIT(SPCR , SPCR_SPR1);
	CLR_BIT(SPSR ,SPSR_SPI2X);

	/*Enable SPI*/
	SET_BIT(SPCR , SPCR_SPE);
}

void SPI_voidInitSlave(void)
{
	/*Slave initialization*/
	CLR_BIT(SPCR , SPCR_MSTR);

	/*Enable SPI*/
	SET_BIT(SPCR , SPCR_SPE);
}

u8 SPI_u8Transceive(u8 Copy_u8Data)
{
	/*Send th data*/
	SPDR = Copy_u8Data;

	/*polling, waiting until transfer complete*/
	while(	(GET_BIT(SPSR , SPSR_SPIF)) == 0);

	/*Get the exchanged data*/
	return SPDR;
}
