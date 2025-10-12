/*
 * LM35_Program.c
 *
 * Created: 10/12/2025 8:22:28 PM
 *  Author: loaie
 */ 

#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "ADC_interface.h"
#include "LM35_interface.h"

void LM35_voidInit(void)
{
	DIO_voidSetPinDirection(LM35_PORT, LM35_PIN, DIO_PIN_INPUT);
	ADC_voidInit(ADC_REFERENCE_INTERNAL);
}

void LM35_voidGetTemp(u16* copy_pu16TempC)
{
	u16 local_u16DigitalValue = 0;
	u32 local_u16AnalogMilliVolt = 0;

	ADC_voidGetDigitalValue(LM35_ADC_CHANNEL, &local_u16DigitalValue);

	local_u16AnalogMilliVolt = (local_u16DigitalValue * 2560UL) / 1024UL;
	*copy_pu16TempC = local_u16AnalogMilliVolt / 10UL;
}