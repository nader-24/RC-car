/*============================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*============================================*/
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
/*============================================*/
#include "../MOTOR/MOTOR_interface.h";
/*============================================*/
#include "IR_sensor_config.h"
#include "IR_sensor_interface.h"
/*===========================================*/


void IR_sensor_voidInit()
{
	DIO_voidSetPinDirection(IR_SENSOR_PORT,IR_SENSOR_PIN,PIN_IN);
}

void IR_sensor_voidGetValue()
{
	DIO_u8GetPinValue(IR_SENSOR_PORT,IR_SENSOR_PIN);
}

void IR_control()
{
	MD_voidMoveLeft();

}

