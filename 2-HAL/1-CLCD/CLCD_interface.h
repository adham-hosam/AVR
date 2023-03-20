/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/**************		SWC: 	LCD					***************/
/**************************************************************/
/**************************************************************/



#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 copy_u8command);

void CLCD_voidSendData(u8 copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(const char* copy_pcString);

void CLCD_voidGoToXY(u8 copy_u8XPos, u8 copy_u8YPos);

void CLCD_voidWriteSpecialCharacter(u8* copy_pu8Pattern , u8 copy_u8PatternNumber , u8 copy_u8XPos , u8 copy_u8YPos);


#endif
