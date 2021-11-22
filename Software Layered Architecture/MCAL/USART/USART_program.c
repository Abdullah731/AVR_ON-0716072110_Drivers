/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 20 NOV, 2021                            */
/**********************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void USART_voidInit(void)
{
    /*Set Bit URSEL To Write On UCSRC*/
    SET_BIT(UCSRC, UCSRC_URSEL);
    /*Data Size = 8-bit*/
    SET_BIT(UCSRC, UCSRC_UCSZ0);
    SET_BIT(UCSRC, UCSRC_UCSZ1);
    CLR_BIT(UCSRB, UCSRB_UCSZ2);
    
    /*Stop bit = 1-bit*/
    CLR_BIT(UCSRC, UCSRC_USBS);

    /*Parity Mode = Disabled*/
    CLR_BIT(UCSRC, UCSRC_UPM0);
    CLR_BIT(UCSRC, UCSRC_UPM1);
    
    /*USART Mode = Asychnronous*/
    CLR_BIT(UCSRC, UCSRC_UMSEL);

    /*BaudRate = 9600*/
    UBRRL = 51;
    /*Clear Bit URSEL To Write On UBRRH*/
    CLR_BIT(UBRRH, UBRRH_URSEL);            // CLR_BIT(UCSRC, UCSRC_URSEL);
    UBRRH = 0;

    /*Enable Trasmitter & Receiver Circuits*/
    SET_BIT(UCSRB, UCSRB_TXEN);
    SET_BIT(UCSRB, UCSRB_RXEN);
}



void USART_voidTransmitData(u8 Copy_u8Data)
{
    /*Polling On The UDRE Flag*/
    while(GET_BIT(UCSRA, UCSRA_UDRE) == 0); // while(!GET_BIT(UCSRA, UCSRA_UDRE));
    /*Copy The Data To Be Transmitted To The UDR Register*/
    UDR = Copy_u8Data;
    /*Polling (Busy Wait) On The TXC Flag */
    while(GET_BIT(UCSRA, UCSRA_TXC) == 0);  // while(!GET_BIT(UCSRA, UCSRA_TXC));
}


void USART_u8ReceiveData(u8 * Copy_pu8ReceivedData)
{
    /*Polling (Busy Wait) On The RXC Flag*/
    while(GET_BIT(UCSRA, UCSRA_RXC) == 0);  // while(!GET_BIT(UCSRA, UCSRA_RXC));
    *Copy_pu8ReceivedData = UDR;
}