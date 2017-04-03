/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */
#include "Types.h"
#include "DIO_interface.h"

#include "Timer_interface.h"

#include "Delay.h"
#include "avr/io.h"

#define led1	DIO_U8PIN16
#define led2	DIO_U8PIN17
#define led3	DIO_U8PIN18

volatile u8 ButFlag = 0;

u8 LedFlag1 = 0;
u8 LedFlag2 = 0;
u8 LedFlag3 = 0;
u8 Local_U8led1 = 0;

volatile u8 TimFlag = 0;

volatile u16 Counter = 0;

void Red_Fun(void) {
	Delay_ms(5);
	LedFlag1 = !LedFlag1;
}

void Yellow_Fun(void) {
	Delay_ms(5);
	LedFlag2 = !LedFlag2;
}
void Green_Fun(void) {
	Delay_ms(5);
	LedFlag3 = !LedFlag3;
}

void TIM0_Main(void) {
	Counter++;

	//DIO_U8WritePinVal(7, HIGH);
/*	__asm__("CLI");
	if (Counter == 2000) {
		TimFlag = 1;
		Counter = 0;
		Local_U8led1 = !Local_U8led1;
	}
	Timer0_voidWriteReg(0x06);
	__asm__("SEI");*/
}

int main(void) {

u8 reg,flags=0;
	SetTIM0_OVF_ISR(TIM0_Main);
	DIO_voidInit();

	//Timer0_voidWriteReg(0x06);
	Timer0_voidInit();

	__asm__("SEI");
	Counter=0;
	while (1) {
		if(Counter>=390)
		{
			Timer0_voidReadReg(&reg);
			if( reg >= 160 )
			{
				//PORTA ^= (1 << 2);//toggle the led on A2
				//flags=!flags;
				DIO_U8WritePinVal(2,flags);
				//Timer0_voidWriteReg(0);
				Counter=0;

			}
		}
	}
	return 0;
}

