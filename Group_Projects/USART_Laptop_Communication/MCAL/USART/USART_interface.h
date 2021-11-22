/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 20 NOV, 2021                            */
/**********************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART_voidInit(void);
void USART_voidTransmitData(u8 Copy_u8Data);
void USART_u8ReceiveData(u8 * Copy_pu8ReceivedData);


#endif