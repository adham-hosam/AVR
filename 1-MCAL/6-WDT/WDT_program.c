/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	WDT				***************/
/**************************************************************/
/**************************************************************/
#include "PLATFORM_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_config.h"
#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_register.h"

void WDT_voidEnable(void)
{
	SET_BIT(WDTCR , WDTCR_WDE);
}

void WDT_voidDsiable(void)
{
	/*Set WDTOE and WDE bits*/
	WDTCR |= WDTCR_MASK;


	/*Clear WDE bit*/
	WDTCR = ZERO;

}

u8 WDT_voidSleep(u8 Copy_u8SleepTime)
{
	u8 Local_u8ErrorState = OK;

	if(Copy_u8SleepTime < 8 )
	{
		/*Clear the first 3 bits to set the time-out value*/
		WDTCR &= WDTCR_PRESCALER_MASK;

		/*Set the time-out value*/
		WDTCR |= Copy_u8SleepTime;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}

	return Local_u8ErrorState;
}
