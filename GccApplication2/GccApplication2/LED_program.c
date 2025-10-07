/*
 * LED_program.c
 *
 * Created: 9/10/2025 12:48:40 AM
 *  Author: loaie
 */ 

#include "LED_interface.h"

void LED_voidInit(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType) 
{
    DIO_voidSetPinDirection(copy_u8PortId, copy_u8PinId, DIO_PIN_OUTPUT);

    switch (copy_u8ConnectionType)
    {
        case LED_FORWARD_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_LOW);
            break;

        case LED_REVERSE_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_HIGH);
            break;

        default:
            break;
    }
}

void LED_voidOn(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType) 
{
    switch (copy_u8ConnectionType)
    {
        case LED_FORWARD_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_HIGH);
            break;
            
        case LED_REVERSE_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_LOW);
            break;

        default:
            break;
    }   
}

void LED_voidOff(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType) 
{
    switch (copy_u8ConnectionType)
    {
        case LED_FORWARD_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_LOW);
            break;
        
        case LED_REVERSE_CONNECTION:
            DIO_voidSetPinValue(copy_u8PortId, copy_u8PinId, DIO_PIN_HIGH);
            break;

        default:
            break;
    }
}

void LED_voidToggle(u8 copy_u8PortId, u8 copy_u8PinId)
{
    DIO_voidTogglePinValue(copy_u8PortId, copy_u8PinId);
}
