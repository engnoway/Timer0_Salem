/*
 * S4MDelay.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef S4MDELAY_H_
#define S4MDELAY_H_

#define Delay_us(Copy_U8DelayVal) do{ u16 Local_U16Counter; \
	for(Local_U16Counter = 0 ; Local_U16Counter < Copy_U8DelayVal; Local_U16Counter++){\
	__asm__("NOP"); __asm__("NOP"); __asm__("NOP"); __asm__("NOP");\
	}\
	}while(0)

#endif /* S4MDELAY_H_ */
