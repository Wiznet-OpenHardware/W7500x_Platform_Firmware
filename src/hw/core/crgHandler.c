/*
 * crgHandler.c
 *
 *  Created on: Aug 4, 2017
 *      Author: Kei
 */

#include "hw.h"
#include "system_W7500x.h"

void initSystemClock(SourceClockMode src_clock_mode, PllSourceClock pll_src_clock, SystemClockFreq system_clock_freq)
{
    uint8_t src_clk_mode = INTERN_XTAL;
    uint32_t pll_src_clk = PLL_SOURCE_8MHz;
    uint32_t sys_clk_freq = SYSTEM_CLOCK_8MHz;

    switch(src_clock_mode){
        case INTERNAL_CLOCK :
            src_clk_mode = INTERN_XTAL;
            break;
        case EXTERNAL_CLOCK :
            src_clk_mode = EXTERN_XTAL;
            break;
    }

    switch(pll_src_clock){
        case PLL_8MHz :
            pll_src_clk = PLL_SOURCE_8MHz;
            break;
        case PLL_12MHz :
            pll_src_clk = PLL_SOURCE_12MHz;
            break;
        case PLL_24MHz :
            pll_src_clk = PLL_SOURCE_24MHz;
            break;
    }

    switch(system_clock_freq){
        case SYSTEM_8MHz :
            sys_clk_freq = SYSTEM_CLOCK_8MHz;
            break;
        case SYSTEM_12MHz :
            sys_clk_freq = SYSTEM_CLOCK_12MHz;
            break;
        case SYSTEM_16MHz :
            sys_clk_freq = SYSTEM_CLOCK_16MHz;
            break;
        case SYSTEM_24MHz :
            sys_clk_freq = SYSTEM_CLOCK_24MHz;
            break;
        case SYSTEM_32MHz :
            sys_clk_freq = SYSTEM_CLOCK_32MHz;
            break;
        case SYSTEM_36MHz :
            sys_clk_freq = SYSTEM_CLOCK_36MHz;
            break;
        case SYSTEM_48MHz :
            sys_clk_freq = SYSTEM_CLOCK_48MHz;
            break;
    }

    SystemInit_User(src_clk_mode, pll_src_clk, sys_clk_freq);
}

void initSysTickTimerMs(uint32_t millisecond)
{
    SysTick_Config((GetSystemClock() / 1000 * millisecond));
}
