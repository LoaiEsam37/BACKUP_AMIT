/*
 * TMR0_program.c
 *
 * Created: 10/16/2025 6:45:05 PM
 * Author: Loaie
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPT_interface.h"

#include "TMR0_register.h"
#include "TMR0_private.h"
#include "TMR0_interface.h"
#include "TMR0_config.h"

static void (*PRV_pToFuncCallBack)(void) = NULL;

/**
 * @brief Initialize Timer0 in Normal (Overflow) mode
 */
void TMR0_voidInit(void)
{
    /* Select Normal Mode: WGM01 = 0, WGM00 = 0 */
    CLR_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);

    /* Set Preload Value */
    TCNT0 = TMR0_PRELOAD_VALUE;

    /* Enable Overflow Interrupt */
    SET_BIT(TIMSK, TOIE0);
}

/**
 * @brief Start Timer0 with prescaler 64
 */
void TMR0_voidStart(void)
{
    /* Select Prescaler = 64 ? CS02:CS00 = 0b011 */
    SET_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
}

/**
 * @brief Stop Timer0 (no clock source)
 */
void TMR0_voidStop(void)
{
    /* Clear CS02:CS00 bits ? Timer stopped */
    CLR_BIT(TCCR0, CS00);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);
}

/**
 * @brief Set callback for Timer0 overflow interrupt
 *
 * @param pToFuncCallBack Pointer to callback function
 */
void TMR0_voidSetCallbackOVF(void (*pToFuncCallBack)(void))
{
    if (pToFuncCallBack != NULL)
    {
        PRV_pToFuncCallBack = pToFuncCallBack;
    }
    else
    {
        // Optional: handle null pointer (could add error flag)
    }
}

/**
 * @brief ISR for Timer0 Overflow (vector 11 in datasheet)
 */
ISR(TIMER0_OVF_vect)
{
    static u16 local_u16Counter = 0;
    local_u16Counter++;

    if (local_u16Counter >= TMR0_OVERFLOW_COUNTER)
    {
        /* Reload the timer with preload value */
        TCNT0 = TMR0_PRELOAD_VALUE;

        /* Call user callback if set */
        if (PRV_pToFuncCallBack != NULL)
        {
            PRV_pToFuncCallBack();
        }

        /* Reset overflow counter */
        local_u16Counter = 0;
    }
}
