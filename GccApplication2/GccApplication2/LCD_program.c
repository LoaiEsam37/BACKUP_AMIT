/*
 * LCD_program.c
 *
 * Created: 9/18/2025 8:00:13 PM
 *  Author: loaie
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

/* ================== Private helpers ================== */
void PRV_voidEnableWriteTrigger(void);
void LCD_voidSendHalfCommand(u8 copy_u8HalfCmd);

/* ===================================================== */
void LCD_voidInit(void)
{
	// Control pins
	DIO_voidSetPinDirection(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT, LCD_E_PIN, DIO_PIN_OUTPUT);

#if LCD_MODE == LCD_EIGHT_BIT_MODE

	DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);

	_delay_ms(40);

	LCD_voidSendCommand(0x38); // Function set: 8-bit, 2 lines, 5x8 dots
	_delay_us(50);

	LCD_voidSendCommand(0x0C); // Display ON, cursor OFF
	_delay_us(50);

	LCD_voidSendCommand(0x01); // Clear display
	_delay_ms(2);

	LCD_voidSendCommand(0x06); // Entry mode set
	_delay_us(50);

#elif LCD_MODE == LCD_FOUR_BIT_MODE

	// Data pins
	DIO_voidSetPinDirection(LCD_D4_PORT, LCD_D4, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D5_PORT, LCD_D5, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D6_PORT, LCD_D6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_D7_PORT, LCD_D7, DIO_PIN_OUTPUT);

	_delay_ms(40);

	// --- 4-bit init sequence (real LCDs require this) ---
	LCD_voidSendHalfCommand(0x03);
	_delay_ms(5);
	LCD_voidSendHalfCommand(0x03);
	_delay_us(150);
	LCD_voidSendHalfCommand(0x03);
	_delay_us(150);

	LCD_voidSendHalfCommand(0x02); // Enter 4-bit mode
	_delay_us(150);

	// Function set
	LCD_voidSendCommand(0x28); // 4-bit, 2 lines, 5x8 dots
	_delay_us(50);

	// Display control
	LCD_voidSendCommand(0x0C); // Display ON, cursor OFF
	_delay_us(50);

	// Clear display
	LCD_voidSendCommand(0x01);
	_delay_ms(2);

	// Entry mode
	LCD_voidSendCommand(0x06); // Increment cursor
	_delay_us(50);

#endif
}

/* ===================================================== */
void LCD_voidDisplayChar(u8 copy_u8Data)
{
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_HIGH);

#if LCD_MODE == LCD_EIGHT_BIT_MODE
	DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Data);
	PRV_voidEnableWriteTrigger();

#elif LCD_MODE == LCD_FOUR_BIT_MODE
	LCD_voidSendHalfCommand(copy_u8Data >> 4); // High nibble
	LCD_voidSendHalfCommand(copy_u8Data & 0x0F); // Low nibble
#endif
}

/* ===================================================== */
void LCD_voidDisplayString(u8* pu8String)
{
	while (*pu8String != '\0')
	{
		LCD_voidDisplayChar(*pu8String);
		pu8String++;
	}
}

/* ===================================================== */
void LCD_voidSendCommand(u8 copy_u8Command)
{
	DIO_voidSetPinValue(LCD_RS_PORT, LCD_RS_PIN, DIO_PIN_LOW);

#if LCD_MODE == LCD_EIGHT_BIT_MODE
	DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Command);
	PRV_voidEnableWriteTrigger();

#elif LCD_MODE == LCD_FOUR_BIT_MODE
	LCD_voidSendHalfCommand(copy_u8Command >> 4);   // High nibble
	LCD_voidSendHalfCommand(copy_u8Command & 0x0F); // Low nibble
#endif
}

/* ===================================================== */
void LCD_voidClear(void)
{
	LCD_voidSendCommand(0x01);
	_delay_ms(2);
}

/* ===================================================== */
void LCD_voidShift(u8 copy_u8ShifttingDiirection)
{
	switch (copy_u8ShifttingDiirection)
	{
		case LCD_SHIFT_LEFT:  LCD_voidSendCommand(0x18); break;
		case LCD_SHIFT_RIGHT: LCD_voidSendCommand(0x1C); break;
	}
	_delay_us(50);
}

/* ===================================================== */
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position)
{
	switch(copy_u8LineNumber)
	{
		case LCD_LINE_ONE: LCD_voidSendCommand(0x80 + copy_u8Position); break;
		case LCD_LINE_TWO: LCD_voidSendCommand(0xC0 + copy_u8Position); break;
	}
	_delay_us(50);
}

/* ===================================================== */
void LCD_voidDisplayNumber(u32 copy_u32Number)
{
	u32 local_u32ReversedNumber = 1;

	if (copy_u32Number == 0)
	{
		LCD_voidDisplayChar('0');
	}
	else
	{
		while (copy_u32Number > 0)
		{
			local_u32ReversedNumber = (local_u32ReversedNumber * 10) + (copy_u32Number % 10);
			copy_u32Number /= 10;
		}

		while (local_u32ReversedNumber > 1)
		{
			u8 digit = local_u32ReversedNumber % 10;
			LCD_voidDisplayChar(digit + '0');
			local_u32ReversedNumber /= 10;
		}
	}
}

/* ===================================================== */
/* ================== Private functions ================= */
void PRV_voidEnableWriteTrigger(void)
{
	DIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_HIGH);
	_delay_us(1);   // ? 450ns
	DIO_voidSetPinValue(LCD_E_PORT, LCD_E_PIN, DIO_PIN_LOW);
	_delay_us(50);  // allow command to settle
}

void LCD_voidSendHalfCommand(u8 copy_u8HalfCmd)
{
	// RS already set outside
	DIO_voidSetPinValue(LCD_D4_PORT, LCD_D4, GET_BIT(copy_u8HalfCmd, 0));
	DIO_voidSetPinValue(LCD_D5_PORT, LCD_D5, GET_BIT(copy_u8HalfCmd, 1));
	DIO_voidSetPinValue(LCD_D6_PORT, LCD_D6, GET_BIT(copy_u8HalfCmd, 2));
	DIO_voidSetPinValue(LCD_D7_PORT, LCD_D7, GET_BIT(copy_u8HalfCmd, 3));

	PRV_voidEnableWriteTrigger();
}
