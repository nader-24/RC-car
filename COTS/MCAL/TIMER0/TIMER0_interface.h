#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


typedef enum
{
	NON_INV = 0,
	INV
}PWM_mode_e;

void TIMER0_voidInit(void);

void TIMER0_voidSetPreLoadTicks(u8 Copy_u8Ticks);

void TIMER0_voidSetOcrTicks(u8 Copy_u8Ticks);

STD_err_e TIMER0_eSetCallBackNormal(void (*Pfunc)(void));

STD_err_e TIMER0_eSetCallBackCompare(void (*Pfunc)(void));

void FASTPWM_voidInvOrNoninv(PWM_mode_e Copy_Mode);




#endif
