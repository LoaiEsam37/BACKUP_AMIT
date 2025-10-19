/*
 * TMR1_program.c
 *
 * Created: 10/16/2025 8:28:15 PM
 * Author: Loaie
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "INTERRUPT_interface.h"

#include "TMR1_register.h"
#include "TMR1_private.h"
#include "TMR1_interface.h"
#include "TMR1_config.h"

static void (*PRV_pToFuncCallBack_OVF)(void) = NULL;
static void (*PRV_pToFuncCallBack_CTC)(void) = NULL;

void TMR1_voidInit(void)
{
#if TMR1_MODE == TMR1_NORMAL_MODE
    // Normal mode: WGM13:0 = 0000
    CLR_BIT(TCCR1A, WGM10);
    CLR_BIT(TCCR1A, WGM11);
    CLR_BIT(TCCR1B, WGM12);
    CLR_BIT(TCCR1B, WGM13);

    TCNT1 = TMR1_PRELOAD_VALUE;
    SET_BIT(TIMSK, TOIE1); // Enable overflow interrupt

#elif TMR1_MODE == TMR1_CTC_MODE
    // CTC mode: WGM13:0 = 0100 (TOP = OCR1A)
    CLR_BIT(TCCR1A, WGM10);
    CLR_BIT(TCCR1A, WGM11);
    SET_BIT(TCCR1B, WGM12);
    CLR_BIT(TCCR1B, WGM13);

    OCR1A = TMR1_COMPARE_MATCH_VALUE;
    SET_BIT(TIMSK, OCIE1A); // Enable CTC interrupt
#endif
}

void TMR1_voidStart(void)
{
    // Prescaler = 64 ? CS12:0 = 011
    SET_BIT(TCCR1B, CS10);
    SET_BIT(TCCR1B, CS11);
    CLR_BIT(TCCR1B, CS12);
}

void TMR1_voidStop(void)
{
    CLR_BIT(TCCR1B, CS10);
    CLR_BIT(TCCR1B, CS11);
    CLR_BIT(TCCR1B, CS12);
}

void TMR1_voidSetCallbackOVF(void (*pToFuncCallBack)(void))
{
    if (pToFuncCallBack != NULL)
    {
        PRV_pToFuncCallBack_OVF = pToFuncCallBack;
    }
}

void TMR1_voidSetCallbackCTC(void (*pToFuncCallBack)(void))
{
    if (pToFuncCallBack != NULL)
    {
        PRV_pToFuncCallBack_CTC = pToFuncCallBack;
    }
}

/*---------------------- ISRs ----------------------*/

ISR(TIMER1_OVF_vect)
{
#if TMR1_MODE == TMR1_NORMAL_MODE
    static u16 local_u16Counter = 0;
    local_u16Counter++;

    if (local_u16Counter >= TMR1_OVERFLOW_COUNTER)
    {
        TCNT1 = TMR1_PRELOAD_VALUE;

        if (PRV_pToFuncCallBack_OVF != NULL)
        {
            PRV_pToFuncCallBack_OVF();
        }

        local_u16Counter = 0;
    }
#endif
}

ISR(TIMER1_COMPA_vect)
{
#if TMR1_MODE == TMR1_CTC_MODE
    static u16 local_u16Counter = 0;
    local_u16Counter++;

    if (local_u16Counter >= TMR1_CTC_COUNTER)
    {
        if (PRV_pToFuncCallBack_CTC != NULL)
        {
            PRV_pToFuncCallBack_CTC();
        }

        local_u16Counter = 0;
    }
#endif
}
