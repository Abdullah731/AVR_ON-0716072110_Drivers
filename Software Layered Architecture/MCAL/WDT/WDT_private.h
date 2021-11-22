/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 13 NOV, 2021                            */
/**********************************************************/
#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

#define WDTCR         *((volatile u8*)0x41)   // Watch Dog Timer Control Register
#define WDTCR_WDP0    0                       // Watch Dog Timer Prescaler Bit 0
#define WDTCR_WDP1    1                       // Watch Dog Timer Prescaler Bit 1
#define WDTCR_WDP2    2                       // Watch Dog Timer Prescaler Bit 2
#define WDTCR_WDE     3                       // Watch Dog Timer Enable Bit
#define WDTCR_WDPTOE  4                      // Watch Dog Timer Turn-off Enable


#endif