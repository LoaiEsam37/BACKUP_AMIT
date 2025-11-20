/*
 * SPI_interface.h
 *
 * Created: 11/20/2025 7:23:44 PM
 *  Author: loaie
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "STD_TYPES.h"

void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);

void SPI_voidTransceive(u8 copy_u8Data, u8* pu8ReceivedData);

#endif /* SPI_INTERFACE_H_ */