/*
 * crgHandler.h
 *
 *  Created on: Aug 4, 2017
 *      Author: Kei
 */

#ifndef SRC_HW_CORE_CRGHANDLER_H_
#define SRC_HW_CORE_CRGHANDLER_H_

#include "common.h"

typedef enum{
    INTERNAL_CLOCK = 0,
    EXTERNAL_CLOCK = 1
}SourceClockMode;

typedef enum{
    PLL_8MHz = 0,
    PLL_12MHz = 1,
    PLL_24MHz = 2,
}PllSourceClock;

typedef enum{
    SYSTEM_8MHz = 0,
    SYSTEM_12MHz = 1,
    SYSTEM_16MHz = 2,
    SYSTEM_24MHz = 3,
    SYSTEM_32MHz = 4,
    SYSTEM_36MHz = 5,
    SYSTEM_48MHz = 6,
}SystemClockFreq;

void initSystemClock(SourceClockMode src_clock_mode, PllSourceClock pll_src_clock, SystemClockFreq system_clock_freq);
void initSysTickTimerMs(uint32_t millisecond);

#endif /* SRC_HW_CORE_CRGHANDLER_H_ */
