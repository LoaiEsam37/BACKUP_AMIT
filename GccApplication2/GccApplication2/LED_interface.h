/*
 * LED_interface.h
 *
 * Created: 9/10/2025 12:49:00 AM
 *  Author: loaie
 */ 

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "DIO_interface.h"

/* LED Connection Types */
#define LED_FORWARD_CONNECTION   0
#define LED_REVERSE_CONNECTION   1

/* LED Pin Definitions */
#define LED1_PIN    DIO_PIN3
#define LED2_PIN    DIO_PIN2
#define LED3_PIN    DIO_PIN7
#define LED4_PIN    DIO_PIN6

/* LED Port Definitions */
#define LED1_PORT   DIO_PORTB
#define LED2_PORT   DIO_PORTC
#define LED3_PORT   DIO_PORTC
#define LED4_PORT   DIO_PORTD

/* Function Prototypes */
void LED_voidInit(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType);
void LED_voidOn(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType);
void LED_voidOff(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType);
void LED_voidToggle(u8 copy_u8PortId, u8 copy_u8PinId);

#endif /* LED_INTERFACE_H_ */
