/*
 * ethernetWrapper.h
 *
 *  Created on: Aug 8, 2017
 *      Author: Kei
 */

#ifndef SRC_APP_ETHERNETWRAPPER_H_
#define SRC_APP_ETHERNETWRAPPER_H_

#include <stdint.h>

#ifndef SOCK_DHCP
#define SOCK_DHCP 6
#endif

#ifndef SOCK_DNS
#define SOCK_DNS 7
#endif

int32_t initEthernetStatic(uint8_t* mac_addr, uint8_t* ip_addr, uint8_t* subnet, uint8_t* gateway, uint8_t* dns_server);
int32_t initEthernetDHCP(uint8_t* mac_addr);

void maintainDHCP(void);

int32_t openSocketAsClient(uint8_t sock_num);
int32_t openSocketAsServer(uint8_t sock_num, uint16_t port_num);

int32_t connectToServerDomain(uint8_t sock_num, uint8_t* domain_name, uint16_t dest_port);
int32_t connectToServerIP(uint8_t sock_num, uint8_t* dest_ip_addr, uint16_t dest_port);
int32_t disconnectTCPConnection(uint8_t sock_num);
int32_t isTCPSocketConnected(uint8_t sock_num);

int32_t sendDataTCP(uint8_t sock_num, uint8_t * send_buf, uint16_t send_len);
int32_t sendDataUDP(uint8_t sock_num, uint8_t * send_buf, uint16_t send_len, uint8_t * peer_addr, uint16_t peer_port);
int32_t receiveDataTCP(uint8_t sock_num, uint8_t * recv_buf, uint16_t read_len);
int32_t receiveDataUDP(uint8_t sock_num, uint8_t * recv_buf, uint16_t read_len, uint8_t * peer_addr, uint16_t peer_port);
int32_t getSocketReceivedDataSize(uint8_t sock_num);

int8_t openSocketDHCPAndGetIpAddress(uint8_t sock_num);
int8_t openSocketDNSAndGetIpAddress(uint8_t sock_num, uint8_t* dns_server_ip, uint8_t* dns_domain_name, uint8_t* ip_addr_receive_buf);

#endif /* SRC_APP_ETHERNETWRAPPER_H_ */
