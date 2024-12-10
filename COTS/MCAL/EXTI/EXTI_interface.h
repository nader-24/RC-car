/*
 * EXTI_interface.h
 *
 *  Created on: 27 Sep 2024
 *      Author: nader
 */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


typedef enum
{
	ENABLED = 0,
	DISABLED
}MODE_e;

typedef enum
{
	LOW_LEVEL = 0,
	ON_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}SENSITIVITY_e;

typedef enum
{
	INT0 = 0,
	INT1,
	INT2
}INTNUM_e;



void EXTI_voidEnableDisable(INTNUM_e Copy_eIntNum, MODE_e Copy_eMode);

void EXTI_voidSetSenseCtrl(INTNUM_e Copy_eIntNum, SENSITIVITY_e Copy_eSenseControl);

STD_err_e EXTI_voidSetCallBack(INTNUM_e Copy_eIntNum,
		void (*Local_PtrFunc)(void));








#endif
