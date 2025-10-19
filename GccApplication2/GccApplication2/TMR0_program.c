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

static void (*PRV_pToFuncCallBack_OVF)(void) = NULL;
static void (*PRV_pToFuncCallBack_CTC)(void) = NULL;

/**
 * @brief Initialize Timer0 based on selected mode (Normal or CTC)
 */
void TMR0_voidInit(void)
{
#if TMR0_MODE == TMR0_NORMAL_MODE
    /* Select Normal Mode: WGM01 = 0, WGM00 = 0 */
    CLR_BIT(TCCR0, WGM00);
    CLR_BIT(TCCR0, WGM01);

    /* Set Preload Value */
    TCNT0 = TMR0_PRELOAD_VALUE;

    /* Enable Overflow Interrupt */
    SET_BIT(TIMSK, TOIE0);

#elif TMR0_MODE == TMR0_CTC_MODE
    /* Select CTC Mode: WGM01 = 1, WGM00 = 0 */
    CLR_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

    /* Load Compare Value */
    OCR0 = TMR0_COMPARE_MATCH_VALUE;

    /* Enable Output Compare Match Interrupt */
    SET_BIT(TIMSK, OCIE0);

#endif
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
 */
void TMR0_voidSetCallbackOVF(void (*pToFuncCallBack)(void))
{
    if (pToFuncCallBack != NULL)
    {
        PRV_pToFuncCallBack_OVF = pToFuncCallBack;
    }
}

/**
 * @brief Set callback for Timer0 compare match interrupt
 */
void TMR0_voidSetCallbackCTC(void (*pToFuncCallBack)(void))
{
    if (pToFuncCallBack != NULL)
    {
        PRV_pToFuncCallBack_CTC = pToFuncCallBack;
    }
}


void TMR0_voidSetDelay_msUsingCTC(u16 copy_u16Delay_ms)
{
	/* 1. Configure Timer0 in CTC mode */
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);   // WGM01 = 1 ? CTC mode

	/* 2. Set compare match value */
	OCR0 = 250;   // gives 1ms tick at F_CPU=16MHz, prescaler=64

	/* 3. Start timer with prescaler 64 */
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

	/* 4. Wait for delay_ms matches */
	for (u16 i = 0; i < copy_u16Delay_ms; i++)
	{
		/* Wait until OCF0 flag is set (compare match occurred) */
		while (GET_BIT(TIFR, OCF0) == 0);

		/* Clear flag manually by writing 1 */
		SET_BIT(TIFR, OCF0);
	}

	/* 5. Stop timer */
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
}

/**
 * @brief ISR for Timer0 Overflow
 */
ISR(TIMER0_OVF_vect)
{
#if TMR0_MODE == TMR0_NORMAL_MODE
    static u16 local_u16Counter = 0;
    local_u16Counter++;

    if (local_u16Counter >= TMR0_OVERFLOW_COUNTER)
    {
        TCNT0 = TMR0_PRELOAD_VALUE;

        if (PRV_pToFuncCallBack_OVF != NULL)
        {
            PRV_pToFuncCallBack_OVF();
        }

        local_u16Counter = 0;
    }
#endif
}

/**
 * @brief ISR for Timer0 Compare Match (CTC)
 */
ISR(TIMER0_COMP_vect)
{
#if TMR0_MODE == TMR0_CTC_MODE
    static u16 local_u16Counter = 0;
    local_u16Counter++;

    if (local_u16Counter >= TMR0_CTC_COUNTER)
    {
		if (PRV_pToFuncCallBack_CTC != NULL)
		{
			PRV_pToFuncCallBack_CTC();
		}
	    local_u16Counter = 0;
    }
#endif
}