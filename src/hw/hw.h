/*
 * hw.h
 *
 *  Created on: Aug 3, 2017
 *      Author: Kei
 */

#ifndef SRC_HW_HW_H_
#define SRC_HW_HW_H_


#include "core/adcHandler.h"
#include "core/crgHandler.h"
#include "core/dmaHandler.h"
#include "core/ex_uartHandler.h"
#include "core/extiHandler.h"
#include "core/flashHandler.h"
#include "core/gpioHandler.h"
#include "core/pwmHandler.h"
#include "core/rngHandler.h"
#include "core/softi2cHandler.h"
#include "core/sspHandler.h"
#include "core/timerHandler.h"
#include "core/uartHandler.h"
#include "core/wdtHandler.h"
#include "core/wztoeHandler.h"

#include "hw_def.h"
#include "board/board.h"


void initHW(void);



#endif /* SRC_HW_HW_H_ */
