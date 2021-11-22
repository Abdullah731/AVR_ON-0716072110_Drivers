#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADMUX			*((volatile u8 *)0x27)
#define ADMUX_MUX0		0
#define ADMUX_MUX1		1
#define ADMUX_MUX2		2
#define ADMUX_MUX3		3
#define ADMUX_MUX4		4
#define ADMUX_ADLAR		5	// Left Adjust Bit
#define ADMUX_REFS0		6	// Reference Selection Bit 0
#define ADMUX_REFS1		7	// Reference Selection Bit 1

#define ADCSRA			*((volatile u8 *)0x26)	// ADC Status and Control Register
#define ADCSRA_ADPS0	0	// Prescaler Bit 0
#define ADCSRA_ADPS1	1	// Prescaler Bit 1
#define ADCSRA_ADPS2	2	// Prescaler Bit 2
#define ADCSRA_ADIE		3	// ADC Interrupt Enable
#define ADCSRA_ADIF		4	// ADC Interrupt Flag
#define ADCSRA_ADATE	5	// ADC Auto Trigger Enable
#define ADCSRA_ADSC		6	// ADC Start Conversion
#define ADCSRA_ADEN		7	// ADC Enable

#define	ADCH			*((volatile u8 *)0x25)	// ADC High Register
#define	ADCL			*((volatile u8 *)0x24)	// ADC Low Register
#define ADC				*((volatile u16 *)0x24)	// ADC Result Register

#define PRESCALER_MASK 				0b11111000
#define ADC_PRESCALER_DIV_BY_64		6
#define CHANNEL_NUMBER_MASK			0b11100000
#define BUSY						1
#define NOTBUSY						0


#endif