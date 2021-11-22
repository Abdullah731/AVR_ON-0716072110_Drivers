#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMERS/TIMERS_interface.h"

// 999  -> 0 Angle   // 499
// 1999 -> 180 Angle // 2249
void main(void)
{
	DIO_voidSetPinDirection(PORTD, PIN5, OUTPUT);
	TIMERS_voidTimer1Init();
	TIMERS_voidTimer1SetOverflowValue(19999);

	while(1)
	{
		TIMERS_voidTimer1ChannelASetCompareMatchValue(999); //499 // 0 Angle
	}
}
