/*
 * TIMER1_interface.h
 *
 *  Created on: 18 Oct 2024
 *      Author: nader
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_



typedef enum
{
	NORMAL = 0,
	PWM_PHASE_CORRECT_8,
	PMW_PHASE_CORRECT_9,
	PWM_PHASE_CORRECT_10,
	COMPARE_OCR1A,
	PWM_FAST_8,
	PWM_FAST_9,
	PWM_FAST_10,
	PWM_FREQ_PHASE_CORRECT_ICR1,
	PWM_FREQ_PHASE_CORRECT_OCR1A,
	PWM_PHASE_CORRECT_ICR1,
	PWM_PHASE_CORRECT_OCR1A,
	COMPARE_ICR1,
	PWM_FAST_ICR1 = 14,
	PWM_FAST_OCR1A

}Mode_e;

void TIMER1_voidSetCallBackOVF(void (*pfunc)(void));
void TIMER1_voidSetPreLoad(u16 Copy_u16PreLoad);


void TIMER1_voidInit(void);
void TIMER1_voidSetCompareValue(u16 Copy_u16Value);
void TIMER1_voidSetCompareValue_B(u16 Copy_u16Value);
#endif /* TIMER1_INTERFACE_H_ */
