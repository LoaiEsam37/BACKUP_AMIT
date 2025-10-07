/*
 * GI_register.h
 *
 * Created: 10/2/2025 8:21:45 PM
 *  Author: loaie
 */ 


#ifndef GI_REGISTER_H_
#define GI_REGISTER_H_

#define SREG   (*((volatile u8*)0x5F))  // Status Register

#define SREG_I   7   // Global Interrupt Enable
#define SREG_T   6   // Bit Copy Storage
#define SREG_H   5   // Half Carry Flag
#define SREG_S   4   // Sign Flag
#define SREG_V   3   // Two’s Complement Overflow Flag
#define SREG_N   2   // Negative Flag
#define SREG_Z   1   // Zero Flag
#define SREG_C   0   // Carry Flag

#endif /* GI_REGISTER_H_ */