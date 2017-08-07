#ifndef __GPIOHANDLER_H__
#define __GPIOHANDLER_H__

#include <stdint.h>
#include "hw_def.h"

typedef enum
{
    INPUT = 0, OUTPUT = 1
} GpioDirection;

typedef enum
{
    LOW = 0, HIGH = 1
} GpioState;

typedef enum
{
    PORT_A = 0, PORT_B = 1, PORT_C = 2
} GpioPortNum;

typedef enum
{
    PULL_DOWN = 0,
    PULL_UP = 1
} GpioPullDownUp;

int32_t initGpioPin(uint8_t port, uint8_t pin, uint8_t direction,
        uint8_t mode);
int32_t setGpioPin(uint8_t port, uint8_t pin, uint8_t one_bit);
int32_t getGpioPinInputState(uint8_t port, uint8_t pin);
int32_t getGpioPinOutputState(uint8_t port, uint8_t pin);

#if (USING_CHIP == W7500P)
#define PORT_A_MAX_PIN 14
#define PORT_B_MAX_PIN 6
#elif (USING_CHIP == W7500)

#endif


#endif

