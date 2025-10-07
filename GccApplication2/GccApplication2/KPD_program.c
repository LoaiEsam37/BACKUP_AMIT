/*
 * Keypad_program.c
 *
 * Created: 9/28/2025 7:16:03 PM
 *  Author: loaie
 */ 

#define F_CPU 16000000UL
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"
#include <util/delay.h>

void KPD_voidInit(void)
{
	/* Set column pins as OUTPUT*/
	DIO_voidSetPinDirection(KPD_COL_PORT, KPD_COL0_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL_PORT, KPD_COL1_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COL_PORT, KPD_COL2_PIN, DIO_PIN_OUTPUT);

	DIO_voidSetPinValue(KPD_COL_PORT, KPD_COL0_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(KPD_COL_PORT, KPD_COL1_PIN, DIO_PIN_HIGH);
	DIO_voidSetPinValue(KPD_COL_PORT, KPD_COL2_PIN, DIO_PIN_HIGH);

	/* Set row pins as INPUT with internal pull-up */
	DIO_voidSetPinDirection(KPD_ROW_PORT, KPD_ROW0_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW_PORT, KPD_ROW1_PIN, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROW_PORT, KPD_ROW2_PIN, DIO_PIN_INPUT);

	DIO_voidActivePinInternalPUR(KPD_ROW_PORT, KPD_ROW0_PIN);
	DIO_voidActivePinInternalPUR(KPD_ROW_PORT, KPD_ROW1_PIN);
	DIO_voidActivePinInternalPUR(KPD_ROW_PORT, KPD_ROW2_PIN);
}


void KPD_voidGetValue(u8* pu8PressedVal)
{
	u8 row, col, pinVal;
	*pu8PressedVal = KPD_NO_PRESSED_KEY;

	static u8 KPD_Keys[3][3] = KPD_KEYS;
	static u8 local_u8RowPins[3] = { KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN };
	static u8 local_u8ColPins[3] = { KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN };

	for (col = 0; col < 3; col++)
	{
		DIO_voidSetPinValue(KPD_COL_PORT, local_u8ColPins[col], DIO_PIN_LOW);
		for (row = 0; row < 3; row++)
		{
			DIO_voidGetPinValue(KPD_ROW_PORT, local_u8RowPins[row], &pinVal);

			if (pinVal == DIO_PIN_LOW)
			{
				*pu8PressedVal = KPD_Keys[row][col];

				while (pinVal == DIO_PIN_LOW)
				{
					DIO_voidGetPinValue(KPD_ROW_PORT, local_u8RowPins[row], &pinVal);
				}
				_delay_ms(10);

				DIO_voidSetPinValue(KPD_COL_PORT, local_u8ColPins[col], DIO_PIN_HIGH);
				return;
			}
		}

		DIO_voidSetPinValue(KPD_COL_PORT, local_u8ColPins[col], DIO_PIN_HIGH);
	}
}
