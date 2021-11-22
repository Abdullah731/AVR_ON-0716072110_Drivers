/*Library Inclusion*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

/*Self layer*/

/*Lower Layer*/
#include "../../MCAL/DIO/DIO_interface.h"

/*Self Files*/
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include <util/delay.h>

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set The RS Pin To Be Low: 0 for Command*/
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, LOW);
	
	/*Set The RW Pin To Be Low: 0 for Write*/
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
	
	/*Set The Port Value To Be The Command*/
	DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Command);
	
	/*Set The Enable Pin To Be High*/
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	
	/*wait for 2msec*/
	_delay_ms(2);

	/*Set The Enable Pin To Be Low*/
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
	/*Set The RS Pin To Be High: 1 for Data*/
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RS_PIN, HIGH);
	
	/*Set The RW Pin To Be Low: 0 for Write*/
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_RW_PIN, LOW);
	
	/*Set The Port Value To Be The Data*/
	DIO_voidSetPortSpecificValue(LCD_DATA_PORT, Copy_u8Data);
	
	/*Set The Enable Pin To Be High*/
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, HIGH);
	
	/*wait for 2msec*/
	_delay_ms(2);

	/*Set The Enable Pin To Be Low*/
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_EN_PIN, LOW);
}

void LCD_voidInit(void)
{
	/*Set The Data Port To Be Output*/
	DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);
	
	/*Set The Control Pins To Be Output*/
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, OUTPUT);
	
	/*wait for more than 30msec*/
	_delay_ms(40);
	
	/*Send The Function Set Command: N: 1=> 2-Lines, F: 0=> 5*8 Dots*/
	LCD_voidSendCommand(0x38);
	
	/*Send The Function Set Command: D: 1=> Display ON, C: 1=> Visible, B: 1=> Blink*/
	LCD_voidSendCommand(0x0F);
	
	/*Send The Display Clear Command*/
	LCD_voidSendCommand(0x01);
}









