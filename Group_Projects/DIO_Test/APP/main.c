#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_interface.h"

void main(void)
{
	DIO_voidSetPinDirection(PORTA, PIN0, OUTPUT);
	DIO_voidSetPinValue(PORTA, PIN0, HIGH);
	while(1);
}
