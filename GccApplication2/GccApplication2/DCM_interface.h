/*
 * DCM_interface.h
 *
 * Created: 11/1/2025 1:03:09 PM
 *  Author: loaie
 */ 


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

/* Macros for DC motor Id*/
#define DCM_MOTOR_A					0
#define DCM_MOTOR_B					1

/* Macros for DC motor direction*/
#define DCM_CLOCK_WISE				0
#define DCM_COUNTER_CLOCK_WISE		1

void DCM_voidInit(u8 copy_u8MotorId);
void DCM_voidOn(u8 copy_u8MotorId, u8 copy_u8MotorDirection);
void DCM_voidOff(u8 copy_u8MotorId);
void DCM_voidInitWithCtrlSpeed(u8 copy_u8MotorId);
void DCM_voidOnWithCtrlSpeed(u8 copy_u8MotorId, u8 copy_u8MotorDirection, u8 copy_u8MotorSpeed);
void DCM_voidOffWithCtrlSpeed(u8 copy_u8MotorId);


#endif /* DCM_INTERFACE_H_ */