/*
 * EEPROM_program.c
 *
 *  Created on: 2 Nov 2024
 *      Author: nader
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "EEPROM_interface.h"
#include <util/delay.h>


void EEPROM_voidWriteByte(u8 Copy_u8Device,
		u16 Copy_u16Location,
		u8 Copy_u8Data)
{
	u8 copy_u8Address = (0b01010000) |
			(Copy_u8Device<<2) |
			(Copy_u16Location>>8);
	TWI_voidSendStartCondition();
	TWIvoidSendSlaveAddressWithWrite(copy_u8Address);
	TWI_voidSendData((u8)Copy_u16Location);
	TWI_voidSendData(Copy_u8Data);
	TWI_voidSendStopCondition();
	_delay_ms(10);

}


u8 EEPROM_u8ReadByte(u8 Copy_u8Device,
		u16 Copy_u16Location )
{
	u8 local_u8Data =0;

	u8 copy_u8Address = (0b01010000) |
			(Copy_u8Device<<2) |
			(Copy_u16Location>>8);
	TWI_voidSendStartCondition();
	TWIvoidSendSlaveAddressWithWrite(copy_u8Address);
	TWI_voidSendData((u8)Copy_u16Location);
	TWI_voidSendStartCondition();
	TWIvoidSendSlaveAddressWithRead(copy_u8Address);
	local_u8Data = TWI_u8ReceiveData();
	TWI_voidSendStopCondition();
	return local_u8Data;
}
