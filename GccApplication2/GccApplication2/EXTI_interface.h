/*
 * EXTI_interface.h
 *
 * Created: 10/2/2025 8:52:44 PM
 *  Author: loaie
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum {
	EXTI_INT0,
	EXTI_INT1,
	EXTI_INT2
} EXTI_IntSrc_t;

typedef enum {
	EXTI_LOW_LEVEL,
	EXTI_ANY_CHANGE,
	EXTI_FALLING_EDGE,
	EXTI_RISING_EDGE
} EXTI_intSenseCtrl_t;

void EXTI_voidInit(EXTI_IntSrc_t copy_tIntSrc, EXTI_intSenseCtrl_t copy_tIntSenseCtrl);
void EXTI_voidEnable(EXTI_IntSrc_t copy_tIntSrc, EXTI_intSenseCtrl_t copy_Sense);
void EXTI_voidDisable(EXTI_IntSrc_t copy_tIntSrc);
void EXTI_voidSetCallback(EXTI_IntSrc_t copy_tIntSrc, void (*copy_pvCallback)(void));


#endif /* EXTI_INTERFACE_H_ */