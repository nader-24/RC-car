/********************************************************************************/
/********************************************************************************/
/************************** Layer   : HAL          ******************************/
/************************** SWC     : CLCD         ******************************/
/************************** DATE    : 13 sep 2024  ******************************/
/************************** VERSION : 1.0.0        ******************************/
/************************** AUTHOR  : Nader Ashraf ******************************/
/********************************************************************************/
/********************************************************************************/

#ifndef _CLCD_INTERFACE_H_
#define _CLCD_INTERFACE_H_


void CLCD_voidInit(void);
void CLCD_u8SendString(char *pCopyString);
void CLCD_voidSetPosition(u8 Copy_u8x, u8 Copy_u8y);
void CLCD_voidClearDisplay(void);
void CLCD_voidSendSpecialChar(u8 Copy_u8BlockNum,
		u8 *Pu8ArrayPattern,
		u8 Copy_u8x,
		u8 Copy_u8y);
void CLCD_voidSendNum(u16 Copy_u16Num);

#endif
