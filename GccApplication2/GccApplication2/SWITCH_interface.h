/*
 * SWITCH_interface.h
 *
 * Created: 9/11/2025 3:26:32 PM
 *  Author: loaie
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#include "DIO_interface.h"

/* Enum for Switch Status */
typedef enum
{
    SWITCH_RELEASED = 0,
    SWITCH_PRESSED
} SWITCH_State_t;

/* Macros for Switch Connection Type */
#define SWITCH_FORWARD_CONNECTION   0
#define SWITCH_REVERSE_CONNECTION   1

/* Macros for Switch Pins */
#define SWITCH1_PIN     DIO_PIN2
#define SWITCH2_PIN     DIO_PIN3
#define SWITCH3_PIN     DIO_PIN7

/* Macros for Switch Ports */
#define SWITCH1_PORT    DIO_PORTD
#define SWITCH2_PORT    DIO_PORTD
#define SWITCH3_PORT    DIO_PORTD

/* Function Prototypes */
void SWITCH_voidInit(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType);
void SWITCH_voidGetState(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType, SWITCH_State_t *penuSwitchStatus);

#endif /* SWITCH_INTERFACE_H_ */
