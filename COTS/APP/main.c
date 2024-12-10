/*
 * main.c
 *
 *  Created on: 8 Dec 2024
 *      Author: nader
 */

/*==================================*/
#include <util/delay.h>
/*=======================================*/
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/*=======================================*/
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/GI/GI_interface.h"
#include "../MCAL/ICU/ICU_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/TIMER1/TIMER1_interface.h"
#include "../MCAL/UART/UART_int.h"
#include "../MCAL/TWI/TWI_interface.h"
/*=======================================*/
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/ULTRA_SONIC/ULTRA_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"
/*=======================================*/

u8 distance_ultra[3]={0};
u8 ultra_index =0;
u8 trig=0b00011100;
/*=======================================*/


/*=======================================*/
/*====GLOBal FLAGS====*/
volatile u8 bluetooth_flag=0;

/*====================*/
void motor_control(void)
{
	u8 flag = UART_u8GetData();
	if(bluetooth_flag == 1)
	{

		switch (flag)
		{
		case '0':
			MD_voidMotorSpeed(128);
			break;
		case '5':
			MD_voidMotorSpeed(255);
			break;
		case 'F':
			MD_voidMoveForward();
			break;
		case 'L':
			MD_voidMoveLeft();
			break;
		case 'R':
			MD_voidMoveRight();
			break;
		case 'B':
			MD_voidMoveBackward();
			break;
		case 'S':
			MD_voidStop();
			break;
		case 'x':
			bluetooth_flag=0;
			DIO_voidSetPinValue(PORT_u8B, PIN0, PIN_LOW);
			break;
		}
	}
	else if(flag=='X')
	{
		bluetooth_flag=1;
		DIO_voidSetPinValue(PORT_u8B, PIN0, PIN_HIGH);
	}


}


/*===========================*/

/*=============================*/



void main (void)
{
	/* pins init  */
	/* bt led indication portb pin 0 */
	DIO_voidSetPinDirection(PORT_u8B, PIN0, PIN_OUT);

	/*  uart pins portd pin0,pin1 */
	DIO_voidSetPinDirection(PORT_u8D, PIN0, PIN_IN);
	DIO_voidSetPinDirection(PORT_u8D, PIN1, PIN_OUT);

	/*IR pin int2 portd pin2*/
	DIO_voidSetPinDirection(PORT_u8B, PIN2, PIN_IN);

	/* I2c BUS pins scl output  */
	DIO_voidSetPinDirection(PORT_u8C, PIN0, PIN_OUT);

	/* ICP input portd pin6 */
	DIO_voidSetPinDirection(PORT_u8D, PIN6, PIN_IN);

	/* LCD pins init portc data
	 * portc pin 7 pin6 pin5 control */
	DIO_voidSetPortDirection(PORT_u8A, PORT_OUT);
	DIO_voidSetPinDirection(PORT_u8C, PIN7, PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8C, PIN6, PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8C, PIN5, PIN_OUT);

	/* OCR0 output  */
	DIO_voidSetPinDirection(PORT_u8B, PIN3, PIN_OUT);

	/* Ultrasonic trig pins out */
	DIO_voidSetPinDirection(PORT_u8C, PIN4, PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8C, PIN3, PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8C, PIN2, PIN_OUT);

	/*  motor portD
	 * pin3 * pin4 * pin5 * pin7  */
	DIO_voidSetPinDirection(PORT_u8D, PIN3, PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8D, PIN4, PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8D, PIN5, PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8D, PIN7, PIN_OUT);


	/*ICU call_back*/


	/* timer0 ovf callback */


	/*  peripherials enables */
	GI_voidEnable();
	ICU_voidEnable();
	TIMER0_voidInit();
	TIMER1_voidInit();
	UART_voidRXCInterrupt(Enable);
	ULTRA_Init();
	UART_voidSetBudRate(9600);
	UART_voidUDREInterrupt(Enable);
	UART_voidInit();

	UART_RXCSetCallBack(motor_control);
	ICU_voidSetPrecaller(NO_PRE_SCALLER);
	ICU_voidSetEdge(RISING);
	//ICU_voidSetCallBack(&ultra_measure);
	FASTPWM_voidInvOrNoninv(NON_INV);
	TIMER0_voidSetOcrTicks(200);
	CLCD_voidInit();

	while(1)
	{
		CLCD_voidSendNum(ULTRA_reading());

		CLCD_voidSetPosition(0, 0);
		CLCD_u8SendString("     ");
		CLCD_voidSetPosition(0, 0);
	}

}














