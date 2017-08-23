/*
 * eepromEE24AAXX.c
 *
 *  Created on: Aug 22, 2017
 *      Author: Kei
 */

#include "hw.h"
#include "eepromEE24AAXX.h"

extern void delayUsForSoftI2C(uint16_t microsecond);

static uint8_t writePageEE24AAXX(uint32_t addr, uint8_t *buf, uint8_t len);

uint16_t readEE24AAXX(uint32_t addr, uint8_t *buf, uint16_t len)
{
    uint8_t bsb;
    uint8_t block;
    uint16_t i;
    uint16_t ret_len = 0;

    block = addr / EEPROM_BLOCK_SIZE;
    if (block >= EEPROM_BLOCK_COUNT) return 0; // failed

    bsb = (addr / EEPROM_BLOCK_SIZE) << 1;

    __disable_irq();

    startSoftI2C();

    if (EE_TYPE > EE24AA16) {
        sendSoftI2CByte(0xA0);
        waitSoftI2CAck();
        sendSoftI2CByte((uint8_t) ((addr & 0xFF00) >> 8));
        waitSoftI2CAck();
        sendSoftI2CByte((uint8_t) (addr & 0x00FF));
        waitSoftI2CAck();
    }
    else {
        sendSoftI2CByte((uint8_t) (0xA0 + bsb));
        waitSoftI2CAck();
        sendSoftI2CByte((uint8_t) (addr % EEPROM_BLOCK_SIZE));
        waitSoftI2CAck();
    }

    startSoftI2C();

    if (EE_TYPE > EE24AA16) {
        sendSoftI2CByte(0xA1);
    }
    else {
        sendSoftI2CByte((uint8_t) (0xA1 + bsb));
    }
    waitSoftI2CAck();

    for (i = 0; i < len; i++) {
        ret_len++;
        if (len == ret_len) buf[i] = readSoftI2CByte(0); // I2C NACK
        else buf[i] = readSoftI2CByte(1); // I2C ACK

    }

    stopSoftI2C();

    __enable_irq();

    delayUsForSoftI2C(10000);

    return ret_len;
}

uint16_t writeEE24AAXX(uint32_t addr, uint8_t *buf, uint16_t len)
{
    uint8_t page, remainder;
    uint8_t block;
    uint16_t write_ptr;
    uint16_t i;
    uint16_t ret_len = 0;

    block = addr / EEPROM_BLOCK_SIZE;
    if (block >= EEPROM_BLOCK_COUNT) return 0;

    page = len / EEPROM_PAGE_SIZE;
    remainder = len - (page * EEPROM_PAGE_SIZE);

    if (len < EEPROM_PAGE_SIZE) {
        ret_len += writePageEE24AAXX(addr, buf, len);
    }
    else {
        for (i = 0; i < page; i++) {
            write_ptr = i * EEPROM_PAGE_SIZE;
            ret_len += writePageEE24AAXX(addr + write_ptr, buf + write_ptr, EEPROM_PAGE_SIZE);
        }

        if (remainder > 0) {
            write_ptr = page * EEPROM_PAGE_SIZE;
            ret_len += writePageEE24AAXX(addr + write_ptr, buf + write_ptr, remainder);
        }
    }

    return ret_len;
}

void eraseEE24AAXXBlock(uint32_t addr)
{
    uint8_t block, page;
    uint16_t i;
    uint32_t start_addr;
    uint8_t buf[EEPROM_PAGE_SIZE];

    block = addr / EEPROM_BLOCK_SIZE;
    if (block >= EEPROM_BLOCK_COUNT) return;

    memset(buf, 0xff, EEPROM_PAGE_SIZE);
    page = EEPROM_BLOCK_SIZE / EEPROM_PAGE_SIZE;

    block = addr / EEPROM_BLOCK_SIZE;
    start_addr = block * EEPROM_BLOCK_SIZE;

    for (i = 0; i < page; i++) {
        writePageEE24AAXX(start_addr + (i * EEPROM_PAGE_SIZE), buf, EEPROM_PAGE_SIZE);
    }
}

static uint8_t writePageEE24AAXX(uint32_t addr, uint8_t *buf, uint8_t len)
{
    uint8_t bsb;
    uint8_t block;
    uint8_t i;
    uint8_t ret_len = 0;

    block = addr / EEPROM_BLOCK_SIZE;
    if (block >= EEPROM_BLOCK_COUNT) return 0;

    bsb = (addr / EEPROM_BLOCK_SIZE) << 1;

    if (len > EEPROM_PAGE_SIZE) len = EEPROM_PAGE_SIZE;

    __disable_irq();

    startSoftI2C();

    if (EE_TYPE > EE24AA16) {
        sendSoftI2CByte(0xA0);
        waitSoftI2CAck();
        sendSoftI2CByte((uint8_t) ((addr & 0xFF00) >> 8));
        waitSoftI2CAck();
        sendSoftI2CByte((uint8_t) (addr & 0x00FF));
        waitSoftI2CAck();
    }
    else {
        sendSoftI2CByte((uint8_t) (0xA0 + bsb));
        waitSoftI2CAck();
        sendSoftI2CByte((uint8_t) (addr % EEPROM_BLOCK_SIZE));
        waitSoftI2CAck();
    }

    for (i = 0; i < len; i++) {
        sendSoftI2CByte(buf[i]);
        waitSoftI2CAck();
        ret_len++;
    }

    stopSoftI2C();

    __enable_irq();

    delayUsForSoftI2C(10000);

    return ret_len;
}
