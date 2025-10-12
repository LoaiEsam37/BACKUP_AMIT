/*
 * LM35_interface.h
 *
 * Created: 10/12/2025 8:22:44 PM
 *  Author: loaie
 */ 


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#define LM35_PORT				DIO_PORTA
#define LM35_PIN				DIO_PIN0
#define LM35_ADC_CHANNEL		ADC_CHANNEL_0 

void LM35_voidInit(void);
void LM35_voidGetTemp(u16* copy_pu16TempC);

#endif /* LM35_INTERFACE_H_ */