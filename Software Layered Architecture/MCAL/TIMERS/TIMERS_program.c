/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v2.0									  */
/* !Date        : 12 NOV, 2021                             */
/**********************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

void (*Global_pvCTCFunction)(void) = NULL;

void TIMERS_voidTimer0Init(void)
{
	/*Set Fast PWM Mode*/
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	/*Set Mode : Set On Top, Clear On Compare*/
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
		
	/*Prescaler = 8*/
	TCCR0 &= 0b11111000;
	TCCR0 |= 0b00000010;	
}

void TIMERS_voidTimer1Init(void)
{
	/*Set Mode 14*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);

	/*Set Mode: Set On Top Clear On Compare*/
	SET_BIT(TCCR1A, TCCR1A_COM1A1);
	CLR_BIT(TCCR1A, TCCR1A_COM1A0);
	
	/*Set Prescaler To Be = 8*/
	CLR_BIT(TCCR1B, TCCR1B_CS10);
	SET_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
}

void TIMERS_voidTimer1SetOverflowValue(u16 Copy_u16OverflowValue)
{
	ICR1 = Copy_u16OverflowValue;
}

void TIMERS_voidTimer1ChannelASetCompareMatchValue(u16 Copy_u16CompareMatchValue)
{
	OCR1A = Copy_u16CompareMatchValue;
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

void ICU_voidSetSenseControl(u8 Copy_u8SenseControl)
{
	switch(Copy_u8SenseControl)
	{
		case FALLING_EDGE:
			/*Set Sense Signal To Be Falling Edge*/
			CLR_BIT(TCCR1B, TCCR1B_ICES1);
			break;
		case RISING_EDGE:
		/*Set Sense Signal To Be Rising Edge*/
			SET_BIT(TCCR1B, TCCR1B_ICES1);
			break;
	}
}



void (*Global_pvICUFunction)(void) = NULL;

void ICU_voidSetCallbackFunction(void(*Copy_pvNotificationFunction)(void))
{
	/*Set Callback Function to the Global pointer to function*/
	Global_pvICUFunction = Copy_pvNotificationFunction;
}

u16 ICU_u16ReadInputCapture(void)
{
	/*Return Input Capture Register*/
	return ICR1;
}

void ICU_voidInterruptControl(u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case ENABLE:
			/*Enable ICU Interrupt*/
			SET_BIT(TIMSK, TIMSK_TICIE1);
		break;
		case DISABLE:
			/*Disable ICU Interrupt*/
			CLR_BIT(TIMSK, TIMSK_TICIE1);
		break;
	}
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


/*ISR For Input Capture Unit*/
void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if(Global_pvICUFunction != NULL)
	{
		Global_pvICUFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}






