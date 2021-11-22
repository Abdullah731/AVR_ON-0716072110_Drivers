/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 	         							  */
/* !Version     : v2.0									  */
/* !Date        : 12 NOV, 2021                             */
/**********************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidTimer0Init(void);
void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue);
void TIMERS_voidTimer0SetPreloadValue(u8 Copy_u8PreloadValue);
void TIMERS_voidTimer0CTCSetCallBackFunction(void (*Copy_pvCTCFunction)(void));
void TIMERS_voidTimer1ChannelASetCompareMatchValue(u16 Copy_u16CompareMatchValue);
void TIMERS_voidTimer1SetOverflowValue(u16 Copy_u16OverflowValue);
void TIMERS_voidTimer1Init(void);

#endif