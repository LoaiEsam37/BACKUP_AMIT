/*
 * GI_program.c
 *
 * Created: 10/2/2025 8:21:04 PM
 *  Author: loaie
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GI_register.h"
#include "GI_interface.h"

void GI_voidEnable(void)
{
	SET_BIT(SREG, SREG_I);
}

void GI_voidDisable(void)
{
	CLR_BIT(SREG, SREG_I);
}