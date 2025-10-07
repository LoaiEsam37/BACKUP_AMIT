/*
 * SSD_interface.h
 *
 * Created: 9/16/2025 5:04:14 PM
 *  Author: loaie
 */ 


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "DIO_interface.h"

#define SSD_ID_ONE			1
#define SSD_ID_TWO			2

void SSD_voidInit(void);
void SSD_voidDisplayOneDigitNumber(u8 copy_u8SSDId, u8 copy_u8Number);
void SSD_voidDisplayTwoDigitNumber(u8 copy_u8Number);

#endif /* SSD_INTERFACE_H_ */