/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 3 DEC, 2021                             */
/**********************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

/*   MSB 
*    Prescaler = 16 
*    Leading Edge = Rising
*    Sample At Leading Edge
*/

void SPI_voidMasterInit(void)
{
    /*Set The Node To Be Master Node*/
    SET_BIT(SPCR, SPCR_MSTR);
    /*Set The MSB To Send First*/
    CLR_BIT(SPCR, SPCR_DORD);
    /*Set The Leading Edge To Be Rising Edge */
    CLR_BIT(SPCR, SPCR_CPOL);
    /*Sample At Leading Edge*/
    CLR_BIT(SPCR, SPCR_CPHA);
    /*Set The Clock Divider(Prescaler) to be = 16*/
    SET_BIT(SPCR, SPCR_SPR0);
    CLR_BIT(SPCR, SPCR_SPR1);
    CLR_BIT(SPSR, SPSR_SPI2X);
    /*Enable SPI*/
    SET_BIT(SPCR, SPCR_SPE);
}

void SPI_voidSlaveInit(void)
{
    /*Set The Node To Be Slave Node*/
    CLR_BIT(SPCR, SPCR_MSTR);
    /*Set The MSB To Send First*/
    CLR_BIT(SPCR, SPCR_DORD);
    /*Set The Leading Edge To Be Rising Edge */
    CLR_BIT(SPCR, SPCR_CPOL);
    /*Sample At Leading Edge*/
    CLR_BIT(SPCR, SPCR_CPHA);
    /*Enable SPI*/
    SET_BIT(SPCR, SPCR_SPE);
}


u8 SPI_u8Tranceive(u8 Copy_u8DataToBeSent)
{
    u8 Local_u8Dummy;
    u8 Local_u8ReceivedData;
    /*Set The Data In The SPDR Register To Send*/
    SPDR = Copy_u8DataToBeSent;
    /*Polling (busy Waiting) on the flag until the exchange complete*/
    while(!GET_BIT(SPSR, SPSR_SPIF)); // while(GET_BIT(SPSR, SPSR_SPIF) == 0);
    /*To Clear The Flag:
    * 1- Read The Register*/
    Local_u8Dummy = SPSR;
    /*2- Clear The Flag By Writing One*/
    SET_BIT(SPSR, SPSR_SPIF);
    /*3- Access SPDR*/
    Local_u8ReceivedData = SPDR;
    /*Return The Exchanged Data*/
    return Local_u8ReceivedData;
}




















