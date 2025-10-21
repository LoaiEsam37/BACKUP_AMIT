/*
 * PWM0_program.c
 *
 * Created: 10/21/2025
 * Author : Loaie
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
#include "PWM0_register.h"
#include "PWM0_interface.h"
#include "PWM0_config.h"

/**
 * @brief Initialize Timer0 for Fast PWM (Non-Inverting Mode)
 */
void PWM0_voidInit(void)
{
    /* 1. Set OC0 (PB3) as output pin */
    SET_BIT(DDRB, DIO_PIN3);

    /* 2. Select Fast PWM mode (WGM00 = 1, WGM01 = 1) */
    SET_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

    /* 3. Select Non-inverting mode (COM01 = 1, COM00 = 0) */
    SET_BIT(TCCR0, COM01);
    CLR_BIT(TCCR0, COM00);

    /* 4. Load default duty cycle */
    PWM0_voidSetDutyCycle(PWM0_DEFAULT_DUTY);
}

/**
 * @brief Start PWM signal generation (apply prescaler)
 */
void PWM0_voidStart(void)
{
#if PWM0_PRESCALER == 1
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
#elif PWM0_PRESCALER == 8
    CLR_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
#elif PWM0_PRESCALER == 64
    SET_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
#elif PWM0_PRESCALER == 256
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
#elif PWM0_PRESCALER == 1024
    SET_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    SET_BIT(TCCR0, CS02);
#endif
}

/**
 * @brief Stop PWM signal (turn off clock source)
 */
void PWM0_voidStop(void)
{
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
}

/**
 * @brief Set duty cycle in percentage (0–100%)
 */
void PWM0_voidSetDutyCycle(u8 copy_u8DutyCycle)
{
    if (copy_u8DutyCycle > 100)
        copy_u8DutyCycle = 100;

    OCR0 = (u8)((copy_u8DutyCycle / 100.0) * 255);
}
