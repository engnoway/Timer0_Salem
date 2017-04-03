/*
 * Timer_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer0_voidInit();

void Timer1_voidInit();

void Timer0_voidWriteReg(u8 Copy_U8WriteVal);

void Timer0_voidReadReg(u8 *Copy_U8PtrToVal);

void Timer1_voidWriteReg(u16 Copy_U16WriteVal);

void Timer1_voidReadReg(u16 *Copy_U16PtrToVal);

void SetTIM0_OVF_ISR(void (*Copy_voidPtrToFun)(void));

void SetTIM1_OVF_ISR(void (*Copy_voidPtrToFun)(void));

void Timer1_Stop(void);

void Timer0_Stop(void);



#endif /* TIMER_INTERFACE_H_ */
