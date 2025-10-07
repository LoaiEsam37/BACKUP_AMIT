/*
 * DIO_program.c
 *
 * Created: 9/9/2025 6:46:22 PM
 *  Author: loaie
 */ 

#include "DIO_interface.h"
#include "DIO_register.h"

void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection) 
{
	switch (copy_u8PinDirection)
	{
		case DIO_PIN_INPUT:
		switch(copy_u8PortId)
		{
			case DIO_PORTA: CLR_BIT(DDRA, copy_u8PinId); break;
			case DIO_PORTB: CLR_BIT(DDRB, copy_u8PinId); break;
			case DIO_PORTC: CLR_BIT(DDRC, copy_u8PinId); break;
			case DIO_PORTD: CLR_BIT(DDRD, copy_u8PinId); break;
		}
		break;
		
		case DIO_PIN_OUTPUT:
		switch(copy_u8PortId)
		{
			case DIO_PORTA: SET_BIT(DDRA, copy_u8PinId); break;
			case DIO_PORTB: SET_BIT(DDRB, copy_u8PinId); break;
			case DIO_PORTC: SET_BIT(DDRC, copy_u8PinId); break;
			case DIO_PORTD: SET_BIT(DDRD, copy_u8PinId); break;
		}
		break;
	}
}


void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	switch (copy_u8PinValue)
	{
		case DIO_PIN_INPUT:
		switch(copy_u8PortId)
		{
			case DIO_PORTA: CLR_BIT(PORTA, copy_u8PinId); break;
			case DIO_PORTB: CLR_BIT(PORTB, copy_u8PinId); break;
			case DIO_PORTC: CLR_BIT(PORTC, copy_u8PinId); break;
			case DIO_PORTD: CLR_BIT(PORTD, copy_u8PinId); break;
		}
		break;
		
		case DIO_PIN_OUTPUT:
		switch(copy_u8PortId)
		{
			case DIO_PORTA: SET_BIT(PORTA, copy_u8PinId); break;
			case DIO_PORTB: SET_BIT(PORTB, copy_u8PinId); break;
			case DIO_PORTC: SET_BIT(PORTC, copy_u8PinId); break;
			case DIO_PORTD: SET_BIT(PORTD, copy_u8PinId); break;
		}
		break;
	}
	
}


void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId) 
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: TOG_BIT(PORTA, copy_u8PinId); break;
		case DIO_PORTB: TOG_BIT(PORTB, copy_u8PinId); break;
		case DIO_PORTC: TOG_BIT(PORTC, copy_u8PinId); break;
		case DIO_PORTD: TOG_BIT(PORTD, copy_u8PinId); break;
	}
}


void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8* pu8PinValue) 
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: *pu8PinValue = GET_BIT(PINA, copy_u8PinId); break;
		case DIO_PORTB: *pu8PinValue = GET_BIT(PINB, copy_u8PinId); break;
		case DIO_PORTC: *pu8PinValue = GET_BIT(PINC, copy_u8PinId); break;
		case DIO_PORTD: *pu8PinValue = GET_BIT(PIND, copy_u8PinId); break;
	}
}


void DIO_voidActivePinInternalPUR(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: SET_BIT(PORTA, copy_u8PinId); break;
		case DIO_PORTB: SET_BIT(PORTB, copy_u8PinId); break;
		case DIO_PORTC: SET_BIT(PORTC, copy_u8PinId); break;
		case DIO_PORTD: SET_BIT(PORTD, copy_u8PinId); break;
	}
}


void DIO_voidActivePinInternalPDR(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: CLR_BIT(PORTA, copy_u8PinId); break;
		case DIO_PORTB: CLR_BIT(PORTB, copy_u8PinId); break;
		case DIO_PORTC: CLR_BIT(PORTC, copy_u8PinId); break;
		case DIO_PORTD: CLR_BIT(PORTD, copy_u8PinId); break;
	}
}


void DIO_voidSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: DDRA = copy_u8PortDirection; break;
		case DIO_PORTB: DDRB = copy_u8PortDirection; break;
		case DIO_PORTC: DDRC = copy_u8PortDirection; break;
		case DIO_PORTD: DDRD = copy_u8PortDirection; break;
	}
}


void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: PORTA = copy_u8PortValue; break;
		case DIO_PORTB: PORTB = copy_u8PortValue; break;
		case DIO_PORTC: PORTC = copy_u8PortValue; break;
		case DIO_PORTD: PORTD = copy_u8PortValue; break;
	}
}


void DIO_voidTogglePortValue(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: TOG_REG(PORTA); break;
		case DIO_PORTB: TOG_REG(PORTB); break;
		case DIO_PORTC: TOG_REG(PORTC); break;
		case DIO_PORTD: TOG_REG(PORTD); break;
	}
}


void DIO_voidGetPortValue(u8 copy_u8PortId, u8* pu8PortValue)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: *pu8PortValue = GET_REG(PINA); break;
		case DIO_PORTB: *pu8PortValue = GET_REG(PINB); break;
		case DIO_PORTC: *pu8PortValue = GET_REG(PINC); break;
		case DIO_PORTD: *pu8PortValue = GET_REG(PIND); break;
	}
}


void DIO_voidActivePortInternalPUR(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: SET_REG(PORTA); break;
		case DIO_PORTB: SET_REG(PORTB); break;
		case DIO_PORTC: SET_REG(PORTC); break;
		case DIO_PORTD: SET_REG(PORTD); break;
	}
}


void DIO_voidActivePortInternalPDR(u8 copy_u8PortId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA: CLR_REG(PORTA); break;
		case DIO_PORTB: CLR_REG(PORTB); break;
		case DIO_PORTC: CLR_REG(PORTC); break;
		case DIO_PORTD: CLR_REG(PORTD); break;
	}
}
