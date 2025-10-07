#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#include "STD_TYPES.h"

/* ---------------- Registers ---------------- */
#define MCUCR   (*((volatile u8*)0x55))
#define MCUCSR  (*((volatile u8*)0x54))
#define GICR    (*((volatile u8*)0x5B))
#define GIFR    (*((volatile u8*)0x5A))

/* ---------------- MCUCR bits ---------------- */
#define ISC00   0   // Interrupt Sense Control 0 bit 0
#define ISC01   1   // Interrupt Sense Control 0 bit 1
#define ISC10   2   // Interrupt Sense Control 1 bit 0
#define ISC11   3   // Interrupt Sense Control 1 bit 1

/* ---------------- MCUCSR bits ---------------- */
#define ISC2    6   // Interrupt Sense Control 2

/* ---------------- GICR bits ---------------- */
#define INT2    5   // External Interrupt Request 2 Enable
#define INT0    6   // External Interrupt Request 0 Enable
#define INT1    7   // External Interrupt Request 1 Enable

/* ---------------- GIFR bits (optional, for flags) ---------------- */
#define INTF2   5
#define INTF0   6
#define INTF1   7

#endif /* EXTI_REGISTER_H_ */
