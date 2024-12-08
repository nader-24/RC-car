/*
 * TWI_interface.h
 *
 *  Created on: 2 Nov 2024
 *      Author: nader
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidInitSlave(u8 Copy_u8SlaveAddress);
void TWI_voidInitMaster(u8 Copy_u8SlaveAddress);
void TWI_voidSendStartCondition(void);
void TWI_voidSendStopCondition(void);
void TWIvoidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
void TWIvoidSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
void TWI_voidSendData(u8 Copy_u8Data);
u8 TWI_u8ReceiveData(void);

#endif /* TWI_INTERFACE_H_ */
