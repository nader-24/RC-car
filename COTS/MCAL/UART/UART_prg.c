/*===================================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*===================================================*/
#include "UART_int.h"
#include "UART_prv.h"
#include "UART_cfg.h"
/*=====================================================*/
static void (*UART_pvRXCIFunc)(void) = NULL;
static void (*UART_pvTXCIFunc)(void) = NULL;
static void (*UART_pvUDREIFunc)(void) = NULL;

void UART_voidInit(void)
{
    u8 Local_UCSRC_var=0;
    SET_BIT(Local_UCSRC_var,UCSRC_URSEL_BIT);
    #if UART_TRANSMITTE == UART_TRANSMITTE_ENABLE
    SET_BIT(UART_u8_UCSRB_REG,UCSRB_TXEN_BIT);

    #elif UART_TRANSMITTE == UART_TRANSMITTE_DISABLE  
    CLR_BIT(UART_u8_UCSRB_REG,UCSRB_TXEN_BIT);
    #endif

    #if UART_RECEIVE == UART_RECEIVE_ENABLE
    SET_BIT(UART_u8_UCSRB_REG,UCSRB_RXEN_BIT);

    #elif UART_RECEIVE == UART_RECEIVE_DISABLE
    SET_BIT(UART_u8_UCSRB_REG,UCSRB_RXEN_BIT);
    #endif

    #if UART_PARITY_MODE == UART_PARITY_DISABLE
    CLR_BIT(Local_UCSRC_var,UCSRC_UPM0_BIT);
    CLR_BIT(Local_UCSRC_var,UCSRC_UPM1_BIT);

    #elif UART_PARITY_MODE == UART_PARITY_EVEN
    CLR_BIT(Local_UCSRC_var,UCSRC_UPM0_BIT);
    SET_BIT(Local_UCSRC_var,UCSRC_UPM1_BIT);

    #elif UART_PARITY_MODE == UART_PARITY_ODD
    SET_BIT(Local_UCSRC_var,UCSRC_UPM0_BIT);
    SET_BIT(Local_UCSRC_var,UCSRC_UPM1_BIT);
    #endif


    #if UART_STOP_BIT == UART_STOP_BIT_1
    CLR_BIT(Local_UCSRC_var,UCSRC_USBS_BIT);
    #elif UART_STOP_BIT == UART_STOP_BIT_2
    SET_BIT(Local_UCSRC_var,UCSRC_USBS_BIT);
    #endif


    #if UART_CHARCHTER_SIZE == UART_CHARCHTER_SIZE_5
    CLR_BIT(Local_UCSRC_var,UCSRC_UCSZ0_BIT);
    CLR_BIT(Local_UCSRC_var,UCSRC_UCSZ1_BIT);
    CLR_BIT(UART_u8_UCSRB_REG,UCSRB_UCSZ2_BIT);

    #elif UART_CHARCHTER_SIZE == UART_CHARCHTER_SIZE_6
    SET_BIT(Local_UCSRC_var,UCSRC_UCSZ0_BIT);
    CLR_BIT(Local_UCSRC_var,UCSRC_UCSZ1_BIT);
    CLR_BIT(UART_u8_UCSRB_REG,UCSRB_UCSZ2_BIT);
    #elif UART_CHARCHTER_SIZE == UART_CHARCHTER_SIZE_7
    CLR_BIT(Local_UCSRC_var,UCSRC_UCSZ0_BIT);
    SET_BIT(Local_UCSRC_var,UCSRC_UCSZ1_BIT);
    CLR_BIT(UART_u8_UCSRB_REG,UCSRB_UCSZ2_BIT);
    #elif UART_CHARCHTER_SIZE == UART_CHARCHTER_SIZE_8
    SET_BIT(Local_UCSRC_var,UCSRC_UCSZ0_BIT);
    SET_BIT(Local_UCSRC_var,UCSRC_UCSZ1_BIT);
    CLR_BIT(UART_u8_UCSRB_REG,UCSRB_UCSZ2_BIT);
    #elif UART_CHARCHTER_SIZE == UART_CHARCHTER_SIZE_9
    SET_BIT(Local_UCSRC_var,UCSRC_UCSZ0_BIT);
    SET_BIT(Local_UCSRC_var,UCSRC_UCSZ1_BIT);
    SET_BIT(UART_u8_UCSRB_REG,UCSRB_UCSZ2_BIT);
    #endif
    UART_u8_UCSRC_REG=Local_UCSRC_var; 

}

void UART_voidSetBudRate(u16 Copy_u8BudRate)
{
    switch (Copy_u8BudRate)
    {
    case 9600:
        UART_u8_UBRRL_REG=UART_BUD_RATE_9600;
        break;
    
    case 4800:
        UART_u8_UBRRL_REG=UART_BUD_RATE_4800;
        break;

    case 2400:
        UART_u8_UBRRL_REG=UART_BUD_RATE_2400;
        break;
    
    default:
        break;
    }
}

void UART_voidRXCInterrupt(Interrapt_Mode Copy_eMode)
{
    switch (Copy_eMode)
    {
    case Enable:
        SET_BIT(UART_u8_UCSRB_REG,UCSRB_RXCIE_BIT);
        break;
    
    case Disable:
        CLR_BIT(UART_u8_UCSRB_REG,UCSRB_RXCIE_BIT);
        break;
    }
}

void UART_voidTXCInterrupt(Interrapt_Mode Copy_eMode)
{
        switch (Copy_eMode)
    {
    case Enable:
        SET_BIT(UART_u8_UCSRB_REG,UCSRB_TXCIE_BIT);
        break;
    
    case Disable:
        CLR_BIT(UART_u8_UCSRB_REG,UCSRB_TXCIE_BIT);
        break;
    }
}

void UART_voidUDREInterrupt(Interrapt_Mode Copy_eMode)
{
        switch (Copy_eMode)
    {
    case Enable:
        SET_BIT(UART_u8_UCSRB_REG,UCSRB_UDRIE_BIT);
        break;
    
    case Disable:
        CLR_BIT(UART_u8_UCSRB_REG,UCSRB_UDRIE_BIT);
        break;
    }
}

void UART_voidSendData(u8 Copy_u8Data)
{
    while(!GET_BIT(UART_u8_UCSRA_REG,UCSRA_UDRE_BIT));
    UART_u8_UDR_REG=Copy_u8Data;
}

u8 UART_u8ResciveData(void)
{
    while(!GET_BIT(UART_u8_UCSRA_REG,UCSRA_RXC_BIT));
    return UART_u8_UDR_REG;
}
u8 UART_u8GetData(void)
{
	return UART_u8_UDR_REG;
}

/*------------------UART Enterrupts Functions------------------*/
//RX Complete Interrupt Functions
void UART_RXCSetCallBack(void (* Copy_pvRXCIFunc)(void))
{
   UART_pvRXCIFunc = Copy_pvRXCIFunc;
}

void __vector_13(void)  __attribute__((signal));
void __vector_13(void)
{
    if(UART_pvRXCIFunc != NULL)
    {
        UART_pvRXCIFunc();
    }
    else
    {
        /*Do nothing*/
    }
}

//TX Complete Interrupt Functions
void UART_TXCSetCallBack(void (* Copy_pvTXCIFunc))
{
   UART_pvTXCIFunc = Copy_pvTXCIFunc;
}

void __vector_15(void)  __attribute__((signal));
void __vector_15(void)
{
    if(UART_pvTXCIFunc != NULL)
    {
        UART_pvTXCIFunc();
    }
    else
    {
        /*Do nothing*/
    }
}

//UDR Empty Interrupt Functions
void UART_UDRESetCallBack(void (* Copy_pvUDREIFunc))
{
   UART_pvUDREIFunc = Copy_pvUDREIFunc;
}

void __vector_14(void)  __attribute__((signal));
void __vector_14(void)
{
    if(UART_pvUDREIFunc != NULL)
    {
        UART_pvUDREIFunc();
    }
    else
    {
        /*Do nothing*/
    }
}
