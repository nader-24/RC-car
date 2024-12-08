/********************************************************************************/
/********************************************************************************/
/************************** Layer   : MCAL         ******************************/
/************************** SWC     : DIO          ******************************/
/************************** DATE    : 7 sep 2024   ******************************/
/************************** VERSION : 1.0.0        ******************************/
/************************** AUTHOR  : Nader Ashraf ******************************/
/********************************************************************************/
/********************************************************************************/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

void DIO_voidSetPortDirection(u8 Copy_u8PortNum, u8 Copy_u8PortDirection);
void DIO_voidSetPinDirection(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8PinDirection);

void DIO_voidSetPortValue(u8 Copy_u8PortNum, u8 Copy_u8PortValue);
void DIO_voidSetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum,u8 Copy_u8PinValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum);
u8 DIO_u8GetPortValue(u8 Copy_u8PortNum);


#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define PORT_u8A   1
#define PORT_u8B   2
#define PORT_u8C   3
#define PORT_u8D   4


#define PIN_OUT   1
#define PIN_IN    0

#define PIN_HIGH  1
#define PIN_LOW   0

#define PORT_HIGH 0xFF
#define PORT_LOW  0x00

#define PORT_OUT 0xFF
#define PORT_IN  0x00



#endif