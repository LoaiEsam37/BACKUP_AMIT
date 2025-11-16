/*
 * UART_interface.h
 *
 * Created: 11/16/2025 7:27:44 PM
 *  Author: loaie
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "STD_TYPES.h"

void UART_voidInit(void);
void UART_voidTXChar(u8 copy_u8Data);
void UART_charRXChar(u8* pu8Data);


#endif /* UART_INTERFACE_H_ */