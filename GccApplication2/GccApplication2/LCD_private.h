/*
 * LCD_private.h
 *
 * Created: 9/18/2025 7:59:56 PM
 *  Author: loaie
 */ 

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/* -------- Internal Helpers (only used inside LCD_program.c) -------- */
/* Don’t declare them static here, just in the .c file */
void PRV_voidEnableWriteTrigger(void);
void LCD_voidSendHalfCommand(u8 copy_u8HalfCmd);

/* -------- LCD Modes -------- */
#define LCD_EIGHT_BIT_MODE     0
#define LCD_FOUR_BIT_MODE      1

#endif /* LCD_PRIVATE_H_ */
