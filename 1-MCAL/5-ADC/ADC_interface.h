/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	ADC			    	***************/
/**************************************************************/
/**************************************************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInt(void);


u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* copy_pu8Reading);

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* copy_pu8Reading, void(*Copy_pvNotificationFun)(void));

#endif /*ADC_INTERFACE_H_*/
