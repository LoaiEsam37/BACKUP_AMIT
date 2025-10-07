/*
 * SWITCH_program.c
 *
 * Created: 9/11/2025 3:26:49 PM
 *  Author: loaie
 */

#include "SWITCH_interface.h"

void SWITCH_voidInit(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8ConnectionType)
{
    switch (copy_u8ConnectionType)
    {
        case SWITCH_FORWARD_CONNECTION:
            DIO_voidActivePinInternalPDR(copy_u8PortId, copy_u8PinId);
            break;

        case SWITCH_REVERSE_CONNECTION:
            DIO_voidActivePinInternalPUR(copy_u8PortId, copy_u8PinId);
            break;

        default:
            break;
    }
}

void SWITCH_voidGetState(u8 copy_u8PortId,
                         u8 copy_u8PinId,
                         u8 copy_u8ConnectionType,
                         SWITCH_State_t *penuSwitchStatus)
{
    if (penuSwitchStatus == NULL)
    {
        return;
    }

    u8 u8PinValue = 0;
    DIO_voidGetPinValue(copy_u8PortId, copy_u8PinId, &u8PinValue);

    switch (copy_u8ConnectionType)
    {
        case SWITCH_FORWARD_CONNECTION:
            *penuSwitchStatus = (u8PinValue == DIO_PIN_HIGH) ? SWITCH_PRESSED : SWITCH_RELEASED;
            break;

        case SWITCH_REVERSE_CONNECTION:
            *penuSwitchStatus = (u8PinValue == DIO_PIN_LOW) ? SWITCH_PRESSED : SWITCH_RELEASED;
            break;

        default:
            *penuSwitchStatus = SWITCH_RELEASED;
            break;
    }
}
