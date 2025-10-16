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

static void (*PRV_pToFuncCallBack)(void) = NULL;

void TMR1_voidInit(void)
{
    CLR_BIT(TCCR1A, WGM10);
    CLR_BIT(TCCR1A, WGM11);
    CLR_BIT(TCCR1B, WGM12);
    CLR_BIT(TCCR1B, WGM13);

    TCNT1 = TMR1_PRELOAD_VALUE;

    SET_BIT(TIMSK, TOIE1);
}

void TMR1_voidStart(void)
{
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
        PRV_pToFuncCallBack = pToFuncCallBack;
    }
}

ISR(TIMER1_OVF_vect)
{
    static u16 local_u16Counter = 0;
    local_u16Counter++;

    if (local_u16Counter >= TMR1_OVERFLOW_COUNTER)
    {
        TCNT1 = TMR1_PRELOAD_VALUE;

        if (PRV_pToFuncCallBack != NULL)
        {
            PRV_pToFuncCallBack();
        }

        local_u16Counter = 0;
    }
}
