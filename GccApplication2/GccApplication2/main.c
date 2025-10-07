/*
 * DIO.c
 *
 * Created: 9/9/2025 6:41:20 PM
 * Author : loaie
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>


#include "STD_TYPES.h"


#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"


#include "LCD_interface.h"
#include "LED_interface.h"
#include "SWITCH_interface.h"
#include "KPD_interface.h"

void INT0_callBack(void)
{
	LED_voidToggle(DIO_PORTB, DIO_PIN3);
}


int main(void)
{
    DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT); //INT0
	
	
	LED_voidInit(DIO_PORTB, DIO_PIN3, LED_FORWARD_CONNECTION);    

	GI_voidEnable();

	EXTI_voidEnable(EXTI_INT0, EXTI_RISING_EDGE);

	EXTI_voidSetCallback(EXTI_INT0, &INT0_callBack);

    while (1)
    {
    }
}