/*
 * DCM_Program.c
 *
 * Created: 11/1/2025 1:02:57 PM
 *  Author: loaie
 */ 

#include "DIO_interface.h"
#include "DCM_interface.h"
#include "DCM_config.h"
#include "PWM0_interface.h"

void DCM_voidInit(u8 copy_u8MotorId)
{
	switch (copy_u8MotorId)
	{
		case DCM_MOTOR_A: 
		DIO_voidSetPinDirection(DCM_MOTOR_A_ENABLE_PORT, DCM_MOTOR_A_ENABLE_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, DIO_PIN_OUTPUT);
		break;
		
		case DCM_MOTOR_B: 
		DIO_voidSetPinDirection(DCM_MOTOR_B_ENABLE_PIN, DCM_MOTOR_B_ENABLE_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, DIO_PIN_OUTPUT);
		break;
	}
}

void DCM_voidOn(u8 copy_u8MotorId, u8 copy_u8MotorDirection)
{
	switch (copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		switch (copy_u8MotorDirection)
		{
			case DCM_CLOCK_WISE:
			DIO_voidSetPinValue(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, DIO_PIN_LOW);
			break;
			
			case DCM_COUNTER_CLOCK_WISE:
			DIO_voidSetPinValue(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, DIO_PIN_HIGH);
			break;
		}
		DIO_voidSetPinValue(DCM_MOTOR_A_ENABLE_PORT, DCM_MOTOR_A_ENABLE_PIN, DIO_PIN_HIGH);
		break;
		 
		case DCM_MOTOR_B:
		switch (copy_u8MotorDirection)
		{
			case DCM_CLOCK_WISE:
			DIO_voidSetPinValue(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, DIO_PIN_LOW);
			break;
			
			case DCM_COUNTER_CLOCK_WISE:
			DIO_voidSetPinValue(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, DIO_PIN_HIGH);
			break;
		}
		DIO_voidSetPinValue(DCM_MOTOR_B_ENABLE_PORT, DCM_MOTOR_B_ENABLE_PIN, DIO_PIN_HIGH);
		break;
	}
}

void DCM_voidOff(u8 copy_u8MotorId)
{
	switch (copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		DIO_voidSetPinValue(DCM_MOTOR_A_ENABLE_PORT, DCM_MOTOR_A_ENABLE_PIN, DIO_PIN_LOW);
		break;
		
		case DCM_MOTOR_B:
		DIO_voidSetPinValue(DCM_MOTOR_B_ENABLE_PORT, DCM_MOTOR_B_ENABLE_PIN, DIO_PIN_LOW);
		break;
	}
}


void DCM_voidInitWithCtrlSpeed(u8 copy_u8MotorId)
{
	switch (copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		PWM0_voidInit();
		DCM_voidInit(DCM_MOTOR_A);
		break;

		case DCM_MOTOR_B:
		PWM0_voidInit();
		DCM_voidInit(DCM_MOTOR_B);
		break;
	}
}

void DCM_voidOnWithCtrlSpeed(u8 copy_u8MotorId, u8 copy_u8MotorDirection, u8 copy_u8MotorSpeed)
{
	switch (copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		switch (copy_u8MotorDirection)
		{
			case DCM_CLOCK_WISE:
			DIO_voidSetPinValue(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, DIO_PIN_LOW);
			break;

			case DCM_COUNTER_CLOCK_WISE:
			DIO_voidSetPinValue(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, DIO_PIN_HIGH);
			break;
		}
		PWM0_voidSetDutyCycle(copy_u8MotorSpeed);
		PWM0_voidStart();
		break;

		case DCM_MOTOR_B:
		switch (copy_u8MotorDirection)
		{
			case DCM_CLOCK_WISE:
			DIO_voidSetPinValue(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, DIO_PIN_HIGH);
			DIO_voidSetPinValue(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, DIO_PIN_LOW);
			break;

			case DCM_COUNTER_CLOCK_WISE:
			DIO_voidSetPinValue(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, DIO_PIN_LOW);
			DIO_voidSetPinValue(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, DIO_PIN_HIGH);
			break;
		}
		PWM0_voidSetDutyCycle(copy_u8MotorSpeed);
		PWM0_voidStart();
		break;
	}
}

void DCM_voidOffWithCtrlSpeed(u8 copy_u8MotorId)
{
	switch (copy_u8MotorId)
	{
		case DCM_MOTOR_A:
		PWM0_voidStop();
		break;

		case DCM_MOTOR_B:
		PWM0_voidStop();
		break;
	}
}