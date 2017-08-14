/*
 * gpioTest.c
 *
 *  Created on: Aug 3, 2017
 *      Author: Kei
 */

#include "common.h"
#include "hw.h"

/* private functions */
void delayMsForGpioTest(uint16_t millisecond);

void initGpioTestSuite(void)
{
    initGpioPin(PORT_C, 5, OUTPUT, PULL_UP);
    initGpioPin(PORT_C, 8, OUTPUT, PULL_UP);
    initGpioPin(PORT_C, 9, OUTPUT, PULL_UP);

    setGpioPin(PORT_C, 5, HIGH);
    setGpioPin(PORT_C, 8, HIGH);
    setGpioPin(PORT_C, 9, HIGH);
}

void doGpioPinBlynk(void)
{
    setGpioPin(PORT_C, 5, LOW);
    delayMsForGpioTest(500);
    setGpioPin(PORT_C, 5, HIGH);
    setGpioPin(PORT_C, 8, LOW);
    delayMsForGpioTest(500);
    setGpioPin(PORT_C, 8, HIGH);
    setGpioPin(PORT_C, 9, LOW);
    delayMsForGpioTest(500);
    setGpioPin(PORT_C, 9, HIGH);
}

void delayMsForGpioTest(uint16_t millisecond)
{
    volatile uint32_t clk_cnt;

    clk_cnt = millisecond * (GetSystemClock() / 1000 / 10);
    while (clk_cnt--)
        ;
}
