/*
 * LCD_interface.h
 *
 * Created: 9/18/2025 7:58:08 PM
 *  Author: loaie
 */ 

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "STD_TYPES.h"   // ? Needed for u8, u32 types

/* Macros for Shift Direction */
#define	LCD_SHIFT_LEFT			    0
#define	LCD_SHIFT_RIGHT			    1

/* Macros for Line Number */
#define	LCD_LINE_ONE			    0
#define	LCD_LINE_TWO			    1

/* Functions Prototypes */
void LCD_voidInit(void);
void LCD_voidDisplayChar(u8 copy_u8Char);
void LCD_voidDisplayString(u8* copy_u8String);
void LCD_voidDisplayNumber(u32 copy_u32Number);
void LCD_voidSendCommand(u8 copy_u8Command);
void LCD_voidClear(void);
void LCD_voidShift(u8 copy_u8ShiftDirection);
void LCD_voidGoToSpecificPosition(u8 copy_u8LineNumber, u8 copy_u8Position);

#endif /* LCD_INTERFACE_H_ */
