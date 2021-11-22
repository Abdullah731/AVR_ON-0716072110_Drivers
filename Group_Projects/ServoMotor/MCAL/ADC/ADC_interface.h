#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#define ADC_CHANNEL0	0
void ADC_voidInit(void);
u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber);
u8 ADC_u8StartConversionAsynchronous(u8 Copy_u8ChannelNumber, void (*Copy_pvCallBackFunction)(void));

#endif