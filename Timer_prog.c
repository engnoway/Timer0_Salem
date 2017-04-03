/*
 * Timer_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */
#include "Types.h"
#include "Timer_config.h"
#include "Timer_interface.h"
#include "Timer_private.h"
#include "util.h"



static void (* TIM0_Ptr_ISR)(void);
static void (* TIM1_Ptr_ISR)(void);

void SetTIM0_OVF_ISR(void (*Copy_voidPtrToFun)(void)){
	TIM0_Ptr_ISR = *Copy_voidPtrToFun;
}

ISR(__vector_11) {
	TIM0_Ptr_ISR();
	}

void SetTIM1_OVF_ISR(void (*Copy_voidPtrToFun)(void)){
	TIM1_Ptr_ISR = *Copy_voidPtrToFun;
}

ISR(__vector_9) {
	TIM1_Ptr_ISR();
	}



void Timer0_voidInit() {
	Assign(*TIM_TCCR0, TIM_TCCR0_INIT);
	Assign(*TIM_TCNT0,0);
	Assign(*TIM_TIMSK, TIM_TIMSK_INIT);
	Assign(*TIM_TIFR, TIM_TIFR_INIT);
	return;
}

void Timer1_voidInit() {
	Assign(*TIM_TCCR1A, TIM_TCCR1A_INIT);
	Assign(*TIM_TCCR1B, TIM_TCCR1B_INIT);
	Assign(*TIM_TIMSK, TIM_TIMSK_INIT);
	Assign(*TIM_TIFR, TIM_TIFR_INIT);
	return;
}

void Timer0_voidWriteReg(u8 Copy_U8WriteVal){
	Assign(*TIM_TCNT0, Copy_U8WriteVal);
	return;
}

void Timer0_voidReadReg(u8 *Copy_U8PtrToVal){
	*Copy_U8PtrToVal = ReadReg(*TIM_TCNT0);
}

void Timer1_voidReadReg(u16 *Copy_U16PtrToVal){
	*Copy_U16PtrToVal = ReadReg(*TIM_TCNT1L) | (ReadReg(*TIM_TCNT1H)<<8);
}



void Timer1_voidWriteReg(u16 Copy_U16WriteVal){
	Assign(*TIM_TCNT1L, (u8)Copy_U16WriteVal);
	Assign(*TIM_TCNT1H, (u8)(Copy_U16WriteVal>>8));
	return;
}

void Timer1_Stop(void){
	Assign(*TIM_TCCR1B, LOW);
}
void Timer0_Stop(void){
	Assign(*TIM_TCCR0, LOW);
}
