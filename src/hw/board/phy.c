/*
 * PHY.c
 *
 *  Created on: Aug 4, 2017
 *      Author: Kei
 */


#include <stdio.h>
#include "common.h"
#include "phy.h"
#include "hw.h"
#include "board_def.h"
#include "W7500x_miim.h"
#include "W7500x_gpio.h"

#ifdef __DEF_USED_MDIO__
#ifndef __W7500P__
#define __DEF_USED_IC101AG__ // PHY initialize for WIZwiki-W7500 Board
#define W7500x_MDIO    GPIO_Pin_14
#define W7500x_MDC     GPIO_Pin_15
#else
#define W7500x_MDIO    GPIO_Pin_15
#define W7500x_MDC     GPIO_Pin_14
#endif
#endif

volatile uint16_t phylink_check_time_msec;

void initPHY(void)
{
    /* W7500 + (IC+101AG PHY) */
#ifdef __DEF_USED_IC101AG__
    *(volatile uint32_t *)(0x41003068) = 0x64; //TXD0 - set PAD strengh and pull-up
    *(volatile uint32_t *)(0x4100306C) = 0x64; //TXD1 - set PAD strengh and pull-up
    *(volatile uint32_t *)(0x41003070) = 0x64; //TXD2 - set PAD strengh and pull-up
    *(volatile uint32_t *)(0x41003074) = 0x64; //TXD3 - set PAD strengh and pull-up
    *(volatile uint32_t *)(0x41003050) = 0x64; //TXE  - set PAD strengh and pull-up
#endif

#ifdef __W7500P__
    *(volatile uint32_t *)(0x41003070) = 0x61; // RXDV - set pull down (PB_12)
    *(volatile uint32_t *)(0x41003054) = 0x61; // COL  - set pull down (PB_05)
#endif

#ifdef __DEF_USED_MDIO__
    mdio_init(GPIOB, W7500x_MDC, W7500x_MDIO);

    #ifdef __W7500P__
        set_link(FullDuplex10);
    #endif

    WIZ_PRINT("\r\nPHYADDR = %.3x, PHYREGADDR = %x, VAL = 0x%.4x\r\n", PHY_ADDR, 0, mdio_read(GPIOB, 0)); // [RW] Control, default: 0x3100 / 0011 0001 0000 0000b
    WIZ_PRINT("PHYADDR = %.3x, PHYREGADDR = %x, VAL = 0x%.4x\r\n", PHY_ADDR, 1, mdio_read(GPIOB, 1)); // [RO] Status,  default: 0x786d / 0111 1000 0110 1101b (link up)
    WIZ_PRINT("PHYADDR = %.3x, PHYREGADDR = %x, VAL = 0x%.4x\r\n", PHY_ADDR, 2, mdio_read(GPIOB, 2)); // [RO] OUI,     default: 0x001c
#endif
}

void initPHYLinkInputPin(void)
{
    initGpioPin(PHYLINK_STATE_INPUT_PORT, PHYLINK_STATE_INPUT_PIN, INPUT, PULL_UP);
}

uint8_t getPHYLinkInputState(void)
{
    int32_t pin_state = getGpioPinInputState(PHYLINK_STATE_INPUT_PORT, PHYLINK_STATE_INPUT_PIN);
    if(pin_state == RET_NOK) pin_state = 0;
    return (uint8_t)pin_state;
}
