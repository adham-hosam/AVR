/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	WDT				***************/
/**************************************************************/
/**************************************************************/

#ifndef WDT_CONFIG_H_
#define WDT_CONFIG_H_

#define WDTCR			*((volatile u8*)0x41)	/*Watchdog Timer Control Register*/
#define WDTCR_WDTOE		4						/*Watchdog Turn-off Enable*/
#define WDTCR_WDE		3						/*Watchdog Enable*/
#define WDTCR_WDP2		2						/*Watchdog Timer Prescaler*/
#define WDTCR_WDP1		1
#define WDTCR_WDP0		0

#endif /*WDT_CONFIG_H_*/
