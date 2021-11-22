/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 13 NOV, 2021                            */
/**********************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_voidSleep(u8 Copy_u8TimeOut)
{
    if(Copy_u8TimeOut <= 7)
    {
        /*Clear For The 3 bits of the prescaler*/
        WDTCR &= 0b11111000;
        WDTCR |= Copy_u8TimeOut;
    }
    else
    {
        /*Do Nothing*/
    }
}

void WDT_voidEnable(void)
{
    SET_BIT(WDTCR, WDTCR_WDE);
}

void WDT_voidDisbale(void)
{
    /*Write one to WDTOE and WDE in the same operation*/
    WDTCR = (1 << WDTCR_WDTOE) | (1 << WDE);
    /*Write Zero To WDE Within the next four cycles*/
    WDTCR = 0x00;
}