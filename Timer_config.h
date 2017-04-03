/*
 * Timer_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: muslim
 */

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/*Comment!: TIMER 0 Configuration */

/*Comment!: TCCRO Register */
/*Range!: HIGH ~ LOW */
#define FOC0	LOW
#define	WGM00	LOW
#define COM01	LOW
#define COM00	LOW
#define WGM01	LOW
#define CS02	LOW
#define CS01	HIGH
#define CS00	LOW

/*Comment! TIMER 1 Configuration*/

/*Comment!: TCCR1A Register */
/*Range!: HIGH ~ LOW */
#define COM1A1	LOW
#define COM1A0	LOW
#define COM1B1	LOW
#define COM1B0	LOW
#define FOC1A	LOW
#define FOC1B	LOW
#define WGM11	LOW
#define WGM10	LOW

/*Comment!: TCCR1B Register */
/*Range!: HIGH ~ LOW */
#define ICNC1	LOW
#define ICES1	LOW
#define NONE	LOW
#define WGM13	LOW
#define WGM12	LOW
#define CS12	LOW
#define CS11	HIGH
#define CS10	LOW






/*Comment!: TIMSK Register */
/*Range!: HIGH ~ LOW*/
#define OCIE2	LOW
#define TOIE2	LOW
#define TICIE1	LOW
#define OCIE1A	LOW
#define OCIE1B	LOW
#define TOIE1	HIGH
#define OCIE0	LOW
#define TOIE0	HIGH

/*Comment!: TIFR Register */
#define OCF2	LOW
#define TOV2	LOW
#define ICF1	LOW
#define OCF1A	LOW
#define OCF1B	LOW
#define TOV1	LOW
#define OCF0	LOW
#define TOV0	LOW


#endif /* TIMER_CONFIG_H_ */
