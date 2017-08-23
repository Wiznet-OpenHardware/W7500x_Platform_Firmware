/*
 * ecoEEPROM.h
 *
 *  Created on: Aug 22, 2017
 *      Author: Kei
 */

#ifndef SRC_TESTSUITE_SOFTI2C_EEPROMEE24AAXX_H_
#define SRC_TESTSUITE_SOFTI2C_EEPROMEE24AAXX_H_

#include "common.h"

#define EE24AA01  128
#define EE24AA02  256
#define EE24AA04  512
#define EE24AA08  1024
#define EE24AA16  2048
#define EE24AA32  4096
#define EE24AA64  8192
#define EE24AA128 16384
#define EE24AA256 32768

#define EE_TYPE EE24AA04

#define EE24AAXX_BLOCK(num) EEPROM_BLOCK_SIZE*(num)

#if (EE_TYPE > EE24AA16)
#define EEPROM_BLOCK_SIZE       256
#define EEPROM_PAGE_SIZE        32
#else
#define EEPROM_BLOCK_SIZE       256
#define EEPROM_PAGE_SIZE        16
#define EEPROM_BLOCK_COUNT      (EE_TYPE / EEPROM_BLOCK_SIZE)
#endif

uint16_t writeEE24AAXX(uint32_t addr, uint8_t *buf, uint16_t len);
uint16_t readEE24AAXX(uint32_t addr, uint8_t *buf, uint16_t len);
void eraseEE24AAXXBlock(uint32_t addr);

#endif /* SRC_TESTSUITE_SOFTI2C_EEPROMEE24AAXX_H_ */
