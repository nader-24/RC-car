/*=========================================*/
#include <util/delay.h>
/*===============================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/ICU/ICU_interface.h"
#include "../../MCAL/GI/GI_interface.h"
/*=========================================*/
#include "ULTRA_interface.h"
/*=========================================*/

/*==============================*/
static u8 flag =0;
static u8 distance = 0;

/* reading of icu */
u16 ICR_reading_1 = 0;
u16 ICR_reading_2 = 0;
/*=============================*/
void ULTRA_measure(void)
{
	if(flag == 0)
	{
		ICR_reading_1= ICU_u16ICR();
		ICU_voidSetEdge(FALLING);
		flag++;
	}
	else
	{
		ICR_reading_2 = ICU_u16ICR();
		ICU_voidSetEdge(RISING);
		distance= ((ICR_reading_2 -ICR_reading_1)*0.0043)/2;
		flag = 0;

	}

}

void ovf_call()
{
	DIO_voidSetPinValue(PORT_u8C, PIN4,PIN_HIGH);
	_delay_us(10);
	DIO_voidSetPinValue(PORT_u8C, PIN4,PIN_LOW);


}
void ULTRA_Init(void)
{
	DIO_voidSetPinDirection(PORT_u8C, PIN4, PIN_OUT);
	TIMER1_voidSetCallBackOVF(&ovf_call);
	ICU_voidSetCallBack(&ULTRA_measure);
	ICU_voidSetPrecaller(NO_PRE_SCALLER);
	ICU_voidSetEdge(RISING);
	ICU_voidEnable();
	TIMER1_voidInit();

}
void ULTRA_Disable(void)
{
	TIMER1_voidDisable();
	ICU_voidDisable();
}
u8 ULTRA_reading(){

	return distance;
}
