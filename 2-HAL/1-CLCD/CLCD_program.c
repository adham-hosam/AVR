/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/**************		SWC: 	LCD					***************/
/**************************************************************/
/**************************************************************/


#include "PLATFORM_TYPES.h"

#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set Data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);
}

void CLCD_voidSendString(const char* copy_pcString)
{
	u8 Local_u8Counter = 0;

	while(copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos)
{
	u8 Local_u8Adrress;

	/* location at the first line */
	if(copy_u8XPos == 0)
	{
		Local_u8Adrress = copy_u8YPos;
	}
	/* location at the second line */
	else if(copy_u8XPos == 1)
	{
		Local_u8Adrress = copy_u8YPos + 0x40 ;
	}
	/* set bit number 7 for set DDRAM address command then send the command */
	CLCD_voidSendCommand(Local_u8Adrress + 128);	//choosen address + 1000 0000 (128)

}

void CLCD_voidWriteNumber(s32 Copy_s32Num)
{
	static u8 Local_u32Reminder = 0, Local_u8Digits = 0;
	static s32 Local_s32ReverseNum = 0;

	/*Handling negative numbers*/
	if(Copy_s32Num< 0)
	{
		CLCD_voidSendData('-');
		Copy_s32Num *=-1;
	}
	while(Copy_s32Num)
	{
		Local_u32Reminder = Copy_s32Num % 10;
		Local_s32ReverseNum = Local_s32ReverseNum *10 + Local_u32Reminder;
		Copy_s32Num /= 10;
		Local_u8Digits++;
	}
	while(Local_u8Digits)
	{
		Local_u32Reminder = Local_s32ReverseNum % 10;
		CLCD_voidSendData(Local_u32Reminder+48);
		Local_s32ReverseNum /= 10;
		Local_u8Digits--;
	}

}

void CLCD_voidWriteSpecialCharacter(u8* copy_pu8Pattern , u8 copy_u8PatternNumber , u8 copy_u8XPos , u8 copy_u8YPos)
{
	u8 Local_uCGRAM8Address = 0 , Local_u8Iterator;

	/* calculate CGRAM address whose each block is 8-bytes*/
	Local_uCGRAM8Address = copy_u8PatternNumber * 8;

	/* send CGRAM address to LCD, with setting bit 6 */
	CLCD_voidSendCommand(Local_uCGRAM8Address + 64);	//Local_uCGRAM8Address + 0100 0000 (64)

	/* write the pattern into the CGRAM*/
	for(Local_u8Iterator = 0 ; Local_u8Iterator <8 ; Local_u8Iterator++)
	{
		CLCD_voidSendData(copy_pu8Pattern[Local_u8Iterator]);
	}

	/* go back to CGRAM tp display the pattern */
	CLCD_voidGoToXY(copy_u8XPos ,  copy_u8YPos);

	/* display the pattern written in the CGRAM */
	CLCD_voidSendData(copy_u8PatternNumber);

}











