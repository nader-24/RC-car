/*
 * UART_program.c
 *
 *  Created on: 25 Oct 2024
 *      Author: nader
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"

void UART_voidInit()
{
	u8 Local_u8Var=0;
	//no parity
	//uart -> not usart
	//one stop bit
	//Ch size : 8bits
	SET_BIT(Local_u8Var,UCSRC_URSEL);
	CLR_BIT(Local_u8Var,UCSRC_UPM0);
	CLR_BIT(Local_u8Var,UCSRC_UPM1);
	CLR_BIT(Local_u8Var,UCSRC_UMSEL);
	CLR_BIT(Local_u8Var,UCSRC_USBS);
	SET_BIT(Local_u8Var,UCSRC_UCSZ0);
	SET_BIT(Local_u8Var,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	UCSRC = Local_u8Var;
	//baud rate ->9600
	UBRRL=51;
	//no interrupt
	//DEFAULT Disabled
	//full duplex
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
}
void UART_voidSendByte(u8 Copy_u8Data)
{
	//Wait -> polling UDRE
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);
	UDR=Copy_u8Data;
}

u8 UART_u8ReceiveByte()
{
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;
}
