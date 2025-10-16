/*
 * TMR1_Interface.h
 *
 * Created: 10/16/2025 8:28:29 PM
 *  Author: loaie
 */ 


#ifndef TMR1_INTERFACE_H_
#define TMR1_INTERFACE_H_

void TMR1_voidInit(void);
void TMR1_voidStart(void);
void TMR1_voidStop(void);
void TMR1_voidSetCallbackOVF(void(*pToFuncCallBack)(void));

#endif /* TMR1_INTERFACE_H_ */