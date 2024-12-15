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
#include "../MCAL/EXTI/EXTI_interface.h"
/*=======================================*/
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/ULTRA_SONIC/ULTRA_interface.h"
#include "../HAL/MOTOR/MOTOR_interface.h"
#include "../HAL/IR_SENSOR/IR_sensor_interface.h"
#include "../HAL/EEPROM/EEPROM_interface.h"
/*=======================================*/
/*====GLOBAL FLAGS====*/
u8 bluetooth_flag=1;
u8 obstacle_counter=0;
u8 obstacle_flag=0;

u8 ultra_distance=255;
/*=======================================*/
void switch_mode(void)
{
	if(bluetooth_flag==0)
	{
		bluetooth_flag=1;
		IR_sensor_voidDisable();
		ULTRA_Disable();
	}
	else
	{
		bluetooth_flag=0;
		IR_sensor_voidInit();
		ULTRA_Init();
	}
}

/*=======================================*/


/*====================*/
void motor_control(void)
{
	u8 uart_flag = UART_u8GetData();
	if(bluetooth_flag == 1)
	{

		switch (uart_flag)
		{
		case '0':
			MD_voidMotorSpeed(128);
			break;
		case '9':
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
			IR_sensor_voidInit();
			break;
		case 'V':
			EEPROM_voidWriteByte(DEVICE1,250,0);
			obstacle_counter=0;
			CLCD_voidSetPosition(6, 1);
			CLCD_voidSendNum(obstacle_counter);
			break;
		}
	}
	else if(uart_flag=='X')
	{
		bluetooth_flag=1;
		IR_sensor_voidDisable();
		DIO_voidSetPinValue(PORT_u8B, PIN0, PIN_HIGH);
	}


}


/*===========================*/
/* system init function */
/*=============================*/
void system_init(void)
{
	/* pins init */
	/* bt led indication portb pin 0 */
	DIO_voidSetPinDirection(PORT_u8B, PIN0, PIN_OUT);

	/*  uart pins portd pin0,pin1 */
	DIO_voidSetPinDirection(PORT_u8D, PIN0, PIN_IN);
	DIO_voidSetPinDirection(PORT_u8D, PIN1, PIN_OUT);

	/*IR pin in0 portd pin2*/
	DIO_voidSetPinDirection(PORT_u8D, PIN2, PIN_IN);

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




	/* EXINT2 Switch*/
	DIO_voidSetPinDirection(PORT_u8B,PIN2,PIN_IN);
	DIO_voidSetPinValue(PORT_u8B,PIN2,PIN_HIGH);
	/*  peripherials enables */



	CLCD_voidInit();
	/*  peripherials enables */
	ULTRA_Init();

	UART_voidRXCInterrupt(Enable);

	UART_voidSetBudRate(9600);
	UART_voidUDREInterrupt(Enable);
	UART_voidInit();

	TWI_voidInitMaster(0);
	obstacle_counter=EEPROM_u8ReadByte(DEVICE1,250);
	UART_RXCSetCallBack(motor_control);
	EXTI_voidEnableDisable(INT2,ENABLED);
	EXTI_voidSetSenseCtrl(INT2,FALLING_EDGE);
	EXTI_voidSetCallBack(INT2,&switch_mode);

	/* writing obstacle to lcd*/
	CLCD_u8SendString("Obstacle ");
	CLCD_voidSetPosition(6, 1);
	CLCD_voidSendNum(obstacle_counter);

	MD_voidMotorsInit();

	GI_voidEnable();
}


void main (void)
{
	system_init();
	while (1)
	{
	    // Read distance from ultrasonic sensor
	    u8 ultra_distance = ULTRA_reading();

	    // Check if an obstacle is detected and Bluetooth flag is inactive
	    if (ultra_distance < 7 && bluetooth_flag == 0)
	    {
	        if (obstacle_flag == 0)
	        {
	            // Stop the motor as an obstacle is detected
	            MD_voidStop();

	            // Increment the obstacle counter
	            obstacle_counter++;

	            // Save the updated counter value to EEPROM
	            EEPROM_voidWriteByte(DEVICE1, 250, obstacle_counter);

	            // Set the obstacle flag to prevent repeated actions
	            obstacle_flag = 1;

	            // Update the obstacle counter on the LCD display
	            CLCD_voidSetPosition(6, 1);
	            CLCD_voidSendNum(obstacle_counter);
	        }
	    }
	    else if (ultra_distance > 12)
	    {
	        // Reset the obstacle flag when the path is clear
	        obstacle_flag = 0;
	    }
	}


}














