/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	ADC			    	***************/
/**************************************************************/
/**************************************************************/

#include "PLATFORM_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_register.h"

static u8* ADC_pu8Reading = NULL;
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;

u8 ADC_u8SBusyState = IDLE;

void ADC_voidInt(void)
{
	/*AVCC as refrence voltage*/
	CLR_BIT(ADMUX, ADMUX_REFS1);
	SET_BIT(ADMUX, ADMUX_REFS0);

	/*Activate left adjust result*/
	SET_BIT(ADMUX, ADMUX_ADLAR);

	/*Set prescaler to devide by 128*/
	SET_BIT(ADCSRA, ADCSRA_ADPS2);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS0);

	/*Enable ADC peripheral*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}


u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u8* copy_pu8Reading)
{
	u32 Local_u32Counter = 0;
	u8 Local_u8ErrorState = OK;
	if(ADC_u8SBusyState == IDLE)
	{
		/*ADC is now busy*/
		ADC_u8SBusyState = BUSY;

		/*Clear the MUX bits in MUX register*/
		ADMUX &= 0b11100000;

		/*Set the required channel*/
		ADMUX |= Copy_u8Channel;

		/*Start conversion*/
		SET_BIT(ADCSRA, ADCSRA_ADSC);

		/*Polling busy waiting untill the conversion complete flag is set or counter reaching timeout value*/
		while(	((GET_BIT(ADCSRA, ADCSRA_ADIF))==0) &&(Local_u32Counter != ADC_u32TIMEOUT) )
		{
			Local_u32Counter++;
		}
		if(Local_u32Counter == ADC_u32TIMEOUT)
		{
			/*loop is broken because timeout is reached*/
			Local_u8ErrorState = NOK;
		}
		else
		{
			/*loop is broken because FLAG is raised*/

			/*Clear the conversion complete flag by setting it*/
			SET_BIT(ADCSRA, ADCSRA_ADIF);

			/*Return the reading*/
			*copy_pu8Reading = ADCH;

			/*ADC is finished, return it to idle*/
			ADC_u8SBusyState = IDLE;
		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}
	return Local_u8ErrorState;

}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u8* copy_pu8Reading, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if(ADC_u8SBusyState == IDLE)
	{
		if(	(copy_pu8Reading == NULL) || (Copy_pvNotificationFunc == NULL) )
		{
			Local_u8ErrorState = NULL_POINTER;
		}
		else
		{
			/*make ADC busy in order not to work until being idle*/
			ADC_u8SBusyState = BUSY;

			/*Copy local pointers to the global pointers*/
			ADC_pu8Reading = copy_pu8Reading;

			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/*Clear the MUX bits in MUX register*/
			ADMUX &= 0b11100000;

			/*Set the required channel*/
			ADMUX |= Copy_u8Channel;

			/*Start conversion*/
			SET_BIT(ADCSRA, ADCSRA_ADSC);

			/*ADC interrupt enable*/
			SET_BIT(ADCSRA , ADCSRA_ADIE);

		}
	}
	else
	{
		Local_u8ErrorState = BUSY_FUNC;
	}

	return Local_u8ErrorState;
}

void __vector_16 (void)	__attribute__((signal));
void __vector_16 (void)
{
	/*Read ADC result*/
	*ADC_pu8Reading = ADCH;

	/*make ADC state idle because it finished*/
	ADC_u8SBusyState = IDLE;

	/*Invoke the callBack notification function*/
	ADC_pvCallBackNotificationFunc();

	/*Disable ADC conversion complete interrupt*/
	CLR_BIT(ADCSRA , ADCSRA_ADIE);
}
