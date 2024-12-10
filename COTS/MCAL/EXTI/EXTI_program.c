/*
 * EXTI_program.c
 *
 *  Created on: 27 Sep 2024
 *      Author: nader
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

static void (*GlobalPtrFunc[3])(void) = {NULL};




void EXTI_voidEnableDisable(INTNUM_e Copy_eIntNum, MODE_e Copy_eMode)
{
	switch (Copy_eIntNum)
	{
	case INT0:
		switch(Copy_eMode)
		{
		case ENABLED:
			SET_BIT(GICR,GICR_INT0);
			break;
		case DISABLED:
			CLR_BIT(GICR,GICR_INT0);
			break;
		}
	break;
	case INT1:
		switch(Copy_eMode)
		{
		case ENABLED:
			SET_BIT(GICR,GICR_INT1);
			break;
		case DISABLED:
			CLR_BIT(GICR,GICR_INT1);
			break;
		}
	break;

	case INT2:
		switch(Copy_eMode)
		{
		case ENABLED:
			SET_BIT(GICR,GICR_INT2);
			break;
		case DISABLED:
			CLR_BIT(GICR,GICR_INT2);
			break;
		}
	break;

	}
}



void EXTI_voidSetSenseCtrl(INTNUM_e Copy_eIntNum, SENSITIVITY_e Copy_eSenseControl)
{
	switch (Copy_eIntNum)
	{
	case INT0 :
		switch (Copy_eSenseControl)
		{
		case LOW_LEVEL :
			CLR_BIT(MCUCR, MCUCR_ISC00);
			CLR_BIT(MCUCR, MCUCR_ISC01);
			break;
		case ON_CHANGE :
			SET_BIT(MCUCR, MCUCR_ISC00);
			CLR_BIT(MCUCR, MCUCR_ISC01);
			break;
		case FALLING_EDGE :
			CLR_BIT(MCUCR, MCUCR_ISC00);
			SET_BIT(MCUCR, MCUCR_ISC01);
			break;
		case RISING_EDGE :
			SET_BIT(MCUCR, MCUCR_ISC00);
			SET_BIT(MCUCR, MCUCR_ISC01);
			break;
		}
		break;

	case INT1 :
		switch (Copy_eSenseControl)
		{
		case LOW_LEVEL :
			CLR_BIT(MCUCR, MCUCR_ISC10);
			CLR_BIT(MCUCR, MCUCR_ISC11);
			break;
		case ON_CHANGE :
			SET_BIT(MCUCR, MCUCR_ISC10);
			CLR_BIT(MCUCR, MCUCR_ISC11);
			break;
		case FALLING_EDGE :
			CLR_BIT(MCUCR, MCUCR_ISC10);
			SET_BIT(MCUCR, MCUCR_ISC11);
			break;
		case RISING_EDGE :
			SET_BIT(MCUCR, MCUCR_ISC10);
			SET_BIT(MCUCR, MCUCR_ISC11);
			break;
		}
		break;
	case INT2 :
		switch (Copy_eSenseControl)
		{
		case RISING_EDGE :
			SET_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		case FALLING_EDGE :
			CLR_BIT(MCUCSR,MCUCSR_ISC2);
			break;
		}
		break;
	}
}


STD_err_e EXTI_voidSetCallBack(INTNUM_e Copy_eIntNum,
		void (*Local_PtrFunc)(void))
{
	STD_err_e Local_errState = OK;
	if (Local_PtrFunc != NULL)
	{
		switch (Copy_eIntNum)
		{
		case INT0 :
			GlobalPtrFunc[0] = Local_PtrFunc;
			break;
		case INT1 :
			GlobalPtrFunc[1] = Local_PtrFunc;
			break;
		case INT2 :
			GlobalPtrFunc[2] = Local_PtrFunc;
			break;
		}
	}
	else
	{
		Local_errState = NOK;
	}
	return Local_errState ;
}

/* ISR TO HANDLE INTERRUPT ZERO */
void __vector_1(void)     __attribute__((signal));
void __vector_1(void)
{
	GlobalPtrFunc[0]();
}


void __vector_2(void)     __attribute__((signal));
void __vector_2(void)
{
	GlobalPtrFunc[1]();
}


void __vector_3(void)     __attribute__((signal));
void __vector_3(void)
{
	GlobalPtrFunc[2]();
}

