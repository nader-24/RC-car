/*
 * ICU_program.c
 *
 *  Created on: 29 Nov 2024
 *      Author: nader
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ICU_interface.h"
#include "ICU_config.h"
#include "ICU_private.h"

static void (*GlobalPtrFuncicu)(void)=NULL;

void ICU_voidEnable(void)
{
	SET_BIT(TIMSK1,TIMSK1_TICIE1);
}
void ICU_voidDisable(void)
{
	CLR_BIT(TIMSK1,TIMSK1_TICIE1);
}


void ICU_voidSetPrecaller(PRE_SCALLER_e Copy_ePrescaller)
{
	switch (Copy_ePrescaller)
	{
	case NO_PRE_SCALLER:
		TCCR1B &= 0b11111000;
		TCCR1B |= NO_PRE_SCALLER;
		break;
	case DIV_8 :
		TCCR1B &= 0b11111000;
		TCCR1B |= DIV_8;
		break;
	case DIV_64:
		TCCR1B &= 0b11111000;
		TCCR1B |= DIV_64;
		break;
	case DIV_256:
		TCCR1B &= 0b11111000;
		TCCR1B |= DIV_256;
		break;
	case DIV_1024:
		TCCR1B &= 0b11111000;
		TCCR1B |= DIV_1024;
		break;
	}
}

u16 ICU_u16ICR(void)
{
	return ICR1;
}

void ICU_voidSetCallBack(void (*ptrfunc)(void))
{
	if(ptrfunc!=NULL)
	{
		GlobalPtrFuncicu=ptrfunc;
	}
	else
	{
		/* do nothing */
	}
}


void ICU_voidSetEdge(u8 Copy_u8Egde)
{
	if(Copy_u8Egde==FALLING)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if (Copy_u8Egde==RISING)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
}

//ICU_interrupt
void __vector_6(void)  __attribute__((signal));
void __vector_6(void)
{
	GlobalPtrFuncicu();
}
