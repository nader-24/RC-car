#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

//=================================================================================================================
#include "TIMER2_int.h" 
#include "TIMER2_prv.h"
#include "TIMER2_cfg.h"
//==========================================================================================================================
/*----------------TIMER2----------------------*/
void (*TIMER2_pvOFIFunc)() = NULL;
void (*TIMER2_pvCMIFunc)() = NULL;

void TIMER2_voidInit()
{
    /*TIMER2_WAVE_GENRATION*/
    #if TIMER2_WAVE_GENRATION == TIMER2_NORMAL_MODE
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_WGM20_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_WGM21_BIT);

    #elif   TIMER2_WAVE_GENRATION == TIMER2_PWM_PHASE_CORRECT_MODE
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_WGM20_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_WGM21_BIT);

    #elif   TIMER2_WAVE_GENRATION == TIMER2_CTC_MODE
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_WGM20_BIT);
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_WGM21_BIT);

    #elif   TIMER2_WAVE_GENRATION == TIMER2_FAST_PWM_MODE
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_WGM20_BIT);
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_WGM21_BIT);
    #endif

    /*TIMER0_OC2_MODE */
    #if TIMER2_OC2_MODE == TIMER2_NORMAL_DIO_PIN
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_COM20_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_COM21_BIT);

    #elif TIMER2_OC2_MODE == TIMER2_TOGGLE_OC2
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_COM20_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_COM21_BIT);

    #elif TIMER2_OC2_MODE == TIMER2_CLR_OC2
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_COM20_BIT);
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_COM21_BIT);

    #elif TIMER2_OC2_MODE == TIMER2_SET_OC2
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_COM20_BIT);
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_COM21_BIT);
    #endif
    /*TIMER0_PRESCALER*/
    #if TIMER2_PRESCALER == TIMER2_NO_CLOCK_SOURCE
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS20_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS21_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS22_BIT);

    #elif TIMER2_PRESCALER == TIMER2_DEVIDED_BY_1
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS20_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS21_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS22_BIT);

    #elif   TIMER2_PRESCALER == TIMER2_DEVIDED_BY_8
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS20_BIT);
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS21_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS22_BIT);

    #elif   TIMER2_PRESCALER == TIMER2_DEVIDED_BY_64
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS20_BIT);
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS21_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS22_BIT);

    #elif   TIMER2_PRESCALER == TIMER2_DEVIDED_BY_256
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS20_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS21_BIT);
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS22_BIT);

    #elif   TIMER2_PRESCALER == TIMER2_DEVIDED_BY_1024 
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS20_BIT);
    CLR_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS21_BIT);
    SET_BIT(TIMER2_u8_TCCR2_REG,TCCR2_CS22_BIT);
    #endif  
}

void TIMER2_voidSetPreload(u8 PreLoad_Value)
{
    TIMER2_u8_TCNT2_REG = PreLoad_Value;
}

void TIMER2_voidSetOutputCompare(u8 Compare_Value)
{
    TIMER2_u8_OCR2_REG = Compare_Value ;
}

void TIMER2_voidOFInterrupt(TIMERS_Interrupt_eMode Mode)
{
    switch (Mode)
    {
    case DISABLE:
        CLR_BIT(TIMERS_u8_TIMSK_REG,TIMSK_TOIE2_BIT);
        break;
    case ENABLE :
        SET_BIT(TIMERS_u8_TIMSK_REG,TIMSK_TOIE2_BIT);
        break;
    
    default:
        break;
    }
}

void TIMER2_voidCMInterrupt(TIMERS_Interrupt_eMode Mode)
{
    switch (Mode)
    {
    case DISABLE:
        CLR_BIT(TIMERS_u8_TIMSK_REG,TIMSK_OCIE2_BIT);
        break;
    case ENABLE :
        SET_BIT(TIMERS_u8_TIMSK_REG,TIMSK_OCIE2_BIT);
        break;
    
    default:
        break;
    }
}

void TIMER2_voidOFSetCallBack(void (* Copy_pvOFIFunc)())
{
    TIMER2_pvOFIFunc = Copy_pvOFIFunc ;
}

void TIMER2_voidCMSetCallBack(void (* Copy_pvCMIFunc)())
{
    TIMER2_pvCMIFunc = Copy_pvCMIFunc ;
}

void __vector_5(void) __attribute__((signal));
void __vector_5(void)
{
    if(TIMER2_pvOFIFunc != NULL)
    {
        TIMER2_pvOFIFunc();
    }
    else
    {
        /*DO NOTHING*/
    }
}

void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
    if(TIMER2_pvCMIFunc != NULL)
    {
        TIMER2_pvCMIFunc();
    }
    else
    {
        /*DO NOTHING*/
    }
}
