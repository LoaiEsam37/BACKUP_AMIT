/*
 * BUZZER_interface.h
 *
 * Created: 9/11/2025 2:47:05 PM
 *  Author: loaie
 */ 

#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#include "DIO_interface.h"

/* Buzzer connection types */
#define BUZZER_FORWARD_CONNECTION   0
#define BUZZER_REVERSE_CONNECTION   1

/* Example buzzer pin configuration */
#define BUZZER1_PIN    DIO_PIN0
#define BUZZER1_PORT   DIO_PORTB

/* Buzzer APIs */
void BUZZER_voidInit(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType);
void BUZZER_voidOn(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType);
void BUZZER_voidOff(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType);
void BUZZER_voidToggle(u8 copy_u8PortId, u8 copy_u8PinId);

#endif /* BUZZER_INTERFACE_H_ */
