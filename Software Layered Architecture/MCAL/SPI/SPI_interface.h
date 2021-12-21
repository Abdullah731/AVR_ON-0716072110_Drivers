/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 3 DEC, 2021                             */
/**********************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_u8Tranceive(u8 Copy_u8DataToBeSent);



#endif