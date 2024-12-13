/*
 * EEPROM_interface.h
 *
 *  Created on: 2 Nov 2024
 *      Author: nader
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_
#define DEVICE1    0
#define DEVICE2    1

void EEPROM_voidWriteByte(u8 Copy_u8Device,
		u16 Copy_u16Location,
		u8 Copy_u8Data);
u8 EEPROM_u8ReadByte(u8 Copy_u8Device,
		u16 Copy_u16Location );


#endif /* EEPROM_INTERFACE_H_ */
