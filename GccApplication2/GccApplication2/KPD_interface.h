/*
 * Keypad_interface.h
 *
 * Created: 9/28/2025 7:16:17 PM
 *  Author: loaie
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "STD_TYPES.h"

#define KPD_NO_PRESSED_KEY   0xFF

void KPD_voidInit(void);
void KPD_voidGetValue(u8* pu8PressedVal);

#endif /* KEYPAD_INTERFACE_H_ */