/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	ADC			    	***************/
/**************************************************************/
/**************************************************************/


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX		  	    *((volatile u8*) 0x27)		//ADC multiplexer selection register
#define ADMUX_REFS1			7						    //Refrence selection bit1
#define ADMUX_REFS0			6							//Refrence selection bit0
#define ADMUX_ADLAR			5							//ADC left adjust result


#define ADCSRA		  	    *((volatile u8*) 0x26)		//ADC Control and Status Register A
#define ADCSRA_ADEN			7							//ADC Enable
#define ADCSRA_ADSC			6							//ADC Start Conversion
#define ADCSRA_ADATE		5                           //ADC Auto Trigger Enable
#define ADCSRA_ADIF			4                           //ADC Interrupt Flag
#define ADCSRA_ADIE			3                           //ADC Interrupt Enable
#define ADCSRA_ADPS2		2                           //ADC Prescaler Select bit2
#define ADCSRA_ADPS1		1                           //ADC Prescaler Select bit1
#define ADCSRA_ADPS0		0                           //ADC Prescaler Select bit0

#define ADCH	 *((volatile u8*) 0x25)					//ADC high register

#define ADCL	 *((volatile u8*) 0x24)					//ADC low register




#endif /*ADC_REGISTER_H_*/