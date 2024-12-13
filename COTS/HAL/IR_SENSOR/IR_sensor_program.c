/*============================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/*============================================*/
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
/*============================================*/
#include "../MOTOR/MOTOR_interface.h"
/*============================================*/
#include "IR_sensor_config.h"
#include "IR_sensor_interface.h"
/*===========================================*/
#include <util/delay.h>
/*===========================================*/
static u8 IR_flag=0;
void IR_CallBack(void)
{
	if(IR_flag==0)
	{
		EXTI_voidSetSenseCtrl(INT0, LOW_LEVEL);
		IR_flag=1;
		MD_voidMoveRight();
		//_delay_ms(2000);
		MD_voidMoveLeft();
		//_delay_ms(4000);
	}
	else
	{
		EXTI_voidSetSenseCtrl(INT0, RISING_EDGE);;
		IR_flag=0;
		MD_voidMoveForward();
	}
}


void IR_sensor_voidInit()
{
	EXTI_voidEnableDisable(INT0, ENABLED);
	EXTI_voidSetSenseCtrl(INT0,RISING_EDGE);
	EXTI_voidSetCallBack(INT0, &IR_CallBack);
}

void IR_sensor_voidDisable()
{
	EXTI_voidEnableDisable(INT0, DISABLED);

}
