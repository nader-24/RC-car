#ifndef UART_INT_H
#define UART_INT_H
//=================================================================================================================
#define UART_BUD_RATE_9600      51
#define UART_BUD_RATE_4800      103
#define UART_BUD_RATE_2400      207
//=================================================================================================================
typedef enum{
            Disable = 0,
            Enable
}Interrapt_Mode;
//=================================================================================================================
void UART_voidInit(void);

void UART_voidSetBudRate(u16 Copy_u8BudRate);

void UART_voidRXCInterrupt(Interrapt_Mode Copy_eMode);

void UART_voidTXCInterrupt(Interrapt_Mode Copy_eMode);

void UART_voidUDREInterrupt(Interrapt_Mode Copy_eMode);

void UART_voidSendData(u8 Copy_u8Data);

u8 UART_u8ResciveData(void);

void UART_RXCSetCallBack(void (* Copy_pvRXCIFunc)(void));
//==================================================================================================================
#endif/*UART_INT_H*/
