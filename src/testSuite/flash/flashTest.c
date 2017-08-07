/*
 * FlashTest.c
 *
 *  Created on: Aug 2, 2017
 *      Author: Kei
 */

#include "flashTest.h"

#include <stdio.h>
#include "common.h"
#include "hw.h"

void initUartForFlashTest(uint8_t uart_ch);
void initExUartForFlashTest(void);

typedef struct __TestData
{
    uint8_t something1[20];
    unsigned int something2;
} TestData;

void doFlashWriteEraseTest()
{
    TestData FlashTestData;

    uint8_t save_buff[SECT_SIZE];
    unsigned int dummy_hex_data = 0x123456;
    unsigned int real_hex_data = 0x0008dc;

    TestData *p_testdata = (TestData*) save_buff;

    /* Init UART for Debug  */
//    initUartForFlashTest(UART_CH1);
    initExUartForFlashTest();

    /* Set dummy data to buffer */
    memcpy(FlashTestData.something1, "I'm dummy data!", sizeof("I'm dummy data!"));
    FlashTestData.something2 = dummy_hex_data;
    memcpy(save_buff, (char*) &FlashTestData, sizeof(TestData));

    /* Read stored data from flash */
    readDataFromFlash(DAT0_START_ADDR, save_buff, sizeof(TestData));
    printf("Something1: %s, Something2: 0x%08X \r\n", (const char*)p_testdata->something1,
            p_testdata->something2);

    /* Erase Sector */
    eraseFlashSector(DAT0_START_ADDR);

    /* Read erased flash memory */
    readDataFromFlash(DAT0_START_ADDR, save_buff, sizeof(TestData));
    printf("Something1: %s, Something2: 0x%08X \r\n", (const char*)p_testdata->something1,
            p_testdata->something2);

    /* Set real data to structure */
    memcpy(FlashTestData.something1, "Hello, WIZnet!", sizeof("Hello, WIZnet!"));
    FlashTestData.something2 = real_hex_data;
    memcpy(save_buff, (char*) &FlashTestData, sizeof(TestData));

    /* Store real data to flash*/
    writeDataToFlashDataSector(DAT0_START_ADDR, save_buff, SECT_SIZE);
}

void initUartForFlashTest(uint8_t uart_ch)
{
    initUart(uart_ch, 115200, WORD_LEN8, PARITY_NONE, STOP_BIT1, FLOW_NONE);

    writeUartData(uart_ch, (uint8_t*)"\r\nHello, WIZnet!\r\n",
            sizeof("Hello, WIZnet!\r\n"));
}

void initExUartForFlashTest()
{
    initExUart(115200);

    writeExUartData((uint8_t*)"\r\nHello, WIZnet!\r\n", sizeof("Hello, WIZnet!\r\n"));
}
