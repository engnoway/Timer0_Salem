/*
 * Timer.private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*Comment!: Timer 0 Registers*/
#define TIM_TCCR0	(volatile u8*)(0x53)
#define TIM_TCNT0	(volatile u8*)(0x52)
#define TIM_OCR0	(volatile u8*)(0x5C)

/*Comment!: Timer 1 Registers */
#define TIM_TCCR1A	(volatile u8*)(0x4F)
#define TIM_TCCR1B	(volatile u8*)(0x4E)
#define TIM_TCNT1H	(volatile u8*)(0x4D)
#define TIM_TCNT1L	(volatile u8*)(0x4C)
#define TIM_OCR1AH	(volatile u8*)(0x4B)
#define TIM_OCR1AL	(volatile u8*)(0x4A)
#define TIM_OCR1BH	(volatile u8*)(0x49)
#define TIM_OCR1BL	(volatile u8*)(0x48)
#define TIM_ICR1H	(volatile u8*)(0x47)
#define TIM_ICR1L	(volatile u8*)(0x46)

#define TIM_TIMSK	(volatile u8*)(0x59)
#define TIM_TIFR	(volatile u8*)(0x58)


/*Comment!: Initialized TIMER 0 Registers */
#define TIM_TCCR0_INIT	Conc(CS00, CS01, CS02, WGM01, COM00, COM01, WGM00, FOC0)

/*Comment!: Initialized TIMER 1 Registers */
#define TIM_TCCR1A_INIT	Conc(WGM10, WGM11, FOC1B, FOC1A, COM1B0, COM1B1, COM1A0, COM1A1)
#define TIM_TCCR1B_INIT	Conc(CS10, CS11, CS12, WGM12, WGM13, NONE, ICES1, ICNC1)

#define TIM_TIMSK_INIT	Conc(TOIE0, OCIE0, TOIE1, OCIE1B, OCIE1A, TICIE1, TOIE2, OCIE2)
#define TIM_TIFR_INIT	Conc(TOV0, OCF0, TOV1, OCF1B, OCF1A, ICF1, TOV2, OCF2)




/*Comment!: TIMER 0 REGISTER */
/*Comment!: TCCRO Register */
#define TIM_FOC0	7
#define TIM_WGM00	6
#define TIM_COM01	5
#define TIM_COM00	4
#define TIM_WGM01	3
#define TIM_CS02	2
#define TIM_CS01	1
#define TIM_CS00	0

/*Comment!: TIMER 1 REGISTER */
/*Comment!: TCCR1A Register */
#define TIM_COM1A1	7
#define TIM_COM1A0	6
#define TIM_COM1B1	5
#define TIM_COM1B0	4
#define TIM_FOC1A	3
#define TIM_FOC1B	2
#define TIM_WGM11	1
#define TIM_WGM10	0

/*Comment!: TCCR1B Register */
#define TIM_ICNC1	7
#define TIM_ICES1	6
#define TIM_NONE	5
#define TIM_WGM13	4
#define TIM_WGM12	3
#define TIM_CS12	2
#define TIM_CS11	1
#define TIM_CS10	0

/*Comment!: Shared Registers */
/*Comment!: TIMSK Register */
#define TIM_OCIE2	7
#define TIM_TOIE2	6
#define TIM_TICIE1	5
#define TIM_OCIE1A	4
#define TIM_OCIE1B	3
#define TIM_TOIE1	2
#define TIM_OCIE0	1
#define TIM_TOIE0	0

/*Comment!: TIFR Register */
#define TIM_OCF2	7
#define TIM_TOV2	6
#define TIM_ICF1	5
#define TIM_OCF1A	4
#define TIM_OCF1B	3
#define TIM_TOV1	2
#define TIM_OCF0	1
#define TIM_TOV0	0

/*Comment!: SFIOR Register */
#define PSR10	0


/*Comment!: Concatenation function */
#define Conc(x1,x2,x3,x4,x5,x6,x7,x8) ConcHelper(x1,x2,x3,x4,x5,x6,x7,x8)
#define ConcHelper(b1,b2,b3,b4,b5,b6,b7,b8) 0b##b8##b7##b6##b5##b4##b3##b2##b1

#endif /* TIMER_PRIVATE_H_ */
