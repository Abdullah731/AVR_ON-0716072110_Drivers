#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void (*Global_pvNotificationFunction)(void) = NULL;
u8 ADC_u8Result;
u8 ADC_u8BusyState = NOTBUSY;

void ADC_voidInit(void)
{
	/*Set AREF To Be AVCC*/
	CLR_BIT(ADMUX, ADMUX_REFS1);
	SET_BIT(ADMUX, ADMUX_REFS0);
	
	/*Set The Left Adjust*/
	SET_BIT(ADMUX, ADMUX_ADLAR);

	/*Set The Prescaler To Be = 64*/
	ADCSRA &= PRESCALER_MASK;
	ADCSRA |= ADC_PRESCALER;
	
	/*Enable ADC Peripheral*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}


u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber)
{
	if(ADC_u8BusyState == BUSY)
	{
		return 0;
	}
	else
	{
		/*Set The ADC Peripheral to Busy*/
		ADC_u8BusyState = BUSY;
		/*Clear The First 5-bits*/
		ADMUX &= CHANNEL_NUMBER_MASK;
		ADMUX |= Copy_u8ChannelNumber;
		/*Start The Conversion*/
		SET_BIT(ADCSRA, ADCSRA_ADSC);
		/*Polling (Busy Waiting) until the conversion completes*/
		while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);
		/*Clear The Flag*/
		SET_BIT(ADCSRA, ADCSRA_ADIF);
		/*Set The ADC Peripheral to Not Busy*/
		ADC_u8BusyState = NOTBUSY;
		/*Return The Result*/
		return ADCH;
	}
}



u8 ADC_u8StartConversionAsynchronous(u8 Copy_u8ChannelNumber, void (*Copy_pvCallBackFunction)(void))
{
	if(ADC_u8BusyState == BUSY)
	{
		return 0;
	}
	else
	{
		/*Set ADC To Be Busy*/
		ADC_u8BusyState = BUSY;
		/*Clear The First 5-bits*/
		ADMUX &= CHANNEL_NUMBER_MASK;
		ADMUX |= Copy_u8ChannelNumber;
		/*Set The CallBack Function*/
		Global_pvNotificationFunction = Copy_pvCallBackFunction;
		/*Start The Conversion*/
		SET_BIT(ADCSRA, ADCSRA_ADSC);
		/*ADC Interrupt Enable*/
		SET_BIT(ADCSRA, ADCSRA_ADIE); // => in the Init Function
		/*Return The Data*/
		return ADC_u8Result;
	}
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/*Read The Result*/
	ADC_u8Result = ADCH;
	
	/*Check if the Global Pointer To Function points to NULL*/
	if(Global_pvNotificationFunction != NULL)
	{
		/*invoke the call back function*/
		Global_pvNotificationFunction();
		/*Set ADC To Be Not Busy*/
		ADC_u8BusyState = NOTBUSY;
		/*Disbale ADC Interrupt*/
		CLR_BIT(ADCSRA, ADCSRA_ADIE);
	}
	else
	{
		/*Do Nothing*/
	}
	
}


