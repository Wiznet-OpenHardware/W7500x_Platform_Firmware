#ifndef TIMERHANDLER_H_
#define TIMERHANDLER_H_

#include <stdint.h>

#define TIMER_CH_MAX 2

typedef enum{
    TIMER_CH0_0 = 0,
    TIMER_CH0_1 = 1,
    TIMER_CH1_0 = 2,
    TIMER_CH1_1 = 3
}TimerChannel;

int32_t initTimer(uint8_t timer_ch);
void handleTimerZeroIRQ(void);

uint32_t getDeviceUptimeHour(void);
uint8_t  getDeviceUptimeMin(void);
uint8_t  getDeviceUptimeSec(void);
uint16_t getDeviceUptimeMsec(void);

#endif /* TIMERHANDLER_H_ */
