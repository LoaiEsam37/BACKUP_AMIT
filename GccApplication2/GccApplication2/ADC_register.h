/*
 * ADC_register.h
 *
 * Created: 10/9/2025 6:13:34 PM
 *  Author: loaie
 */ 


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

/* ==============================
   ADC Register Definitions
   For ATmega32
   ============================== */

#define ADMUX   (*(volatile u8*)0x27)   // ADC Multiplexer Selection Register
#define ADCSRA  (*(volatile u8*)0x26)   // ADC Control and Status Register A
#define ADCH    (*(volatile u8*)0x25)   // ADC High Register
#define ADCL    (*(volatile u8*)0x24)   // ADC Low Register
#define SFIOR   (*(volatile u8*)0x50)   // Special Function IO Register
#define ADC		(*(volatile u16*)0x24)  // ADC Data Register (ADCL + ADCH)

/* ==============================
   Bit Definitions for ADMUX
   ============================== */
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5   // ADC Left Adjust Result
#define REFS0   6   // Reference Selection Bit 0
#define REFS1   7   // Reference Selection Bit 1

/* ==============================
   Bit Definitions for ADCSRA
   ============================== */
#define ADPS0   0   // ADC Prescaler Select Bit 0
#define ADPS1   1   // ADC Prescaler Select Bit 1
#define ADPS2   2   // ADC Prescaler Select Bit 2
#define ADIE    3   // ADC Interrupt Enable
#define ADIF    4   // ADC Interrupt Flag
#define ADATE   5   // ADC Auto Trigger Enable
#define ADSC    6   // ADC Start Conversion
#define ADEN    7   // ADC Enable

/* ==============================
   Bit Definitions for SFIOR
   ============================== */
#define ADTS0   5   // ADC Auto Trigger Source Bit 0
#define ADTS1   6   // ADC Auto Trigger Source Bit 1
#define ADTS2   7   // ADC Auto Trigger Source Bit 2

#endif /* ADC_REGISTER_H_ */
