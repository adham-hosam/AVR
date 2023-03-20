/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  HAL					***************/
/**************		SWC: 	KEYPAD				***************/
/**************************************************************/
/**************************************************************/

#include "PLATFORM_TYPES.h"

#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8_GetPressedKey(void)
{
	u8 Local_u8PressedKey =  KPD_NO_PRESSED_KEY, Local_u8ColumnsIdx, Local_u8RowsIdx , Local_u8PinState;
	static u8 Local_u8KPDArr[ROW_NUM][COLUMNS_NUM] = KPD_ARR_VAL;
	static u8 Local_u8ColumnsArr[COLUMNS_NUM] = {KPD_COLUMNS0_PIN , KPD_COLUMNS1_PIN , KPD_COLUMNS2_PIN , KPD_COLUMNS3_PIN};
	static u8 Local_u8RowArr[ROW_NUM] = {KPD_ROW0_PIN , KPD_ROW1_PIN , KPD_ROW2_PIN , KPD_ROW3_PIN};
	for (Local_u8ColumnsIdx = 0; Local_u8ColumnsIdx < COLUMNS_NUM; Local_u8ColumnsIdx++) {

		/*Activate current columns*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8ColumnsArr[Local_u8ColumnsIdx] , DIO_u8PIN_LOW);

		for(Local_u8RowsIdx = 0 ; Local_u8RowsIdx < ROW_NUM ; Local_u8RowsIdx++)
		{
			/*Read current row*/
			DIO_u8GetPinValue(KPD_PORT , Local_u8RowArr[Local_u8RowsIdx] , &Local_u8PinState);

			/*Check if the switch is pressed*/
			if(DIO_u8PIN_LOW == Local_u8PinState)
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowsIdx][Local_u8ColumnsIdx];

				/*Polling (busy waiting) until the the key is released*/
				while(DIO_u8PIN_LOW == Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT , Local_u8RowArr[Local_u8RowsIdx] , &Local_u8PinState);
				}
				return Local_u8PressedKey;
			}

		}
		/*Deactivate the current column*/
		DIO_u8SetPinValue(KPD_PORT, Local_u8ColumnsArr[Local_u8ColumnsIdx] , DIO_u8PIN_HIGH);

	}


	return Local_u8PressedKey;
}
