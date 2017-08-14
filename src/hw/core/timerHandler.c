#include "W7500x_dualtimer.h"

#include "common.h"

#include "hw.h"

/* extern variables */
extern volatile uint16_t uart_timer_ms;
extern volatile uint32_t dhcp_tick_1s;
extern volatile uint32_t dns_1s_tick;

/* private variables */
static volatile uint16_t msec_cnt = 0;
static volatile uint8_t sec_cnt = 0;
static volatile uint8_t min_cnt = 0;
static volatile uint32_t hour_cnt = 0;

/* private structure */
typedef struct
{
    DUALTIMER_TypeDef* Register;
    DUALTIMER_InitTypDef Definition;
    IRQn_Type IRQNum;
} HW_TimerStructure;

HW_TimerStructure TimerStructure[TIMER_CH_MAX];

int32_t initTimer(uint8_t timer_ch)
{
    DUALTIMER_TypeDef * TimerRegister;
    DUALTIMER_InitTypDef * TimerInitStruct;
    IRQn_Type TimerIRQ;

    if (timer_ch > TIMER_CH_MAX) return ERR_PARAM;

    switch (timer_ch)
    {
        case TIMER_CH0_0:
            TimerStructure[timer_ch].Register = DUALTIMER0_0;
            TimerStructure[timer_ch].IRQNum = DUALTIMER0_IRQn;
            TimerStructure[timer_ch].Definition.TimerControl_Size = DUALTIMER_TimerControl_Size_32;
            break;
        case TIMER_CH0_1:
            TimerStructure[timer_ch].Register = DUALTIMER0_1;
            TimerStructure[timer_ch].IRQNum = DUALTIMER0_IRQn;
            TimerStructure[timer_ch].Definition.TimerControl_Size = DUALTIMER_TimerControl_Size_16;
            break;
        case TIMER_CH1_0:
            TimerStructure[timer_ch].Register = DUALTIMER1_0;
            TimerStructure[timer_ch].IRQNum = DUALTIMER1_IRQn;
            TimerStructure[timer_ch].Definition.TimerControl_Size = DUALTIMER_TimerControl_Size_32;
            break;
        case TIMER_CH1_1:
            TimerStructure[timer_ch].Register = DUALTIMER1_1;
            TimerStructure[timer_ch].IRQNum = DUALTIMER1_IRQn;
            TimerStructure[timer_ch].Definition.TimerControl_Size = DUALTIMER_TimerControl_Size_16;
            break;
    }

    TimerRegister = TimerStructure[timer_ch].Register;
    TimerInitStruct = &TimerStructure[timer_ch].Definition;
    TimerIRQ = TimerStructure[timer_ch].IRQNum;

    NVIC_EnableIRQ(TimerIRQ);

    DUALTIMER_ClockEnable(TimerRegister);

    TimerInitStruct->TimerLoad = GetSystemClock() / 1000;
    TimerInitStruct->TimerControl_Mode = DUALTIMER_TimerControl_Periodic;
    TimerInitStruct->TimerControl_OneShot = DUALTIMER_TimerControl_Wrapping;
    TimerInitStruct->TimerControl_Pre = DUALTIMER_TimerControl_Pre_1;

    DUALTIMER_Init(TimerRegister, TimerInitStruct);

    DUALTIMER_IntConfig(TimerRegister, ENABLE);

    DUALTIMER_Start(TimerRegister);

    return RET_OK;
}

void handleTimerZeroIRQ(void)
{
    if (DUALTIMER_GetIntStatus(DUALTIMER0_0)) {
        DUALTIMER_IntClear(DUALTIMER0_0);

        msec_cnt++;
        uart_timer_ms++;

        /* Second Process */
        if (msec_cnt >= 1000 - 1) {
            msec_cnt = 0;
            sec_cnt++;
            dhcp_tick_1s++;
            dns_1s_tick++;
        }

        /* Minute Process */
        if (sec_cnt >= 60) {
            sec_cnt = 0;
            min_cnt++;
        }

        /* Hour Process */
        if (min_cnt >= 60) {
            min_cnt = 0;
            hour_cnt++;
        }
    }

    if (DUALTIMER_GetIntStatus(DUALTIMER0_1)) {
        DUALTIMER_IntClear(DUALTIMER0_1);
        //TODO
    }
}

uint32_t getDeviceUptimeHour(void)
{
    return hour_cnt;
}

uint8_t getDeviceUptimeMin(void)
{
    return min_cnt;
}

uint8_t getDeviceUptimeSec(void)
{
    return sec_cnt;
}

uint16_t getDeviceUptimeMsec(void)
{
    return msec_cnt;
}

