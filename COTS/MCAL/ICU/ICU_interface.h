/*
 * ICU_interface.h
 *
 *  Created on: 29 Nov 2024
 *      Author: nader
 */

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_
#define RISING  1
#define FALLING 0

typedef enum
{
	NO_PRE_SCALLER=1,
	DIV_8,
	DIV_64,
	DIV_256,
	DIV_1024
}PRE_SCALLER_e;

void ICU_voidEnable(void);
void ICU_voidDisable(void);

void ICU_voidSetPrecaller(PRE_SCALLER_e Copy_ePrescaller);
u16 ICU_u16ICR(void);
void ICU_voidSetEdge(u8 Copy_u8Egde);
void ICU_voidSetCallBack(void (*ptrfunc)(void));

#endif /* ICU_INTERFACE_H_ */
