/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	WDT				***************/
/**************************************************************/
/**************************************************************/

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define SLEEP_FOR_16_3ms	0		//*****//
#define SLEEP_FOR_32_5ms	1
#define SLEEP_FOR_65ms		2
#define SLEEP_FOR_0_13s		3
#define SLEEP_FOR_0_26s		4			/*Typical Time-out*/
#define SLEEP_FOR_0_52s		5
#define SLEEP_FOR_1_0s		6
#define SLEEP_FOR_2_1s		7					//*****//


void WDT_voidEnable(void);

void WDT_voidDsiable(void);

u8 WDT_voidSleep(u8 Copy_u8SleepTime);




#endif /*WDT_INTERFACE_H_*/
