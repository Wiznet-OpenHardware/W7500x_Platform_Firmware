#include <string.h>

#include "W7500x.h"
#include "common.h"
#include "hw.h"

void eraseFlashSector(uint32_t sector_addr)
{
    uint16_t erase_id = 0;
    uint32_t addr = 0;

    if (sector_addr == (sector_addr & FLASH_END_ADDR)) {
        erase_id = IAP_ERAS_SECT;
        addr = sector_addr;
    }
    else if ((sector_addr >= DAT0_START_ADDR) && (sector_addr == (sector_addr & DAT0_END_ADDR))) {
        erase_id = IAP_ERAS_DAT0;
        addr = 0;
    }
    else if ((sector_addr >= DAT1_START_ADDR) && (sector_addr == (sector_addr & DAT1_END_ADDR))) {
        erase_id = IAP_ERAS_DAT1;
        addr = 0;
    }
    else {
        WIZ_PRINT(" > FLASH:SECTOR_ERASE_FAILED: [0x%.8x]\r\n", (unsigned int) sector_addr);
        return;
    }

    __disable_irq();

    DO_IAP(erase_id, addr, 0, 0);

    __enable_irq();

}

void eraseFlashBlock(uint32_t block_addr)
{
    if (block_addr != (block_addr & FLASH_END_ADDR)) {
        WIZ_PRINT(" > FLASH:BLOCK_ERASE_FAILED: [0x%.8x]\r\n", (unsigned int) block_addr);
        return;
    }
    __disable_irq();

    DO_IAP(IAP_ERAS_BLCK, block_addr, 0, 0);

    __enable_irq();

}

uint32_t writeDataToFlashDataSector(uint32_t addr, uint8_t * data, uint32_t data_len)
{
    // Invalid memory address range: Data blocks
    if ((addr >= DAT0_START_ADDR) && (addr == (addr & DAT1_END_ADDR))) {
        if ((data_len > SECT_SIZE) || (DAT0_START_ADDR + data_len > DAT1_END_ADDR)) return 0;
    }

    // Invalid data_len
    if ((data_len == 0) && (addr + data_len > DAT1_END_ADDR)) return 0; // (Max ~ 0x0003FFFF)

    // Invalid memory address range: Information block, Do not access
    if ((addr > FLASH_END_ADDR) && (addr < DAT0_START_ADDR)) return 0;

    __disable_irq();

    DO_IAP(IAP_PROG, addr, data, data_len);

    __enable_irq();

    return data_len;
}

uint32_t readDataFromFlash(uint32_t addr, uint8_t *data, uint32_t data_len)
{
    int32_t i;

    for (i = 0; i < data_len; i++) {
        data[i] = *(uint8_t *) (addr + i);
    }

    return i;
}

/**
 * @brief  DO IAP Function
 */
void DO_IAP(uint32_t id, uint32_t dst_addr, uint8_t* src_addr, uint32_t size)
{
    uint32_t temp_interrupt;

    // Backup Interrupt Set Pending Register
    temp_interrupt = (NVIC->ISPR[0]);
    (NVIC->ISPR[0]) = (uint32_t) 0xFFFFFFFF;

    // Call IAP Function
    ((void (*)(uint32_t, uint32_t, uint8_t*, uint32_t)) IAP_ENTRY)(id, dst_addr, src_addr, size);

    // Restore Interrupt Set Pending Register
    (NVIC->ISPR[0]) = temp_interrupt;
}

