#ifndef _Delay_H_
#define _Delay_H_

#include "Delay_Config.h"

#define Delay_ms(Copy_U64DelayMs) do{f64 Local_U32LoopCounter; \
	for (Local_U32LoopCounter = ((Delay_SysClock * 1000 * Copy_U64DelayMs) \
			/ (24 * 50)); Local_U32LoopCounter > 0; Local_U32LoopCounter--) { \
		__asm__("NOP"); \
	} \
} while(0)

#endif
