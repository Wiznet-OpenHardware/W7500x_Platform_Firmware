/*
 * wztoeTest.c
 *
 *  Created on: Aug 9, 2017
 *      Author: Kei
 */
#include "common.h"
#include "hw.h"
#include "wizchip_conf.h"

#include "ethernetWrapper.h"
#include "wztoeTest.h"

#define TEST_BUF_SIZE 256

void initWZTOETestSuite(uint8_t enable_dhcp)
{
    uint8_t mac_addr[6] = { 0x00, 0x08, 0xDC, 0x50, 0x4F, 0x5F };
    uint8_t ip_addr[4] = { 192, 168, 11, 100 };
    uint8_t subnet[4] = { 255, 255, 255, 0 };
    uint8_t gateway[4] = { 192, 168, 11, 1 };
    uint8_t dns_server[4] = { 8, 8, 8, 8 };

    if (enable_dhcp == USE_DHCP_ETH) {
        if (initEthernetDHCP(mac_addr) != RET_OK) {
            initEthernetStatic(mac_addr, ip_addr, subnet, gateway, dns_server);
        }
    }
    else {
        initEthernetStatic(mac_addr, ip_addr, subnet, gateway, dns_server);
    }
}

void doTCPServerLoopback(uint8_t sock_num, uint16_t port_num)
{
    uint16_t len;
    uint8_t share_buf[TEST_BUF_SIZE];

    if (isTCPSocketConnected(sock_num)) {
        len = getSocketReceivedDataSize(sock_num);
        if (len) {
            len = receiveDataTCP(sock_num, share_buf, len);
            sendDataTCP(sock_num, share_buf, len);
        }
    }
    else if (getSocketStatus(sock_num) == SOCK_STATUS_CLOSED) {
        openSocketAsServer(sock_num, port_num);
    }
}

void doTCPClientLoopback(uint8_t sock_num, uint8_t* dest_ip_addr, uint16_t dest_port_num)
{
    uint16_t len;
    uint8_t share_buf[TEST_BUF_SIZE];

    if (isTCPSocketConnected(sock_num)) {
        len = getSocketReceivedDataSize(sock_num);
        if (len) {
            len = receiveDataTCP(sock_num, share_buf, len);
            sendDataTCP(sock_num, share_buf, len);
        }
    }
    else if (getSocketStatus(sock_num) == SOCK_STATUS_INIT) {
        connectToServerIP(sock_num, dest_ip_addr, dest_port_num);
    }
    else if (getSocketStatus(sock_num) == SOCK_STATUS_CLOSED) {
        openSocketAsClient(sock_num);
    }
}

void doUDPLoopback(uint8_t sock_num, uint16_t port_num)
{
    uint16_t len;
    uint8_t peer_ip_addr[4];
    uint16_t peer_port_num;
    uint8_t share_buf[TEST_BUF_SIZE];

    if (getSocketStatus(sock_num) == SOCK_STATUS_UDP) {
        len = getSocketReceivedDataSize(sock_num);
        if (len) {
            len = receiveDataUDP(sock_num, share_buf, len, peer_ip_addr, &peer_port_num);
            sendDataUDP(sock_num, share_buf, len, peer_ip_addr, peer_port_num);
        }
    }
    else if (getSocketStatus(sock_num) == SOCK_STATUS_CLOSED) {
        openSocketAsUDPPeer(sock_num, port_num);
    }
}
