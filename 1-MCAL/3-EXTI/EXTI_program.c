/**************************************************************/
/**************************************************************/
/**************		Author: Adham Hossam		***************/
/**************		Layer:  MCAL				***************/
/**************		SWC: 	EXTI				***************/
/**************************************************************/
/**************************************************************/

#include "PLATFORM_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/*Global Pointer to function to hold INT0 ISR address*/
void (*EXTI_pvInt0Func)(void) = NULL;

void EXTI_voidInt0Init(void)
{
	/*1- Check sense control*/
#if INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR , MCUCR_ISC00);
	CLR_BIT(MCUCR , MCUCR_ISC01);

#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR , MCUCR_ISC00);
	CLR_BIT(MCUCR , MCUCR_ISC01);

#elif INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR , MCUCR_ISC00);
	SET_BIT(MCUCR , MCUCR_ISC01);

#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR , MCUCR_ISC00);
	SET_BIT(MCUCR , MCUCR_ISC01);

#else
#error	"Wrong INT0_SENSE configuration option"
#endif

	/*Check peripheral interrupt state*/
#if	INT0_INITAIAL_STATE == ENABLED
	SET_BIT(GICR , GICR_INT0);

#elif INT0_INITAIAL_STATE == DISABLED
	CLR_BIT(GICR , GICR_INT0);

#else
#error	"Wrong INT0_INITAIAL_STATE configuration option"
#endif

}

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Sense)
	{
	case LOW_LEVEL: 	CLR_BIT(MCUCR , MCUCR_ISC00); CLR_BIT(MCUCR , MCUCR_ISC01)  ;break;
	case ON_CHANGE: 	SET_BIT(MCUCR , MCUCR_ISC00); CLR_BIT(MCUCR , MCUCR_ISC01)  ;break;
	case FALLING_EDGE:  CLR_BIT(MCUCR , MCUCR_ISC00); SET_BIT(MCUCR , MCUCR_ISC01)  ;break;
	case RISING_EDGE:	SET_BIT(MCUCR , MCUCR_ISC00); SET_BIT(MCUCR , MCUCR_ISC01)  ;break;
	default: 			Local_u8ErrorState = NOK;
	}



	return Local_u8ErrorState;
}

/*Function which will be writen in main will be called by this fuction*/
u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER;
	}


	return Local_u8ErrorState;
}

/*ISR of INT0*/
void __vector_1 (void)	__attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*Do nothing*/
	}
}



