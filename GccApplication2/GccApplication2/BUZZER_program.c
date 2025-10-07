/*
 * BUZZER_program.c
 *
 * Created: 9/11/2025 2:46:31 PM
 *  Author: loaie
 */ 

#include "BUZZER_interface.h"

void BUZZER_voidInit(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType)
{
    DIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, DIO_PIN_OUTPUT);	

    switch (copy_u8ConnectionType)
    {
        case BUZZER_FORWARD_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_LOW);
            break;

        case BUZZER_REVERSE_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_HIGH);
            break;

        default:
            break;
    }
}

void BUZZER_voidOn(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType)
{
    switch (copy_u8ConnectionType)
    {
        case BUZZER_FORWARD_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_HIGH);
            break;

        case BUZZER_REVERSE_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_LOW);
            break;

        default:
            break;
    }
}

void BUZZER_voidOff(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType)
{
    switch (copy_u8ConnectionType)
    {
        case BUZZER_FORWARD_CONNECTION: 
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_LOW);
            break;
		
        case BUZZER_REVERSE_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_HIGH);
            break;

        default:
            break;
    }
}

void BUZZER_voidToggle(u8 copy_u8PortId, u8 copy_u8PinId)
{
    DIO_voidTogglePinValue(copy_u8PortId, copy_u8PinId);
}
