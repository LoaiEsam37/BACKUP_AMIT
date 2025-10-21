/*
 * PWM0_register.h
 *
 * Created: 10/21/2025 8:26:25 PM
 *  Author: loaie
 */ 


#ifndef PWM0_REGISTER_H_
#define PWM0_REGISTER_H_

// Timer/Counter Control Register
#define TCCR0   (*(volatile u8*)0x53)

// TCCR0 Bits
#define FOC0    7   // Force Output Compare
#define WGM00   6   // Waveform Generation Mode bit 0
#define COM01   5   // Compare Match Output Mode bit 1
#define COM00   4   // Compare Match Output Mode bit 0
#define WGM01   3   // Waveform Generation Mode bit 1
#define CS02    2   // Clock Select bit 2
#define CS01    1   // Clock Select bit 1
#define CS00    0   // Clock Select bit 0

// Timer/Counter Register
#define TCNT0   (*(volatile u8*)0x52)

// Output Compare Register
#define OCR0    (*(volatile u8*)0x5C)

// Timer/Counter Interrupt Mask Register
#define TIMSK   (*(volatile u8*)0x59)

// TIMSK Bits (Timer0-related)
#define OCIE0   1   // Output Compare Match Interrupt Enable
#define TOIE0   0   // Overflow Interrupt Enable

// Timer/Counter Interrupt Flag Register
#define TIFR    (*(volatile u8*)0x58)

// TIFR Bits (Timer0-related)
#define OCF0    1   // Output Compare Flag
#define TOV0    0   // Overflow Flag

#endif /* PWM0_REGISTER_H_ */