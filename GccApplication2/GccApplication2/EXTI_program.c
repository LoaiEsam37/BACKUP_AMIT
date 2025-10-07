/*
 * EXTI_program.c
 *
 * Created: 10/2/2025 8:52:24 PM
 * Author: Loaie
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"


static void (*EXTI_pvInt0Func)(void) = NULL;
static void (*EXTI_pvInt1Func)(void) = NULL;
static void (*EXTI_pvInt2Func)(void) = NULL;

void EXTI_voidInit(EXTI_IntSrc_t copy_tIntSrc, EXTI_intSenseCtrl_t copy_tIntSenseCtrl)
{
	switch(copy_tIntSrc)
	{
		case EXTI_INT0:
			switch(copy_tIntSenseCtrl)
			{
				case EXTI_LOW_LEVEL:	CLR_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); break;
				case EXTI_ANY_CHANGE:	SET_BIT(MCUCR, ISC00); CLR_BIT(MCUCR, ISC01); break;
				case EXTI_FALLING_EDGE:	CLR_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); break;
				case EXTI_RISING_EDGE:	SET_BIT(MCUCR, ISC00); SET_BIT(MCUCR, ISC01); break;
			}
			break;

		case EXTI_INT1:
			switch(copy_tIntSenseCtrl)
			{
				case EXTI_LOW_LEVEL:	CLR_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); break;
				case EXTI_ANY_CHANGE:	SET_BIT(MCUCR, ISC10); CLR_BIT(MCUCR, ISC11); break;
				case EXTI_FALLING_EDGE:	CLR_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); break;
				case EXTI_RISING_EDGE:	SET_BIT(MCUCR, ISC10); SET_BIT(MCUCR, ISC11); break;
			}
			break;

		case EXTI_INT2:
			switch(copy_tIntSenseCtrl)
			{
				case EXTI_FALLING_EDGE: CLR_BIT(MCUCSR, ISC2); break;
				case EXTI_RISING_EDGE:  SET_BIT(MCUCSR, ISC2); break;
				default: break;
			}
			break;
	}
}


void EXTI_voidEnable(EXTI_IntSrc_t copy_tIntSrc, EXTI_intSenseCtrl_t copy_Sense)
{
	EXTI_voidInit(copy_tIntSrc, copy_Sense);

	switch(copy_tIntSrc)
	{
		case EXTI_INT0: SET_BIT(GICR, INT0); break;
		case EXTI_INT1: SET_BIT(GICR, INT1); break;
		case EXTI_INT2: SET_BIT(GICR, INT2); break;
	}
}


void EXTI_voidDisable(EXTI_IntSrc_t copy_tIntSrc)
{
	switch(copy_tIntSrc)
	{
		case EXTI_INT0: CLR_BIT(GICR, INT0); break;
		case EXTI_INT1: CLR_BIT(GICR, INT1); break;
		case EXTI_INT2: CLR_BIT(GICR, INT2); break;
	}
}

void EXTI_voidSetCallback(EXTI_IntSrc_t copy_tIntSrc, void (*copy_pvCallback)(void))
{
	if (copy_pvCallback != NULL)
	{
		switch(copy_tIntSrc)
		{
			case EXTI_INT0: EXTI_pvInt0Func = copy_pvCallback; break;
			case EXTI_INT1: EXTI_pvInt1Func = copy_pvCallback; break;
			case EXTI_INT2: EXTI_pvInt2Func = copy_pvCallback; break;
		}
	}
	else
	{
		// return Error State
	}
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	EXTI_pvInt0Func();
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	EXTI_pvInt1Func();
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	EXTI_pvInt2Func();

}