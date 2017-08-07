/*
 * ex_uartHandler.c
 *
 *  Created on: Jul 19, 2017
 *      Author: Kei
 */

#include <stdio.h>
#include <string.h>

#include "W7500x_uart.h"
#include "W7500x.h"

#include "hw.h"

#ifdef USE_EX_UART_AS_DATA
BUFFER_DEFINITION(ex_uart_rx, EX_UART_BUF_SIZE);
#endif

uint8_t flag_ex_uart_ringbuf_full;

void initExUart(uint32_t baud)
{
    IRQn_Type ExUartIRQ;
    S_UART_Init(baud);

#ifdef USE_EX_UART_AS_DATA
    ExUartIRQ = UART2_IRQn;

    S_UART_ITConfig(S_UART_CTRL_RXI, ENABLE);

    NVIC_ClearPendingIRQ(ExUartIRQ);
    NVIC_SetPriority(ExUartIRQ, 1);
    NVIC_EnableIRQ(ExUartIRQ);
#endif
}

int32_t writeExUartData(uint8_t *send_buf, uint16_t length)
{
    uint16_t total_length = 0;

    if (send_buf == NULL) return ERR_PARAM;

    while (*send_buf != '\0' && total_length < length) {
        S_UartPutc(*send_buf++);
        total_length++;
    }
    return total_length;
}

int32_t getExUartReceivedDataSize()
{
    int32_t recv_size = 0;
#ifdef USE_EX_UART_AS_DATA
    recv_size = BUFFER_USED_SIZE(ex_uart_rx);
#endif
    return recv_size;
}

int32_t readExUartData(uint8_t *recv_buf, uint16_t length)
{
    uint16_t total_length = 0, first_length = 0;

    if (recv_buf == NULL) return ERR_PARAM;
    if (length == 0) return 0;

#ifdef USE_EX_UART_AS_DATA
    total_length = length = MIN(BUFFER_USED_SIZE(ex_uart_rx), length);
    if (IS_BUFFER_OUT_SEPARATED(ex_uart_rx) && (first_length =
            BUFFER_OUT_1ST_SIZE(ex_uart_rx)) < length) {
        memcpy(recv_buf, &BUFFER_OUT(ex_uart_rx), first_length);
        BUFFER_OUT_MOVE(ex_uart_rx, first_length);
        length -= first_length;
    }
    memcpy(recv_buf + first_length, &BUFFER_OUT(ex_uart_rx), length);
    BUFFER_OUT_MOVE(ex_uart_rx, length);
#endif

    return total_length;
}

void handleExUartIRQ()
{
#ifdef USE_EX_UART_AS_DATA
    if (S_UART_GetITStatus(S_UART_INTSTATUS_RXI)) {
        if (IS_BUFFER_FULL(ex_uart_rx)) {
            S_UART_ReceiveData();
            flag_ex_uart_ringbuf_full = 1;
        }
        else {
            BUFFER_IN(ex_uart_rx) = S_UART_ReceiveData();
            BUFFER_IN_MOVE(ex_uart_rx, 1);
        }

        S_UART_ClearITPendingBit(S_UART_INTSTATUS_RXI);
    }
#endif
}
