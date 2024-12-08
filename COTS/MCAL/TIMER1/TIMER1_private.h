/*
 * TIMER1_private.h
 *
 *  Created on: 18 Oct 2024
 *      Author: nader
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

/* PRE_SCALLER OPTIONS */
#define DIV_1      1
#define DIV_8      2
#define DIV_64     3
#define DIV_256    4
#define DIV_1024   5
#define EXT_FALL   6
#define EXT_RIS    7


/* Timer 1 counter Register */
#define TCNT1            *((volatile u16*)0x4C)

/* Timer 1A control Register  */
#define TCCR1A           *((volatile u8*)0x4F)
#define TCCR1A_WGM10     0
#define TCCR1A_WGM11     1
#define TCCR1A_FOC1B     2
#define TCCR1A_FOC1A     3
#define TCCR1A_COM1B0    4
#define TCCR1A_COM1B1    5
#define TCCR1A_COM1A0    6
#define TCCR1A_COM1A1    7

/* Timer 1B control Register */
#define TCCR1B           *((volatile u8*)0x4E)
#define TCCR1B_CS10      0
#define TCCR1B_CS11      1
#define TCCR1B_CS12      2
#define TCCR1B_WGM12     3
#define TCCR1B_WGM13     4
/*          Bit 5 is reserved       */
#define TCCR1B_ICES1     6
#define TCCR1B_ICNC1     7

/* Timer 1A output compare Register 16bit */
#define OCR1A            *((volatile u16*)0x4A)

/* Timer 1B output compare Register 16bit */
#define OCR1B            *((volatile u16*)0x48)

/* Timer 1 input capture Register */
#define ICR1             *((volatile u16*)0x46)

/* Timer Interrupt control Register */
#define TIMSK1           *((volatile u8*)0x59)
#define TIMSK1_TOIE1     2
#define TIMSK1_OCIE1B    3
#define TIMSK1_OCIE1A    4
#define TIMSK1_TICIE1    5

/* Timer 1 Flag Register  */
#define TIFR1            *((volatile u8*)0x58)
#define TIFR1_TOV1       2
#define TIFR1_OCF1B      3
#define TIFR1_OCF1A      4
#define TIFR1_ICF1       5
#endif /* TIMER1_PRIVATE_H_ */
