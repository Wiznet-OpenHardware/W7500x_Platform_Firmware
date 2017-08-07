/*
 * UartLoopback.c
 *
 *  Created on: Jul 27, 2017
 *      Author: Kei
 */



#include <stdio.h>
#include "common.h"
#include "hw.h"

#include "uartTest.h"

void initUartTestSuite(uint8_t uart_ch)
{
    initUart(uart_ch, 115200, WORD_LEN8, PARITY_NONE, STOP_BIT1, FLOW_NONE);
    writeUartData(uart_ch, (uint8_t*)"Hello, WIZnet!\r\n", sizeof("Hello, WIZnet!\r\n"));
}

void initExUartTestSuite()
{
    initExUart(115200);
    writeExUartData((uint8_t*)"Hello, WIZnet!\r\n", sizeof("Hello, WIZnet!\r\n"));
}

void doUartLoopback(uint8_t uart_ch)
{
    int32_t ret_len;
    const uint8_t test_buf_size = 255;
    uint8_t test_buf[test_buf_size];

    if ((ret_len = getUartReceivedDataSize(uart_ch)) > 0) {
        if(ret_len > test_buf_size) ret_len = test_buf_size;
        ret_len = readUartData(uart_ch, test_buf, ret_len);
        if (ret_len > 0) {
            writeUartData(uart_ch, test_buf, ret_len);
        }
    }


}

void doExUartLoopback()
{
    int32_t ret_len;
    const uint8_t test_buf_size = 255;
    uint8_t test_buf[test_buf_size];

    if ((ret_len = getExUartReceivedDataSize()) > 0) {
        if(ret_len > test_buf_size) ret_len = test_buf_size;
        ret_len = readExUartData(test_buf, ret_len);
        if (ret_len > 0) {
            writeExUartData(test_buf, ret_len);
        }
    }
}
