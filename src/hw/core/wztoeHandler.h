/*
 * wztoeHandler.h
 *
 *  Created on: Aug 4, 2017
 *      Author: Kei
 */

#ifndef SRC_HW_CORE_WZTOEHANDLER_H_
#define SRC_HW_CORE_WZTOEHANDLER_H_

#include <stdint.h>
#include "wizchip_conf.h"


typedef enum{
 SOCK_STATUS_CLOSED = 0,
 SOCK_STATUS_INIT = 1,
 SOCK_STATUS_LISTEN = 2,
 SOCK_STATUS_SYNSENT = 3,
 SOCK_STATUS_SYNRECV = 4,
 SOCK_STATUS_ESTABLISHED = 5,
 SOCK_STATUS_FIN_WAIT = 6,
 SOCK_STATUS_CLOSING = 7,
 SOCK_STATUS_TIME_WAIT = 8,
 SOCK_STATUS_CLOSE_WAIT = 9,
 SOCK_STATUS_LAST_ACK = 10,
 SOCK_STATUS_UDP = 11,
 SOCK_STATUS_IPRAW = 12,
 SOCK_STATUS_MACRAW = 13,
 SOCK_STATUS_PPPOE = 14
}SocketStatus;

typedef struct
{
   uint8_t mac[6];
   uint8_t ip[4];
   uint16_t port;
} SockDestinationNetInfo;

void setTOETimerTickTo100US(void);
int32_t getSocketStatus(uint8_t sock_num);
int32_t setSocketRetryTimeMsAndCount(uint8_t sock_num, uint32_t millisecond, uint8_t cnt);
int32_t setSocketTCPKeepAliveTime(uint8_t sock_num, uint16_t keep_alive_time);

wiz_NetInfo* getLocalNetInfoPointer (void);
SockDestinationNetInfo* getSocketDestinationNetInfo(uint8_t sock_num);

#endif /* SRC_HW_CORE_WZTOEHANDLER_H_ */
