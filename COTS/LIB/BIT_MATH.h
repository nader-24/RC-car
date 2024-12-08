#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

/* set bit */

#define SET_BIT(REG, BIT_NUM) (REG |= (1 << BIT_NUM))

/* clear bit */

#define CLR_BIT(REG, BIT_NUM) (REG &= (~(1 << BIT_NUM)))

/* toggle bit */

#define TOG_BIT(REG, BIT_NUM) (REG ^= (1 << BIT_NUM))

/* get bit */

#define GET_BIT(REG, BIT_NUM) ((REG >> BIT_NUM) & 0x01)

#endif