/*===============================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*===============================================*/
#include "TIMER1_config.h"
#include "TIMER1_interface.h"
#include "TIMER1_private.h"
/*==============================================*/

static void (*GlobalPtrFuncOVF)(void)=NULL;


void TIMER1_voidInit(void)
{
/* REQ mode -> 1 ovf  */

	TCCR1A =0x00;
	/*  enable interrupt */
	SET_BIT(TIMSK1,TIMSK1_TOIE1);

/* prescaller -> handeled in ICU */

}
void TIMER1_voidDisable()
{
	CLR_BIT(TIMSK1,TIMSK1_TOIE1);
}

void TIMER1_voidSetCallBackOVF(void (*pfunc)(void))
{
	if(pfunc!=NULL)
	{
		GlobalPtrFuncOVF=pfunc;
	}
	else
	{
		/* do nothing */
	}
}


void TIMER1_voidSetCompareValue(u16 Copy_u16Value)
{
	OCR1A= Copy_u16Value;
}

void TIMER1_voidSetCompareValue_B(u16 Copy_u16Value)
{
	OCR1B = Copy_u16Value;
}


void TIMER1_voidSetPreLoad(u16 Copy_u16PreLoad)
{
	TCNT1 = Copy_u16PreLoad;
}

void __vector_9(void)  __attribute__((signal));
void __vector_9(void)
{
	GlobalPtrFuncOVF();
}

