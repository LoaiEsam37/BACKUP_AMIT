/*
 * SSD_program.c
 *
 * Created: 9/16/2025 5:04:02 PM
 *  Author: loaie
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
/* UTILES_LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "SSD_interface.h"
#include "SSD_config.h"
#include "SSD_private.h"


void SSD_voidInit(void)
{
	DIO_voidSetPortDirection(SSD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_OUTPUT);
}


void SSD_voidDisplayOneDigitNumber(u8 copy_u8SSDId, u8 copy_u8Number)
{
	if (copy_u8Number <= 9)
	{
		DIO_voidSetPortValue(SSD_DATA_PORT, PRV_u8Number[copy_u8Number]);

		switch (copy_u8SSDId)
		{
			case SSD_ID_ONE: DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_HIGH);	break;
			case SSD_ID_TWO: DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_HIGH);	break;
		}
	}
	else
	{
		
	}
}



void SSD_voidDisplayTwoDigitNumber(u8 copy_u8Number)
{
	if (copy_u8Number <= 99)
	{
		u8 local_u8Tens = copy_u8Number / 10;
		u8 local_u8Units = copy_u8Number % 10;
		
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_LOW);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_LOW);
		
		DIO_voidSetPortValue(SSD_DATA_PORT, PRV_u8Number[local_u8Tens]);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E1_PIN, DIO_PIN_LOW);
		
		DIO_voidSetPortValue(SSD_DATA_PORT, PRV_u8Number[local_u8Units]);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_voidSetPinValue(SSD_ENABLE_PORT, SSD_E2_PIN, DIO_PIN_LOW);
		
		
	
	}
	else
	{
		
	}
	
}