/*
 * UartTest.h
 *
 *  Created on: Jul 27, 2017
 *      Author: Kei
 */

#ifndef TESTSUITE_UARTTEST_H_
#define TESTSUITE_UARTTEST_H_

#include "common.h"

void initUartTestSuite(uint8_t uart_ch);
void doUartLoopback(uint8_t uart_ch);

void initExUartTestSuite(void);
void doExUartLoopback(void);

#endif /* TESTSUITE_UARTTEST_H_ */
