/*
 * UART_interface.h
 *
 *  Created on: 25 Oct 2024
 *      Author: nader
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_voidInit();

void UART_voidSendByte(u8 Copy_u8Data);

u8 UART_u8ReceiveByte();



#endif /* UART_INTERFACE_H_ */
