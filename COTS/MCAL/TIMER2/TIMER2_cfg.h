#ifndef TIMER2_CFG_H
#define TIMER2_CFG_H
/*--------------------------------------TIMER2--------------------------------------------------------*/
/*
TIMER2_NORMAL_MODE
TIMER2_PWM_PHASE_CORRECT_MODE
TIMER2_CTC_MODE
TIMER2_FAST_PWM_MODE
*/
#define TIMER2_WAVE_GENRATION  TIMER2_CTC_MODE


/*
TIMER2_NORMAL_DIO_PIN
TIMER2_TOGGLE_OC2
TIMER2_CLR_OC2
TIMER2_SET_OC2
*/
#define TIMER2_OC2_MODE     TIMER2_TOGGLE_OC2

/*
TIMER2_NO_CLOCK_SOURCE
TIMER2_DEVIDED_BY_1
TIMER2_DEVIDED_BY_8
TIMER2_DEVIDED_BY_64
TIMER2_DEVIDED_BY_254
TIMER2_DEVIDED_BY_1024
*/
#define TIMER2_PRESCALER     TIMER2_DEVIDED_BY_1
//==============================================================================================================



#endif