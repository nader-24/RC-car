/*
 * ULTRA_interface.h
 *
 *  Created on: 9 Dec 2024
 *      Author: nader
 */

#ifndef COTS_HAL_ULTRA_SONIC_ULTRA_INTERFACE_H_
#define COTS_HAL_ULTRA_SONIC_ULTRA_INTERFACE_H_



#ifndef ULTA_H_
#define ULTA_H_

typedef enum{
	LEFT = 2,
	MID,
	RIGHT
}sonic_e;
void ULTRA_Init(void);

void ULTRA_measure(void);

u8 ULTRA_reading();
#endif /* ULTA_H_ */


#endif /* COTS_HAL_ULTRA_SONIC_ULTRA_INTERFACE_H_ */
