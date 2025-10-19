/*
 * TMR0_interface.h
 *
 * Created: 10/16/2025 6:45:20 PM
 *  Author: loaie
 */ 


#ifndef TMR0_INTERFACE_H_
#define TMR0_INTERFACE_H_

void TMR0_voidInit(void);
void TMR0_voidStart(void);
void TMR0_voidStop(void);
void TMR0_voidSetCallbackOVF(void(*pToFuncCallBack)(void));
void TMR0_voidSetCallbackCTC(void (*pToFuncCallBack)(void));
void TMR0_voidSetDelay_msUsingCTC(u16 copy_u16Delay_ms);


#endif /* TMR0_INTERFACE_H_ */
