/*=======================================================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*=======================================================================*/
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER0/TIMER0_interface.h"
/*=======================================================================*/
#include "MOTOR_config.h"
#include "MOTOR_interface.h"
#include "MOTOR_private.h"
/*======================================================================*/

void MD_voidMotorsInit(void)
{
	DIO_voidSetPinDirection(MD_DIRECTION_PORT,MOTOR1_FORWARD_PIN,PIN_OUT);
	DIO_voidSetPinDirection(MD_DIRECTION_PORT,MOTOR1_BACKWARD_PIN,PIN_OUT);
	DIO_voidSetPinDirection(MD_DIRECTION_PORT,MOTOR2_FORWARD_PIN,PIN_OUT);
	DIO_voidSetPinDirection(MD_DIRECTION_PORT,MOTOR2_BACKWARD_PIN,PIN_OUT);
	DIO_voidSetPinDirection(PORT_u8B, PIN3, PIN_OUT);/*ocr0 pin*/
	TIMER0_voidSetOcrTicks(150);
	FASTPWM_voidInvOrNoninv(NON_INV);
	TIMER0_voidInit();

}

void MD_voidMoveForward(void)
{
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_FORWARD_PIN,PIN_HIGH);
    DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_BACKWARD_PIN,PIN_LOW);
    DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_FORWARD_PIN,PIN_HIGH);
    DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_BACKWARD_PIN,PIN_LOW);
}

void MD_voidMoveBackward(void)
{
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_FORWARD_PIN,PIN_LOW);
    DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_BACKWARD_PIN,PIN_HIGH);
    DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_FORWARD_PIN,PIN_LOW);
    DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_BACKWARD_PIN,PIN_HIGH);
}

void MD_voidStop(void)
{
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_FORWARD_PIN,PIN_LOW);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_BACKWARD_PIN,PIN_LOW);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_FORWARD_PIN,PIN_LOW);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_BACKWARD_PIN,PIN_LOW);
}

void MD_voidMoveLeft(void)
{
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_FORWARD_PIN,PIN_LOW);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_BACKWARD_PIN,PIN_HIGH);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_FORWARD_PIN,PIN_HIGH);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_BACKWARD_PIN,PIN_LOW);
}

void MD_voidMoveRight(void)
{
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_FORWARD_PIN,PIN_HIGH);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR1_BACKWARD_PIN,PIN_LOW);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_FORWARD_PIN,PIN_LOW);
	DIO_voidSetPinValue(MD_DIRECTION_PORT,MOTOR2_BACKWARD_PIN,PIN_HIGH);
}
void MD_voidMotorSpeed(u8 speed)
{
    TIMER0_voidSetOcrTicks(speed);
}

