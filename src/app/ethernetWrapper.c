/*
 * ethernetWrapper.c
 *
 *  Created on: Aug 8, 2017
 *      Author: Kei
 */

#include "common.h"
#include "socket.h"
#include "hw.h"
#include "wizchip_conf.h"
#include "dhcp.h"
#include "dns.h"

#include "ethernetWrapper.h"

/* Private Functions */
void resetWIZCHIPForConflict(void);
void updateDHCPNetworkInfo(void);
void assignDHCPNetworkInfo(void);

typedef struct __SockBufSize
{
    uint8_t tx[_WIZCHIP_SOCK_NUM_];
    uint8_t rx[_WIZCHIP_SOCK_NUM_];
} SockBufSize;

static uint16_t client_any_port;
static SockBufSize SocketBufferSize = { { 2, 2, 2, 2, 2, 2, 2, 2 }, { 2, 2, 2, 2, 2, 2, 2, 2 } };

int32_t initEthernetStatic(uint8_t* mac_addr, uint8_t* ip_addr, uint8_t* subnet, uint8_t* gateway, uint8_t* dns_server)
{
    wiz_NetInfo* p_LocalNetInfo = getLocalNetInfoPointer();

    if ((mac_addr == NULL) || (ip_addr == NULL) || (subnet == NULL) || (gateway == NULL) || (dns_server == NULL)) return ERR_PARAM;

    initPHY();
    setTOETimerTickTo100US();
    ctlwizchip(CW_INIT_WIZCHIP, (uint8_t*) &SocketBufferSize);

    memcpy(p_LocalNetInfo->mac, mac_addr, 6);
    memcpy(p_LocalNetInfo->ip, ip_addr, 4);
    memcpy(p_LocalNetInfo->sn, subnet, 4);
    memcpy(p_LocalNetInfo->gw, gateway, 4);
    memcpy(p_LocalNetInfo->dns, dns_server, 4);
    p_LocalNetInfo->dhcp = NETINFO_STATIC;

    ctlnetwork(CN_SET_NETINFO, p_LocalNetInfo);

    return RET_OK;
}

int32_t initEthernetDHCP(uint8_t* mac_addr)
{
    wiz_NetInfo* p_LocalNetInfo = getLocalNetInfoPointer();

    if (mac_addr == NULL) return ERR_PARAM;

    initPHY();
    setTOETimerTickTo100US();
    ctlwizchip(CW_INIT_WIZCHIP, (uint8_t*) &SocketBufferSize);

    memcpy(p_LocalNetInfo->mac, mac_addr, 6);
    p_LocalNetInfo->dhcp = NETINFO_DHCP;

    ctlnetwork(CN_SET_NETINFO, p_LocalNetInfo);

    if (openSocketDHCPAndGetIpAddress(SOCK_DHCP) != DHCP_IP_LEASED) return RET_NOK;

    return RET_OK;
}

void maintainDHCP()
{
    DHCP_run();
}

int32_t openSocketAsServer(uint8_t sock_num, uint16_t port_num)
{
    if (socket(sock_num, Sn_MR_TCP, port_num, SF_TCP_NODELAY) == sock_num) {
        listen(sock_num);
        return RET_OK;
    }
    return RET_NOK;
}

int32_t openSocketAsClient(uint8_t sock_num)
{
    if (client_any_port) {
        client_any_port++;
    }
    else if (client_any_port == 0) {
        srand(getDeviceUptimeMsec());
        client_any_port = (rand() % 10000) + 35000;
    }

    if (socket(sock_num, Sn_MR_TCP, client_any_port, SF_TCP_NODELAY) == sock_num) return RET_OK;
    return RET_NOK;
}

int32_t openSocketAsUDPPeer(uint8_t sock_num, uint16_t port_num)
{
    if(socket(sock_num, Sn_MR_UDP, port_num, 0) == sock_num){
        return RET_OK;
    }
    return RET_NOK;
}

int32_t connectToServerDomain(uint8_t sock_num, uint8_t* domain_name, uint16_t dest_port)
{
    uint8_t domain_ip_addr[4];
    wiz_NetInfo* p_LocalNetInfo = getLocalNetInfoPointer();

    openSocketDNSAndGetIpAddress(SOCK_DNS, p_LocalNetInfo->dns, domain_name, domain_ip_addr);

    if (connect(sock_num, domain_ip_addr, dest_port) == SOCK_OK) return RET_OK;
    return RET_NOK;
}

int32_t connectToServerIP(uint8_t sock_num, uint8_t* dest_ip_addr, uint16_t dest_port)
{
    if (connect(sock_num, dest_ip_addr, dest_port) == SOCK_OK) return RET_OK;
    return RET_NOK;
}

int32_t disconnectTCPConnection(uint8_t sock_num)
{
    if (disconnect(sock_num) == SOCK_OK) return RET_OK;
    return RET_NOK;
}

int32_t isTCPSocketConnected(uint8_t sock_num)
{
    switch (getSocketStatus(sock_num))
    {
        case SOCK_STATUS_ESTABLISHED:
            return TRUE;

        case SOCK_STATUS_CLOSE_WAIT:
            disconnectTCPConnection(sock_num);
            break;
    }
    return FALSE;
}

int32_t sendDataTCP(uint8_t sock_num, uint8_t * send_buf, uint16_t send_len)
{
    if (send_buf == NULL) return ERR_PARAM;
    return send(sock_num, send_buf, send_len);
}

int32_t sendDataUDP(uint8_t sock_num, uint8_t* send_buf, uint16_t send_len, uint8_t* peer_addr, uint16_t peer_port)
{
    if ((send_buf == NULL) || (peer_addr == NULL)) return ERR_PARAM;
    return sendto(sock_num, send_buf, send_len, peer_addr, peer_port);
}

int32_t receiveDataTCP(uint8_t sock_num, uint8_t* recv_buf, uint16_t read_len)
{
    if (recv_buf == NULL) return ERR_PARAM;
    return recv(sock_num, recv_buf, read_len);
}

int32_t receiveDataUDP(uint8_t sock_num, uint8_t* recv_buf, uint16_t read_len, uint8_t* peer_addr, uint16_t* peer_port)
{
    if ((recv_buf == NULL) || (peer_addr == NULL)) return ERR_PARAM;
    return recvfrom(sock_num, recv_buf, read_len, peer_addr, peer_port);
}

int32_t getSocketReceivedDataSize(uint8_t sock_num)
{
    if (sock_num >= _WIZCHIP_SOCK_NUM_) return ERR_PARAM;;
    return getSn_RX_RSR(sock_num);
}

int8_t openSocketDHCPAndGetIpAddress(uint8_t sock_num)
{
    uint8_t ret = 0;
    uint8_t dhcp_retry = 0;
    uint8_t dhcp_msg_buf[1024];

    WIZ_PRINT(" - DHCP Client running\r\n");

    DHCP_init(sock_num, dhcp_msg_buf);
    reg_dhcp_cbfunc(assignDHCPNetworkInfo, updateDHCPNetworkInfo, resetWIZCHIPForConflict);

    while (1) {
        ret = DHCP_run();

        if (ret == DHCP_IP_LEASED) {
            WIZ_PRINT(" - DHCP Success\r\n");
            break;
        }
        else if (ret == DHCP_FAILED) {
            dhcp_retry++;
            if (dhcp_retry <= 3) WIZ_PRINT(" - DHCP Timeout occurred and retry [%d]\r\n", dhcp_retry);
        }

        if (dhcp_retry > 3) {
            WIZ_PRINT(" - DHCP Failed\r\n\r\n");
            DHCP_stop();
            break;
        }
    }

    return ret;
}

void assignDHCPNetworkInfo(void)
{
    wiz_NetInfo NetworkInfo;

    ctlnetwork(CN_GET_NETINFO, &NetworkInfo);

    getIPfromDHCP(NetworkInfo.ip);
    getGWfromDHCP(NetworkInfo.gw);
    getSNfromDHCP(NetworkInfo.sn);
    getDNSfromDHCP(NetworkInfo.dns);
    NetworkInfo.dhcp = NETINFO_DHCP;

    ctlnetwork(CN_SET_NETINFO, &NetworkInfo);

    WIZ_PRINT("DHCP LEASED TIME : %d sec. \r\n", getDHCPLeasetime());
}

void updateDHCPNetworkInfo(void)
{
    wiz_NetInfo NetworkInfo;

    ctlnetwork(CN_GET_NETINFO, &NetworkInfo);

    getIPfromDHCP(NetworkInfo.ip);
    getGWfromDHCP(NetworkInfo.gw);
    getSNfromDHCP(NetworkInfo.sn);
    getDNSfromDHCP(NetworkInfo.dns);
    NetworkInfo.dhcp = NETINFO_DHCP;

    ctlnetwork(CN_SET_NETINFO, &NetworkInfo);

    WIZ_PRINT("DHCP LEASED TIME : %d sec. \r\n", getDHCPLeasetime());
}

void resetWIZCHIPForConflict(void)
{
    // TODO
    ;
}

int8_t openSocketDNSAndGetIpAddress(uint8_t sock_num, uint8_t* dns_server_ip, uint8_t* dns_domain_name, uint8_t* ip_addr_receive_buf)
{
    int8_t ret = 0;
    uint8_t dns_retry = 0;
    uint8_t dns_msg_buf[1024];

    WIZ_PRINT(" - DNS Client running\r\n");

    DNS_init(sock_num, dns_msg_buf);

    while (1) {
        if ((ret = DNS_run(dns_server_ip, dns_domain_name, ip_addr_receive_buf)) == 1) {
            WIZ_PRINT(" - DNS Success\r\n");
            break;
        }
        else {
            dns_retry++;
            if (dns_retry <= 2) WIZ_PRINT(" - DNS Timeout occurred and retry [%d]\r\n", dns_retry);
        }

        if (dns_retry > 2) {
            WIZ_PRINT(" - DNS Failed\r\n\r\n");
            break;
        }
    }

    return ret;
}
