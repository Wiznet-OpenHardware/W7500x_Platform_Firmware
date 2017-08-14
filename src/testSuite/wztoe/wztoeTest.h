/*
 * ethLoopback.h
 *
 *  Created on: Aug 9, 2017
 *      Author: Kei
 */

#ifndef SRC_TESTSUITE_WZTOE_WZTOETEST_H_
#define SRC_TESTSUITE_WZTOE_WZTOETEST_H_

#include "stdint.h"

typedef enum
{
    USE_DHCP_ETH = 0, USE_STATIC_ETH = 1
} DHCP_STATIC;

/* DHCP requires a Timer for the dhcp tick */
void initWZTOETestSuite(uint8_t enable_dhcp);
void doTCPServerLoopback(uint8_t sock_num, uint16_t port_num, uint8_t* share_buf);
void doTCPClientLoopback(uint8_t sock_num, uint8_t* dest_ip_addr, uint16_t dest_port_num, uint8_t* share_buf);

#endif /* SRC_TESTSUITE_WZTOE_WZTOETEST_H_ */
