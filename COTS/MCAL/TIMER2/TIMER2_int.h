#ifndef TIMER2_INT_H
#define TIMER2_INT_H
 
typedef enum
{
    ENABLE = 0,
	DISABLE

}TIMERS_Interrupt_eMode;


//========================================================================================================================
/*----------------TIMER2----------------------*/
void TIMER2_voidInit();

void TIMER2_voidSetPreload(u8 PreLoad_Value);

void TIMER2_voidSetOutputCompare(u8 Compare_Value);

void TIMER2_voidOFInterrupt(TIMERS_Interrupt_eMode Mode);

void TIMER2_voidCMInterrupt(TIMERS_Interrupt_eMode Mode);

void TIMER2_voidOFSetCallBack(void (* Copy_pu8OVIFunc)());

void TIMER2_voidCMSetCallBack(void (* Copy_pu8CMIFUnc)());
#endif
