#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define 		MCUCR			*((volatile u8 *)0x55)		// uController Control Register 
#define			MCUCR_ISC00		0							// Interrupt 0 Sense Control 0
#define			MCUCR_ISC01		1							// Interrupt 0 Sense Control 1
#define			MCUCR_ISC10		2							// Interrupt 1 Sense Control 0
#define			MCUCR_ISC11		3							// Interrupt 1 Sense Control 1

#define 		MCUCSR			*((volatile u8 *)0x54)		// uController Control Status Register 
#define			MCUCSR_ISC2		6							// Interrupt 2 Sense Control

#define 		GICR			*((volatile u8 *)0x5B)		// General Interrupt Control Register 
#define			GICR_INT0		6							// Interrupt 0 Enable Bit
#define			GICR_INT1		7							// Interrupt 1 Enable Bit
#define			GICR_INT2		5							// Interrupt 2 Enable Bit

#define 		GIFR			*((volatile u8 *)0x5A)		// General Interrupt Control Register 
#define			GIFR_INTF0		6							// Interrupt 0 Flag Bit
#define			GIFR_INTF1		7							// Interrupt 1 Flag Bit
#define			GIFR_INTF2		5							// Interrupt 2 Flag Bit

#define		    DISABLE			0
#define		    ENABLE			1


#define         NULL        (void *)0

#endif