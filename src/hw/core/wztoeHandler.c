/*
 * wztoeHandler.c
 *
 *  Created on: Aug 4, 2017
 *      Author: Kei
 */

#include "common.h"
#include "hw.h"
#include "wizchip_conf.h"
#include "system_W7500x.h"
#include "W7500x_wztoe.h"

/* Private functions */
static SockDestinationNetInfo* getSocketDestinationNetInfoPointer (uint8_t sock_num);

/* Private Structures */
wiz_NetInfo LocalNetInfo;
SockDestinationNetInfo SockDestNetInfo[_WIZCHIP_SOCK_NUM_];

static SockDestinationNetInfo* getSocketDestinationNetInfoPointer (uint8_t sock_num){
    if (sock_num >= _WIZCHIP_SOCK_NUM_) return (SockDestinationNetInfo*)NULL;
    return &SockDestNetInfo[sock_num];
}

wiz_NetInfo* getLocalNetInfoPointer (){
    return &LocalNetInfo;
}

SockDestinationNetInfo* getSocketDestinationNetInfo(uint8_t sock_num)
{
    SockDestinationNetInfo* p_SockDestNetInfo = getSocketDestinationNetInfoPointer(sock_num);

    if(p_SockDestNetInfo == NULL) return (SockDestinationNetInfo*)NULL;

    getSn_DHAR(sock_num, p_SockDestNetInfo->mac);
    getSn_DIPR(sock_num, p_SockDestNetInfo->ip);
    p_SockDestNetInfo->port = getSn_DPORT(sock_num);

    return p_SockDestNetInfo;
}

void setTOETimerTickTo100US(){
    setTIC100US(GetSystemClock() / 10000);
}

int32_t setSocketRetryTimeMsAndCount(uint8_t sock_num, uint32_t millisecond, uint8_t cnt)
{
    uint32_t retry_time_100us = millisecond * 10; //unit : 100us
    if ((sock_num >= _WIZCHIP_SOCK_NUM_) || (retry_time_100us > 0xFFFFFFFF)) return ERR_PARAM;
    setSn_RTR(sock_num, retry_time_100us);
    setSn_RCR(sock_num, cnt);
    return RET_OK;
}

int32_t setSocketTCPKeepAliveTime(uint8_t sock_num, uint16_t keep_alive_time)
{
    if (sock_num >= _WIZCHIP_SOCK_NUM_) return ERR_PARAM;
    if (getSn_MR(sock_num) != Sn_MR_TCP) return ERR_PARAM;

    setSn_KPALVTR(sock_num, keep_alive_time); //5*value (sec)
    return RET_OK;
}

int32_t getSocketStatus(uint8_t sock_num)
{
    if (sock_num >= _WIZCHIP_SOCK_NUM_) return ERR_PARAM;

    switch (getSn_SR(sock_num))
    {
        case SOCK_CLOSED:
            return SOCK_STATUS_CLOSED;
        case SOCK_INIT:
            return SOCK_STATUS_INIT;
        case SOCK_LISTEN:
            return SOCK_STATUS_LISTEN;
        case SOCK_SYNSENT:
            return SOCK_STATUS_SYNSENT;
        case SOCK_SYNRECV:
            return SOCK_STATUS_SYNRECV;
        case SOCK_ESTABLISHED:
            return SOCK_STATUS_ESTABLISHED;
        case SOCK_FIN_WAIT:
            return SOCK_STATUS_FIN_WAIT;
        case SOCK_CLOSING:
            return SOCK_STATUS_CLOSING;
        case SOCK_TIME_WAIT:
            return SOCK_STATUS_TIME_WAIT;
        case SOCK_CLOSE_WAIT:
            return SOCK_STATUS_CLOSE_WAIT;
        case SOCK_LAST_ACK:
            return SOCK_STATUS_LAST_ACK;
        case SOCK_UDP:
            return SOCK_STATUS_UDP;
        case SOCK_IPRAW:
            return SOCK_STATUS_IPRAW;
        case SOCK_MACRAW:
            return SOCK_STATUS_MACRAW;
        case SOCK_PPPOE:
            return SOCK_STATUS_PPPOE;
				default : break;
    }
    return RET_NOK;
}

