#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define NORMAL_MODE   1
#define CTC_MODE      2
#define FAST_PWM      3
#define PHASE_PWM     4

#define DIV_1         1
#define DIV_8         2
#define DIV_64        3
#define DIV_256       4
#define DIV_1024      5




#define  TCCR0         *((volatile u8*)0X53)
#define  TCCR0_WGM01   3
#define  TCCR0_WGM00   6

#define  TCNT0         *((volatile u8*)0X52)
#define  OCR0          *((volatile u8*)0X5C)

#define  TIMSK         *((volatile u8*)0X59)
#define  TIMSK_TOIE0   0
#define  TIMSK_OCIE0   1



#endif
