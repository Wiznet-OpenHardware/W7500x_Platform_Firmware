/*
 * ex_uartHandler.h
 *
 *  Created on: Jul 19, 2017
 *      Author: Kei
 */

#ifndef EX_UARTHANDLER_H_
#define EX_UARTHANDLER_H_

#include "common.h"

#ifndef EX_UART_BUF_SIZE
#define EX_UART_BUF_SIZE 1024
#endif

extern uint8_t flag_ex_uart_ringbuf_full;

void initExUart(uint32_t baud);

int32_t writeExUartData(uint8_t *send_buf, uint16_t length);
int32_t readExUartData(uint8_t *recv_buf, uint16_t length);
int32_t getExUartReceivedDataSize(void);

void handleExUartIRQ(void);

#endif /* EX_UARTHANDLER_H_ */
