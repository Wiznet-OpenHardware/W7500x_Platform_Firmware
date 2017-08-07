/*
 * hw_def.h
 *
 *  Created on: Aug 3, 2017
 *      Author: Kei
 */

#ifndef SRC_HW_HW_DEF_H_
#define SRC_HW_HW_DEF_H_

#include "W7500x_gpio.h"

/* CHIP Define */
#define W7500 0
#define W7500P 1

#define USING_CHIP W7500

/* UART */
#define UART0_BUF_SIZE   1024
#define UART1_BUF_SIZE   1024
#define EX_UART_BUF_SIZE 1024

//#define USE_UART0
#define USE_UART1
#define USE_EX_UART_AS_DATA

#ifdef USE_UART0
#define UART0_RTS_PIN               GPIO_Pin_12
#define UART0_RTS_PORT              GPIOA
#define UART0_RTS_PAD_AF            PAD_AF1 // 2nd function, GPIO
#define UART0_CTS_PIN               GPIO_Pin_11
#define UART0_CTS_PORT              GPIOA
#define UART0_CTS_PAD_AF            PAD_AF1 // 2nd function, GPIO
#endif
#ifdef USE_UART1
#define UART1_RTS_PIN               GPIO_Pin_1
#define UART1_RTS_PORT              GPIOC
#define UART1_RTS_PAD_AF            PAD_AF1 // 2nd function, GPIO
#define UART1_CTS_PIN               GPIO_Pin_7
#define UART1_CTS_PORT              GPIOA
#define UART1_CTS_PAD_AF            PAD_AF1 // 2nd function, GPIO
#endif

#endif /* SRC_HW_HW_DEF_H_ */
