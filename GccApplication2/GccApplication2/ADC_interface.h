/*
 * ADC_interface.h
 *
 * Created: 10/9/2025 6:13:15 PM
 *  Author: loaie
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum
{
	ADC_REFERENCE_AVCC = 0,
	ADC_REFERENCE_AREF,
	ADC_REFERENCE_INTRNAL,
} ADC_refVolt_t;

typedef enum
{
	ADC_CHANNEL_0 = 0,   // PA0
	ADC_CHANNEL_1,       // PA1
	ADC_CHANNEL_2,       // PA2
	ADC_CHANNEL_3,       // PA3
	ADC_CHANNEL_4,       // PA4
	ADC_CHANNEL_5,       // PA5
	ADC_CHANNEL_6,       // PA6
	ADC_CHANNEL_7        // PA7
} ADC_ChannelId_t;

void ADC_voidInit(ADC_refVolt_t copy_tRefVolt);
void ADC_voidGetDigitalValue(ADC_ChannelId_t copy_tChannelId, u16* pu16DigitalVal);

#endif /* ADC_INTERFACE_H_ */