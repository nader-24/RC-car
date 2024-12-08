/*
 * ICU_private.h
 *
 *  Created on: 29 Nov 2024
 *      Author: nader
 */

#ifndef ICU_PRIVATE_H_
#define ICU_PRIVATE_H_

//icr register
#define ICR1             *((volatile u16*)0x46)

//interrupt register
#define TIMSK1           *((volatile u8*)0x59)
#define TIMSK1_TICIE1    5


//flag register
#define TIFR1            *((volatile u8*)0x58)
#define TIFR1_ICF1       5


//counter register
#define TCNT1            *((volatile u16*)0x4C)

//control register

#define TCCR1B           *((volatile u8*)0x4E)
#define TCCR1B_CS10      0
#define TCCR1B_CS11      1
#define TCCR1B_CS12      2
#define TCCR1B_ICES1     6
#define TCCR1B_ICNC1     7



#endif /* ICU_PRIVATE_H_ */
