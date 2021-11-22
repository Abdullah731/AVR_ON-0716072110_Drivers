#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMERS/TIMERS_interface.h"
#include "../MCAL/GIE/GIE_interface.h"

#include "../HAL/LCD/LCD_interface.h"

void ICU_HW (void);
volatile u16 Global_u16OnTicks;
volatile u16 Global_u16PeriodTicks;


void main(void)
{
	/*Initialize LCD*/
	LCD_voidInit();
	/*Initialize Pins*/
	DIO_voidSetPinDirection(PORTB, PIN3, OUTPUT);		// OC0 Pin
	DIO_voidSetPinDirection(PORTD, PIN6, INPUT);		// ICP Pin
	/*TIMER0 Generate PWM -> On Time = 250usec, Period Time = 256usec*/
	TIMERS_voidTimer0SetCompareMatchValue(250);
	/*Initiate Timer 0 To Generate PWM Signal*/
	TIMERS_voidTimer0Init();
	/*Initiate Timer 1 To Run in Normal Mode*/
	TIMERS_voidTimer1Init();
	/*Set ICU Callback Function*/
	ICU_voidSetCallbackFunction(&ICU_HW);
	/*Set ICU Sense Control To Be Rising Edge*/
	ICU_voidSetSenseControl(RISING_EDGE);
	/*Enable ICU Interrupt*/
	ICU_voidInterruptControl(ENABLE);
	/*Global Interrupt Enable*/
	GIE_voidEnableGlobalInterrupt();

	while(1)
	{
		while( (Global_u16OnTicks == 0) || (Global_u16PeriodTicks == 0) );
		LCD_voidGoToXY(0,0);
		LCD_voidSendString("ON_TICKS=");
		LCD_voidSendNumber(Global_u16OnTicks);
		LCD_voidGoToXY(1,0);
		LCD_voidSendString("Per_TICKS=");
		LCD_voidSendNumber(Global_u16PeriodTicks);
	}
}


void ICU_HW(void)
{
	volatile static u8 Local_u8CounterState = 0;
	volatile static u16 Local_u16Reading1;
	volatile static u16 Local_u16Reading2;
	volatile static u16 Local_u16Reading3;
	Local_u8CounterState++;
	if(Local_u8CounterState == 1)	// You Are In State 1
	{
		/*Read ICR1 Register and save its value*/
		Local_u16Reading1 = ICU_u16ReadInputCapture();
	}
	else if(Local_u8CounterState == 2)	// You Are In State 2
	{
		/*Read ICR1 Register and save its value*/
		Local_u16Reading2 = ICU_u16ReadInputCapture();
		/*Change Sense Signal To Falling Edge*/
		ICU_voidSetSenseControl(FALLING_EDGE);
		/*Get Period Ticks and store it in the Period Ticks Global Variable*/
		Global_u16PeriodTicks = Local_u16Reading2 - Local_u16Reading1 - 1;

	}
	else if(Local_u8CounterState == 3)	// You Are In State 3
	{
		/*Read ICR1 Register and save its value*/
		Local_u16Reading3 = ICU_u16ReadInputCapture();
		/*Get On Ticks and store it in the On Ticks Global Variable*/
		Global_u16OnTicks = Local_u16Reading3 - Local_u16Reading2 - 1;
		/*Disable ICU Interrupt*/
		ICU_voidInterruptControl(DISABLE);
	}
}








