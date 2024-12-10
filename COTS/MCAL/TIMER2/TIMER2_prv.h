#ifndef TIMER2_PRV_H
#define TIMER2_PRV_H

/*-----------------------------------TIMERS REGISTERS---------------------------*/
#define TIMERS_u8_TIMSK_REG         *((volatile u8*) 0x59)
/*TIMER2*/
#define TIMSK_OCIE2_BIT         7
#define TIMSK_TOIE2_BIT         6

#define TIMERS_u8_TIFR_REG          *((volatile u8*) 0x58)
/*TIMER2*/
#define TIFR_OCF2_BIT           7
#define TIFR_TOV2_BIT           6
/*-----------------------------------------------------------------TIMER2-------------------------------------------------------------------*/
/*TIMER2 REGISTERS*/
#define TIMER2_u8_TCCR2_REG         *((volatile u8*) 0x45)
#define TCCR2_FCO2_BIT      7
#define TCCR2_WGM20_BIT     6       
#define TCCR2_COM21_BIT     5        
#define TCCR2_COM20_BIT     4       
#define TCCR2_WGM21_BIT     3       
#define TCCR2_CS22_BIT      2
#define TCCR2_CS21_BIT      1
#define TCCR2_CS20_BIT      0

#define TIMER2_u8_TCNT2_REG        *((volatile u8*) 0x44)//read number of ticks or set a pre-load valu3

#define TIMER2_u8_OCR2_REG         *((volatile u8*) 0x43)//set the Compare match value
/*------------------------TIMER2 MODE-----------------------*/
/*TIMER2_WAVE_GENRATION*/
#define     TIMER2_NORMAL_MODE             1
#define     TIMER2_PWM_PHASE_CORRECT_MODE  2
#define     TIMER2_CTC_MODE                3
#define     TIMER2_FAST_PWM_MODE           4
/*TIMER2_OC2_MODE*/
#define     TIMER2_NORMAL_DIO_PIN      1
#define     TIMER2_TOGGLE_OC2          2
#define     TIMER2_CLR_OC2             3
#define     TIMER2_SET_OC2             4
/*TIMER2_PRESCALRER*/
#define     TIMER2_NO_CLOCK_SOURCE         1
#define     TIMER2_DEVIDED_BY_1            2
#define     TIMER2_DEVIDED_BY_8            3
#define     TIMER2_DEVIDED_BY_64           4
#define     TIMER2_DEVIDED_BY_256          5
#define     TIMER2_DEVIDED_BY_1024         6


#endif