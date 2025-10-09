/*
 * ADC_program.c
 *
 * Created: 10/9/2025 6:13:03 PM
 *  Author: loaie
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_register.h"
#include "ADC_interface.h"



/*======================================================
 * Function: ADC_voidInit
 * Purpose : Initialize ADC with chosen reference voltage
 *======================================================*/
void ADC_voidInit(ADC_refVolt_t copy_tRefVolt)
{
    /* 1. Set reference voltage (REFS1:REFS0 bits in ADMUX) */
    switch (copy_tRefVolt)
    {
        case ADC_REFERENCE_AREF:
            CLR_BIT(ADMUX, REFS0);
            CLR_BIT(ADMUX, REFS1);
            break;

        case ADC_REFERENCE_AVCC:
            SET_BIT(ADMUX, REFS0);
            CLR_BIT(ADMUX, REFS1);
            break;

        case ADC_REFERENCE_INTRNAL:
            SET_BIT(ADMUX, REFS0);
            SET_BIT(ADMUX, REFS1);
            break;
    }

    /* 2. Set result adjustment to right (ADLAR = 0) */
    CLR_BIT(ADMUX, ADLAR);

    /* 3. Enable ADC (ADEN = 1) */
    SET_BIT(ADCSRA, ADEN);

    /* 4. Set ADC Prescaler to 128 ? ADC frequency = 125 kHz (for 16 MHz system clock)
          ADPS2:0 = 111  */
    SET_BIT(ADCSRA, ADPS0);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS2);
}


/*======================================================
 * Function: ADC_voidGetDigitalValue
 * Purpose : Get ADC digital value for a specific channel
 *======================================================*/
void ADC_voidGetDigitalValue(ADC_ChannelId_t copy_tChannelId, u16* pu16DigitalVal)
{
    /* 1. Clear old channel bits and select the new one */
    ADMUX &= 0b11100000;                     // Clear MUX bits
    ADMUX |= (copy_tChannelId & 0b00011111); // Set new channel

    /* 2. Start conversion (ADSC = 1) */
    SET_BIT(ADCSRA, ADSC);

    /* 3. Wait until conversion complete (ADIF = 1) */
    while (GET_BIT(ADCSRA, ADIF) == 0);

    /* 4. Clear interrupt flag by writing 1 to ADIF */
    SET_BIT(ADCSRA, ADIF);

    /* 5. Read the result (must read ADCL first, then ADCH) */
    u16 result = ADCL;
    result |= ((u16)ADCH << 8);

    /* 6. Return the result */
    *pu16DigitalVal = result;
}