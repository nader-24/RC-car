/*=======================================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*=======================================================*/
#include "TIMER0_config.h"
#include "TIMER0_interface.h"
#include "TIMER0_private.h"
/*=======================================================*/

static void (*GlobalPtrFuncNormal)(void)=NULL;
static void (*GlobalPtrFuncCompare)(void)=NULL;

void TIMER0_voidInit(void)
{
	/* Timer Mode   -> WG Bits  -> Inter Source */
#if TIMER_MODE==NORMAL_MODE
	CLR_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TIMSK,TIMSK_TOIE0);
#elif TIMER_MODE == CTC_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TIMSK,TIMSK_OCIE0);
	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);
#elif TIMER_MODE == FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
#elif TIMER_MODE == PHASE_PWM
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

#else
#error ("Wrong config");
#endif


	/* configure PreScaller */

#if PRE_SCALLER == DIV_1
	TCCR0 &=0b11111000;
	TCCR0 |= DIV_1;
#elif PRE_SCALLER == DIV_8
	TCCR0 &=0b11111000;
	TCCR0 |=DIV_8;
#elif PRE_SCALLER == DIV_64
	TCCR0 &=0b11111000;
	TCCR0 |=DIV_64;
#elif PRE_SCALLER == DIV_256
	TCCR0 &=0b11111000;
	TCCR0 |= DIV_256;
#elif PRE_SCALLER == DIV_1024
	TCCR0 &=0b11111000;
	TCCR0 |= DIV_1024;
#else
#error ("wrong prescaller");
#endif



}


void TIMER0_voidSetPreLoadTicks(u8 Copy_u8Ticks)
{
	TCNT0 = Copy_u8Ticks;
}


void TIMER0_voidSetOcrTicks(u8 Copy_u8Ticks)
{
	OCR0 = Copy_u8Ticks;
}


STD_err_e TIMER0_eSetCallBackNormal(void (*Pfunc)(void))
{
	STD_err_e Local_ErrorStatus = OK;
	if(Pfunc != NULL)
	{
		GlobalPtrFuncNormal = Pfunc;
	}
	else
	{
		Local_ErrorStatus = NOK;
	}
	return Local_ErrorStatus;
}


STD_err_e TIMER0_eSetCallBackCompare(void (*Pfunc)(void))
{
	STD_err_e Local_ErrorStatus = OK;
	if(Pfunc != NULL)
	{
		GlobalPtrFuncCompare = Pfunc;
	}
	else
	{
		Local_ErrorStatus = NOK;
	}
	return Local_ErrorStatus;
}

void FASTPWM_voidInvOrNoninv(PWM_mode_e Copy_Mode)
{
	switch (Copy_Mode)
	{
	case NON_INV:
		CLR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		break;
	case INV:
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		break;
	}
}


/* overflow */
void __vector_11(void)     __attribute__((signal));
void __vector_11(void)
{
	GlobalPtrFuncNormal();
}


/* compare */
void __vector_10(void)     __attribute__((signal));
void __vector_10(void)
{
	GlobalPtrFuncCompare();
}

