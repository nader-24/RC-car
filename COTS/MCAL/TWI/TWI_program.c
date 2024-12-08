/*
 * TWI_program.c
 *
 *  Created on: 2 Nov 2024
 *      Author: nader
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_config.h"
#include "TWI_interface.h"
#include "TWI_private.h"

void TWI_voidInitSlave(u8 Copy_u8SlaveAddress)
{
	TWAR =Copy_u8SlaveAddress;
	SET_BIT(TWCR,TWCR_TWEA);
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidInitMaster(u8 Copy_u8SlaveAddress)
{
	TWAR =Copy_u8SlaveAddress;
	SET_BIT(TWCR,TWCR_TWEA);

	/* clock*/
	TWBR = 12;
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	/* enable pref */
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidSendStartCondition(void)
{
	SET_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);
}

void TWI_voidSendStopCondition(void)
{
	SET_BIT(TWCR,TWCR_TWSTO);
}

void TWIvoidSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWDR = (Copy_u8SlaveAddress << 1 );
	SET_BIT(TWDR,0);
	CLR_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

}

void TWIvoidSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWDR = (Copy_u8SlaveAddress << 1 );
	CLR_BIT(TWDR,0);
	CLR_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

}

void TWI_voidSendData(u8 Copy_u8Data)
{
	TWDR = Copy_u8Data;
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);
}

u8 TWI_u8ReceiveData(void)
{
	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);
	return TWDR;
}
