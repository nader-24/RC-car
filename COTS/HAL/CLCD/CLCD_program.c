/*==============================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*==============================================*/
#include "../../MCAL/DIO/DIO_interface.h"
/*==============================================*/
#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include <util/delay.h>
/*==============================================*/

static void CLCD_voidSendData (u8 Copy_u8Data)
{
	//RS-> 1 , RW=0
	//SET data -> data port
	// enable pulse

	DIO_voidSetPinValue(CTRL_PORT, RS, PIN_HIGH);
	DIO_voidSetPinValue(CTRL_PORT, RW, PIN_LOW);

	DIO_voidSetPortValue(DATA_PORT, Copy_u8Data);
	// enable pulse
	DIO_voidSetPinValue(CTRL_PORT, EN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT, EN, PIN_LOW);


}
static void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	DIO_voidSetPinValue(CTRL_PORT, RS, PIN_LOW);
	DIO_voidSetPinValue(CTRL_PORT, RW, PIN_LOW);

	DIO_voidSetPortValue(DATA_PORT, Copy_u8Command);
	// enable pulse
	DIO_voidSetPinValue(CTRL_PORT, EN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CTRL_PORT, EN, PIN_LOW);
}
void CLCD_voidInit(void)
{
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	_delay_ms(1);
	CLCD_voidSendCommand(0b00001100);
	_delay_ms(1);
	CLCD_voidSendCommand(1);
	_delay_ms(2);
}

void CLCD_u8SendString(char *pCopyString)
{
	u8 Local_u8Iterator = 0;
	while(pCopyString[Local_u8Iterator] != '\0')
	{

		CLCD_voidSendData(pCopyString[Local_u8Iterator]);
		Local_u8Iterator++;

	}
}

void CLCD_voidSetPosition(u8 Copy_u8x, u8 Copy_u8y)
{
	u8 Local_u8Position = 0;
	switch (Copy_u8y)
	{
	case 0: Local_u8Position = Copy_u8x;break;
	case 1: Local_u8Position = Copy_u8x + LINE1_BASE; break;

	}
	CLCD_voidSendCommand(Local_u8Position + DDRAM_MSB);
}

void CLCD_voidClearDisplay(void)
{
	CLCD_voidSendCommand(CLEAR_DISPLAY);
	_delay_ms(2);
}



void CLCD_voidSendSpecialChar(u8 Copy_u8BlockNum,
		u8 *Pu8ArrayPattern,
		u8 Copy_u8x,
		u8 Copy_u8y)
{
	u8 Local_u8Position = Copy_u8BlockNum * 8;
	// Go to CG_RAM
	CLCD_voidSendCommand((Local_u8Position + CGRAM_MSB));
	// Start Drawing pattern

	for (u8 i =0 ;i<8;i++)
	{
		CLCD_voidSendData(Pu8ArrayPattern[i]);
	}

	CLCD_voidSetPosition(Copy_u8x, Copy_u8y);
	CLCD_voidSendData(Copy_u8BlockNum);

}

void CLCD_voidSendNum(u16 Copy_u16Num)
{
	s8 Local_u8Iterator = 0;
	char Local_charNum[6];
	do
	{
		Local_charNum[Local_u8Iterator] = (Copy_u16Num % 10) +'0';
		Copy_u16Num/=10;
		Local_u8Iterator++;

	}while(Copy_u16Num > 0);
	Local_u8Iterator--;
	for(;Local_u8Iterator>=0;Local_u8Iterator--)
	{
		CLCD_voidSendData(Local_charNum[Local_u8Iterator]);
	}
}
















