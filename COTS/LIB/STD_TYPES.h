#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_



typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef unsigned long long int u64;
typedef signed long long int s64;

typedef float f32;
typedef double f64;
typedef long double f128;



#define NULL 		(void *)0

typedef enum
{
	OK = 0,
	NOK,
	TIME_OUT_ERR,
	BUSY_STATE
}STD_err_e;


#endif
