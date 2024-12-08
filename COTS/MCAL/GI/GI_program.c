/*
 * GI_program.c
 *
 *  Created on: 28 Sep 2024
 *      Author: nader
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GI_interface.h"
#include "GI_private.h"


void GI_voidEnable(void)
{
	SET_BIT(SREG, SREG_I);
}
void GI_voidDisable(void)
{
	CLR_BIT(SREG, SREG_I);
}
