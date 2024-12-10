/*===============================================*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/ICU/ICU_interface.h"
#include "../../MCAL/GI/GI_interface.h"
/*=========================================*/
#include <util/delay.h>
/*=========================================*/
#include "ULTRA_interface.h"
/*=========================================*/




#define ECHO_PIN       PIN6
/*==============================*/
/* to know exact time */
u8 ovf_counter = 0;

/* flag to switch edges */
u8 flag =0;
u8 trig_flag=0;
u8 distance = 0;
u8 temp[3]={0};


u8 ultra_switching =0;
/* reading of icu */
u16 ICR_reading_1 = 0;
u16 ICR_reading_2 = 0;
/*=============================*/
void ULTRA_measure(void)
{
	static u8 i =0;
	if(trig_flag==1)
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

			/* calculate distance  */
			temp[i]= ((ICR_reading_2 + (65535UL*ovf_counter) -ICR_reading_1)*0.0043)/2;
			i++;
			if(i==3){i=0;}
			TIMER1_voidSetPreLoad(0);
			trig_flag=2;
		}
	}
}

void ovf_call()
{
	if(trig_flag==0)
	{
		switch (ultra_switching)
		{
		case 0:
			DIO_voidSetPinValue(PORT_u8C, PIN4,PIN_HIGH);
			_delay_us(10);
			DIO_voidSetPinValue(PORT_u8C, PIN4,PIN_LOW);
			ultra_switching=1;
			break;
		case 1:
			DIO_voidSetPinValue(PORT_u8C, PIN3,PIN_HIGH);
			_delay_us(10);
			DIO_voidSetPinValue(PORT_u8C, PIN3,PIN_LOW);
			ultra_switching=2;
			break;
		case 2:
			DIO_voidSetPinValue(PORT_u8C, PIN2,PIN_HIGH);
			_delay_us(10);
			DIO_voidSetPinValue(PORT_u8C, PIN2,PIN_LOW);
			ultra_switching=0;
			break;
		}
		trig_flag=1;
	}
	else if(trig_flag==2)
	{
		trig_flag=0;
	}
	else
	{
		ovf_counter++;
	}
}
void ULTRA_Init(void)
{
	TIMER1_voidSetCallBackOVF(&ovf_call);
	ICU_voidSetCallBack(&ULTRA_measure);

}
u8 ULTRA_reading(){
	for(u8 iterator = 0;iterator<2;iterator++)
	{
		if(temp[iterator]<temp[iterator+1])
		{
			distance=temp[iterator];
		}
	}
return distance;
}
