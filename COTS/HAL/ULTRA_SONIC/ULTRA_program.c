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
/* to know exact time */
static u8 ovf_counter = 0;
static u8 trig_flag=0;
/* flag to switch edges */
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
		/* reading ICR value */
		ICR_reading_1= ICU_u16ICR();

		/* changing edge */
		ICU_voidSetEdge(FALLING);

		/* clear ovf counter */
		ovf_counter=0;

		/* set flag to 1  */
		flag =1;
	}
	else if(flag==1)
	{
		ICR_reading_2 = ICU_u16ICR();
		ICU_voidSetEdge(RISING);
		flag = 0;
		trig_flag=0;
		/* calculate distance  */
		distance= ((ICR_reading_2 + (65535UL*ovf_counter) -ICR_reading_1)*0.0043)/2;
	}

}

void ovf_call()
{

	if(trig_flag==0)
	{
		DIO_voidSetPinValue(PORT_u8C, PIN3,PIN_HIGH);
		_delay_us(10);
		DIO_voidSetPinValue(PORT_u8C, PIN3,PIN_LOW);
		trig_flag=1;
	}
	else if(trig_flag==1)
	{
		ovf_counter++;
	}
}
void ULTRA_Init(void)
{
	TIMER1_voidSetCallBackOVF(&ovf_call);
	ICU_voidSetCallBack(&ULTRA_measure);
	ICU_voidEnable();

}
u8 ULTRA_reading(){

	return distance;
}
