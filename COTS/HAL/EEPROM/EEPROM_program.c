/*
 * EEPROM_program.c
 *
 *  Created on: 2 Nov 2024
 *      Author: nader
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TWI/TWI_interface.h"
#include "../../MCAL/GI/GI_interface.h"
#include "EEPROM_interface.h"
#include <util/delay.h>


void EEPROM_voidWriteByte(u8 device, u16 location, u8 data)
{
	GI_voidDisable();
    // Calculate the address for the EEPROM write operation
    u8 address = (0b01010000) |
                 ((device & 0x07) << 2) |  // Ensure the device value is within range
                 ((location >> 8) & 0x03); // Extract the upper 2 bits of the location

    // Start the I2C communication
    TWI_voidSendStartCondition();

    // Send the device address with write operation
    TWIvoidSendSlaveAddressWithWrite(address);

    // Send the memory location (lower 8 bits)
    TWI_voidSendData((u8)location);

    // Send the data byte to be written
    TWI_voidSendData(data);

    // Send stop condition to end communication
    TWI_voidSendStopCondition();

    // Delay to ensure EEPROM write cycle is complete (typically 5-10 ms)
    _delay_ms(12);
    GI_voidEnable();
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
