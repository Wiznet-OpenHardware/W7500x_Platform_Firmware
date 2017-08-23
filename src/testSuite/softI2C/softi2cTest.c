/*
 * softi2cTest.c
 *
 *  Created on: Jul 27, 2017
 *      Author: Kei
 */

#include "hw.h"
#include "eepromEE24AAXX.h"
#include "softi2cTest.h"

#define TEST_EE24AXX_BLOCK EE24AAXX_BLOCK(1)

typedef struct __TestData
{
    uint8_t something1[20];
    unsigned int something2;
} TestData;

void initSoftI2cTestSuite()
{
    initSoftI2C();
    initExUart(115200);
}

void doEE24AXXWriteEraseTest()
{
    TestData EE24AAXXTestData;

    uint8_t save_buff[SECT_SIZE];
    unsigned int dummy_hex_data = 0x123456;
    unsigned int real_hex_data = 0x0008dc;

    TestData *p_testdata = (TestData*) save_buff;

    /* Set dummy data to buffer */
    memcpy(EE24AAXXTestData.something1, "I'm dummy data!", sizeof("I'm dummy data!"));
    EE24AAXXTestData.something2 = dummy_hex_data;
    memcpy(save_buff, (char*) &EE24AAXXTestData, sizeof(TestData));

    /* Read stored data from EE24AAXX */
    readEE24AAXX(TEST_EE24AXX_BLOCK, save_buff, sizeof(TestData));
    WIZ_PRINT("Something1: %s, Something2: 0x%08X \r\n", (const char* ) p_testdata->something1, p_testdata->something2);

    /* Erase Sector */
    eraseEE24AAXXBlock(TEST_EE24AXX_BLOCK);

    /* Read erased EE24AAXX memory */
    readEE24AAXX(TEST_EE24AXX_BLOCK, save_buff, sizeof(TestData));
    WIZ_PRINT("Something1: %s, Something2: 0x%08X \r\n", (const char* ) p_testdata->something1, p_testdata->something2);

    /* Set real data to structure */
    memcpy(EE24AAXXTestData.something1, "Hello, WIZnet!", sizeof("Hello, WIZnet!"));
    EE24AAXXTestData.something2 = real_hex_data;
    memcpy(save_buff, (char*) &EE24AAXXTestData, sizeof(TestData));

    /* Store real data to EE24AAXX */
    writeEE24AAXX(TEST_EE24AXX_BLOCK, save_buff, SECT_SIZE);
}
