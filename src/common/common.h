#ifndef _COMMON_H
#define _COMMON_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

//#define USE_DEBUG_PRINT

/* Macro */
#ifdef USE_DEBUG_PRINT
#define WIZ_PRINT(fmt,...) printf(fmt,##__VA_ARGS__)
#else
#define WIZ_PRINT(fmt,...)
#endif

/* On/Off Status */
typedef enum
{
	OFF		= 0,
	ON		= 1
} OnOff_State_Type;

#define RET_OK			0
#define RET_NOK			-1
#define RET_TIMEOUT		-2
#define ERR_PARAM       -3

#endif //_COMMON_H
