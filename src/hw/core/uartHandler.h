#ifndef UARTHANDLER_H_
#define UARTHANDLER_H_

#include <stdint.h>
#include "common.h"

#ifndef UART_CH_MAX
#define UART_CH_MAX  2
#endif
#ifndef UART0_BUF_SIZE
#define UART0_BUF_SIZE 1024
#endif
#ifndef UART1_BUF_SIZE
#define UART1_BUF_SIZE 1024
#endif

extern uint8_t flag_uart_ringbuf_full[UART_CH_MAX];

/* XON/XOFF: Transmitter On/Off, Software flow control */
#define UART_XON				0x11 // 17
#define UART_XOFF				0x13 // 19
#define UART0_ON_THRESHOLD	(uint16_t)(UART0_BUF_SIZE / 10)
#define UART0_OFF_THRESHOLD	(uint16_t)(UART0_BUF_SIZE - UART0_ON_THRESHOLD)
#define UART1_ON_THRESHOLD  (uint16_t)(UART1_BUF_SIZE / 10)
#define UART1_OFF_THRESHOLD (uint16_t)(UART1_BUF_SIZE - UART1_ON_THRESHOLD)

/* UART interface selector, RS-232/TTL or RS-422/485 */
#define UART_IF_RS232_TTL			0
#define UART_IF_RS422_485			1
#define UART_IF_STR_RS232_TTL		"RS-232/TTL"
#define UART_IF_STR_RS422_485		"RS-422/485"

#define UART_IF_RS422				0
#define UART_IF_RS485				1

#define UART_IF_DEFAULT				UART_IF_RS232_TTL  //UART_IF_RS422_485

/* RTS: output, CTS: input */
#define UART_RTS_HIGH			1
#define UART_RTS_LOW			0

#define UART_CTS_HIGH			1
#define UART_CTS_LOW			0

#define MIN(_a, _b) (_a < _b) ? _a : _b
#define MEM_FREE(mem_p) do{ if(mem_p) { free(mem_p); mem_p = NULL; } }while(0)	//

/* UART Ring Buffer Macro */
#define BUFFER_DEFINITION(_name, _size) \
	uint8_t _name##_buf[_size]; \
	volatile uint16_t _name##_wr=0; \
	volatile uint16_t _name##_rd=0; \
	volatile uint16_t _name##_sz=_size;
#define BUFFER_DECLARATION(_name) \
	extern uint8_t _name##_buf[]; \
	extern uint16_t _name##_wr, _name##_rd, _name##_sz;
#define BUFFER_CLEAR(_name) \
	_name##_wr=0;\
	_name##_rd=0;

#define BUFFER_USED_SIZE(_name) ((_name##_sz + _name##_wr - _name##_rd) % _name##_sz)
#define BUFFER_FREE_SIZE(_name) ((_name##_sz + _name##_rd - _name##_wr - 1) % _name##_sz)
#define IS_BUFFER_EMPTY(_name) ( (_name##_rd) == (_name##_wr))
#define IS_BUFFER_FULL(_name) (BUFFER_FREE_SIZE(_name) == 0)

#define BUFFER_IN(_name) _name##_buf[_name##_wr]
#define BUFFER_IN_OFFSET(_name, _offset) _name##_buf[_name##_wr + _offset]
#define BUFFER_IN_MOVE(_name, _num) _name##_wr = (_name##_wr + _num) % _name##_sz
#define BUFFER_IN_1ST_SIZE(_name) (_name##_sz - _name##_wr - ((_name##_rd==0)?1:0))
#define BUFFER_IN_2ND_SIZE(_name) ((_name##_rd==0) ? 0 : _name##_rd-1)
#define IS_BUFFER_IN_SEPARATED(_name) (_name##_rd <= _name##_wr)

#define BUFFER_OUT(_name) _name##_buf[_name##_rd]
#define BUFFER_OUT_OFFSET(_name, _offset) _name##_buf[_name##_rd + _offset]
#define BUFFER_OUT_MOVE(_name, _num) _name##_rd = (_name##_rd + _num) % _name##_sz
#define BUFFER_OUT_1ST_SIZE(_name) (_name##_sz - _name##_rd)
#define BUFFER_OUT_2ND_SIZE(_name) (_name##_wr)
#define IS_BUFFER_OUT_SEPARATED(_name) (_name##_rd > _name##_wr)

typedef enum
{
    UART_CH0 = 0, UART_CH1 = 1
} UartChannel;

typedef enum
{
    WORD_LEN5 = 5, WORD_LEN6 = 6, WORD_LEN7 = 7, WORD_LEN8 = 8
} UartWordLength;

typedef enum
{
    PARITY_NONE = 0, PARITY_ODD = 1, PARITY_EVEN = 2
} UartParity;

typedef enum
{
    STOP_BIT1 = 1, STOP_BIT2 = 2
} UartStopbit;

typedef enum
{
    FLOW_NONE = 0, FLOW_XON_XOFF = 1, FLOW_RTS_CTS = 2
} UartFlowControl;

int32_t initUart(uint8_t uart_ch, uint32_t baud, uint8_t data_bit, uint8_t parity, uint8_t stop_bit, uint8_t flow_control);
int32_t updateUartSetting(uint8_t uart_ch);

int32_t setUartBaudrateToStructure(uint8_t uart_ch, uint8_t baud);
int32_t setUartTxRxMode(uint8_t uart_ch, uint8_t tx_enable, uint8_t rx_enable);
int32_t setUartInterfaceToStructure(uint8_t uart_ch, uint8_t interface);
int32_t setUartDatabitsToStructure(uint8_t uart_ch, uint8_t data_bits);
int32_t setUartParityToStructure(uint8_t uart_ch, uint8_t parity);
int32_t setUartStopbitsToStructure(uint8_t uart_ch, uint8_t stop_bits);
int32_t setUartFlowcontrolToStructure(uint8_t uart_ch, uint8_t flow_control);

int32_t getUartReceivedDataSize(uint8_t uart_ch);
int32_t writeUartData(uint8_t uart_ch, uint8_t *send_buf, uint16_t length);
int32_t readUartData(uint8_t uart_ch, uint8_t *recv_buf, uint16_t length);
int32_t flushUartRxBuffer(uint8_t uart_ch);

void handleUartZeroIRQ(void);
void handleUartOneIRQ(void);

int32_t initUartRTSpin(uint8_t uart_ch);
int32_t getUartFlowcontrolState(uint8_t uart_ch, uint8_t flow_ctrl);
int32_t getUartRS485SelectPinState(uint8_t uart_ch);
int32_t setUartRS485RTSpinToHigh(uint8_t uart_ch);
int32_t setUartRS485RTSpinToLow(uint8_t uart_ch);
int32_t getUartCTSpinState(uint8_t uart_ch);
int32_t setUartRTSpinToHigh(uint8_t uart_ch);
int32_t setUartRTSpinToLow(uint8_t uart_ch);

#endif /* UARTHANDLER_H_ */
