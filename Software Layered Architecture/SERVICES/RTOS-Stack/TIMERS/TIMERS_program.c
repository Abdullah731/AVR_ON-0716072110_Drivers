/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v2.0									  */
/* !Date        : 12 NOV, 2021                            */
/**********************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

void (*Global_pvCTCFunction)(void) = NULL;
void (*Global_pvOVFFunction)(void) = NULL;

void TIMERS_voidTimer0Init(void)
{
	/*Set CTC Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	/*Prescaler = 64*/
	TCCR0 &= 0b11111000;
	TCCR0 |= 0b00000011;

	/*Enable CTC Interrupt*/
	SET_BIT(TIMSK, TIMSK_OCIE0);
}

void TIMERS_voidTimer0OVFSetCallBackFunction(void (*Copy_pvOVFFunction)(void))
{
	Global_pvOVFFunction = Copy_pvOVFFunction;
}


void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
	/*Set Compare Match Value To The OCR0 Register*/
	OCR0 = Copy_u8CompareMatchValue;
}

void TIMERS_voidTimer0SetPreloadValue(u8 Copy_u8PreloadValue)
{
	/*Set Compare Match Value To The OCR0 Register*/
	TCNT0 = Copy_u8PreloadValue;
}

void TIMERS_voidTimer0CTCSetCallBackFunction(void (*Copy_pvCTCFunction)(void))
{
	Global_pvCTCFunction = Copy_pvCTCFunction;
}

/*ISR For Timer 0 Compare Match*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(Global_pvCTCFunction != NULL)
	{
		Global_pvCTCFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}


/*ISR For Timer 0 Overflow*/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if(Global_pvOVFFunction != NULL)
	{
		Global_pvOVFFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}
