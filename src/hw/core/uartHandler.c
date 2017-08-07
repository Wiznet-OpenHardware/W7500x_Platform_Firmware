#include <stdio.h>
#include <string.h>

#include "hw.h"
#include "W7500x_uart.h"
#include "W7500x_gpio.h"

#include "common.h"

volatile uint16_t uart_timer_ms;

/* Private define */

/* Private MACRO */
#ifdef USE_UART0
BUFFER_DEFINITION(uart0_rx, UART0_BUF_SIZE);
#endif
#ifdef USE_UART1
BUFFER_DEFINITION(uart1_rx, UART1_BUF_SIZE);
#endif

/* Private Structure */
typedef struct
{
    UART_TypeDef* Register;
    UART_InitTypeDef Definition;
    IRQn_Type IRQNum;
    uint8_t uart_interface;
    uint8_t enable;
} HW_UartStructure;

HW_UartStructure UartStructure[UART_CH_MAX];

/* Private variables */
uint8_t flag_uart_ringbuf_full[UART_CH_MAX];
#ifdef __USE_GPIO_HARDWARE_FLOWCONTROL__
static uint8_t rts_status = UART_RTS_LOW;
#endif
static uint8_t uart_rs422_or_485_selector = UART_IF_RS422;

/* Private Functions */
void delayMsForUart(uint32_t millisecond);

/* Functions Definition */
int32_t initUart(uint8_t uart_ch, uint32_t baud, uint8_t data_bit, uint8_t parity, uint8_t stop_bit, uint8_t flow_control)
{
    UART_TypeDef * UartRegister;
    UART_InitTypeDef * UartInitStruct;
    IRQn_Type UartIRQ;

    if (uart_ch > UART_CH_MAX) return ERR_PARAM;
    if ((data_bit > WORD_LEN8) || (data_bit < WORD_LEN5)) return ERR_PARAM;
    if (parity > PARITY_EVEN) return ERR_PARAM;
    if (stop_bit > STOP_BIT2) return ERR_PARAM;
    if (flow_control > FLOW_RTS_CTS) return ERR_PARAM;

    switch (uart_ch)
    {
        case UART_CH0:
            UartStructure[uart_ch].Register = UART0;
            UartStructure[uart_ch].IRQNum = UART0_IRQn;
            break;
        case UART_CH1:
            UartStructure[uart_ch].Register = UART1;
            UartStructure[uart_ch].IRQNum = UART1_IRQn;
            break;
    }

    UartRegister = UartStructure[uart_ch].Register;
    UartInitStruct = &UartStructure[uart_ch].Definition;
    UartIRQ = UartStructure[uart_ch].IRQNum;

    UART_StructInit(UartInitStruct);

    UartStructure[uart_ch].Definition.UART_BaudRate = baud;

    switch (data_bit)
    {
        case WORD_LEN5:
            UartInitStruct->UART_WordLength = UART_WordLength_5b;
            break;
        case WORD_LEN6:
            UartInitStruct->UART_WordLength = UART_WordLength_6b;
            break;
        case WORD_LEN7:
            UartInitStruct->UART_WordLength = UART_WordLength_7b;
            break;
        case WORD_LEN8:
            UartInitStruct->UART_WordLength = UART_WordLength_8b;
            break;
    }

    switch (parity)
    {
        case PARITY_NONE:
            UartInitStruct->UART_Parity = UART_Parity_No;
            break;
        case PARITY_ODD:
            UartInitStruct->UART_Parity = UART_Parity_Odd;
            break;
        case PARITY_EVEN:
            UartInitStruct->UART_Parity = UART_Parity_Even;
            break;
        default:
            return ERR_PARAM;
    }

    switch (stop_bit)
    {
        case STOP_BIT1:
            UartInitStruct->UART_StopBits = UART_StopBits_1;
            break;
        case STOP_BIT2:
            UartInitStruct->UART_StopBits = UART_StopBits_2;
            break;
        default:
            return ERR_PARAM;
    }

    setUartInterfaceToStructure(uart_ch, UART_IF_RS232_TTL);
    setUartFlowcontrolToStructure(uart_ch, flow_control);

    UART_Init(UartRegister, UartInitStruct);

    UART_ITConfig(UartRegister, UART_IT_FLAG_RXI, ENABLE);

    NVIC_ClearPendingIRQ(UartIRQ);
    NVIC_SetPriority(UartIRQ, 1);
    NVIC_EnableIRQ(UartIRQ);

    UartStructure[uart_ch].enable = ENABLE;

    return RET_OK;
}

int32_t setUartInterfaceToStructure(uint8_t uart_ch, uint8_t interface)
{
    if (uart_ch > UART_CH_MAX) return ERR_PARAM;
    UartStructure[uart_ch].uart_interface = interface;
    return RET_OK;
}

int32_t setUartTxRxMode(uint8_t uart_ch, uint8_t tx_enable, uint8_t rx_enable)
{
    UART_InitTypeDef * UartInitStruct = &UartStructure[uart_ch].Definition;
    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    if (tx_enable && rx_enable) {
        UartInitStruct->UART_Mode = UART_Mode_Rx | UART_Mode_Tx;
    }
    else if (tx_enable) {
        UartInitStruct->UART_Mode = UART_Mode_Tx;
    }
    else if (rx_enable) {
        UartInitStruct->UART_Mode = UART_Mode_Rx;
    }
    else {
        return ERR_PARAM;
    }
    return ERR_PARAM;
}

int32_t setUartFlowcontrolToStructure(uint8_t uart_ch, uint8_t flow_control)
{
    UART_InitTypeDef * UartInitStruct;
    UART_TypeDef * UartRegister;

    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;
    if (flow_control > FLOW_RTS_CTS) return ERR_PARAM;

    UartInitStruct = &UartStructure[uart_ch].Definition;
    UartRegister = UartStructure[uart_ch].Register;

    if (UartStructure[uart_ch].uart_interface == UART_IF_RS232_TTL) {
        switch (flow_control)
        {
            case FLOW_NONE:
                UartInitStruct->UART_HardwareFlowControl =
                UART_HardwareFlowControl_None;
                break;
            case FLOW_RTS_CTS:
#ifdef __USE_GPIO_HARDWARE_FLOWCONTROL__
                if (UartRegister == UART0) {
#ifdef USE_UART0
                    GPIO_Configuration(UART0_RTS_PORT, UART0_RTS_PIN,
                            GPIO_Mode_OUT, UART0_RTS_PAD_AF);
                    GPIO_Configuration(UART0_CTS_PORT, UART0_CTS_PIN,
                            GPIO_Mode_IN, UART0_CTS_PAD_AF);
                    setUartRTSpinToLow(0);
#endif
                }
                else if (UartRegister == UART1) {
#ifdef USE_UART1
                    GPIO_Configuration(UART1_RTS_PORT, UART1_RTS_PIN,
                            GPIO_Mode_OUT, UART1_RTS_PAD_AF);
                    GPIO_Configuration(UART1_CTS_PORT, UART1_CTS_PIN,
                            GPIO_Mode_IN, UART1_CTS_PAD_AF);
                    setUartRTSpinToLow(1);
#endif
                }
#else
                UartInitStruct->UART_HardwareFlowControl =
                UART_HardwareFlowControl_RTS_CTS;
#endif
                break;
            case FLOW_XON_XOFF:
                UartInitStruct->UART_HardwareFlowControl =
                UART_HardwareFlowControl_None;
                break;
            default:
                return ERR_PARAM;
        }
    }
    else if (UartStructure[uart_ch].uart_interface == UART_IF_RS422_485) {
        UartInitStruct->UART_HardwareFlowControl =
        UART_HardwareFlowControl_None;

        getUartRS485SelectPinState(uart_ch);
        initUartRTSpin(uart_ch);
        WIZ_PRINT("UART Interface: %s mode\r\n", uart_rs422_or_485_selector?"RS-485":"RS-422");
    }

    UartStructure[uart_ch].Definition.UART_HardwareFlowControl = flow_control;
    return RET_OK;
}

int32_t writeUartData(uint8_t uart_ch, uint8_t *send_buf, uint16_t length)
{
    uint16_t total_length = 0;

    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;
    if (send_buf == NULL) return ERR_PARAM;

    while (*send_buf != '\0' && total_length < length) {
        UartPutc(UartStructure[uart_ch].Register, *send_buf++);
        total_length++;
    }
    return total_length;
}

int32_t getUartReceivedDataSize(uint8_t uart_ch)
{
    int32_t recv_size = 0;

    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    switch (uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
            recv_size = BUFFER_USED_SIZE(uart0_rx);
#endif
            break;
        case UART_CH1:
#ifdef USE_UART1
            recv_size = BUFFER_USED_SIZE(uart1_rx);
#endif
            break;
        default:
            return ERR_PARAM;
    }
    return recv_size;
}

int32_t readUartData(uint8_t uart_ch, uint8_t *recv_buf, uint16_t length)
{
    uint16_t total_length = 0, first_length = 0;

    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;
    if (recv_buf == NULL) return ERR_PARAM;
    if (length == 0) return 0;

    switch (uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
            total_length = length = MIN(BUFFER_USED_SIZE(uart0_rx), length);
            if (IS_BUFFER_OUT_SEPARATED(uart0_rx) && (first_length =
                            BUFFER_OUT_1ST_SIZE(uart0_rx)) < length) {
                memcpy(recv_buf, &BUFFER_OUT(uart0_rx), first_length);
                BUFFER_OUT_MOVE(uart0_rx, first_length);
                length -= first_length;
            }
            memcpy(recv_buf + first_length, &BUFFER_OUT(uart0_rx), length);
            BUFFER_OUT_MOVE(uart0_rx, length);
#endif
            break;
        case UART_CH1:
#ifdef USE_UART1
            total_length = length = MIN(BUFFER_USED_SIZE(uart1_rx), length);
            if (IS_BUFFER_OUT_SEPARATED(uart1_rx) && (first_length = BUFFER_OUT_1ST_SIZE(uart1_rx)) < length) {
                memcpy(recv_buf, &BUFFER_OUT(uart1_rx), first_length);
                BUFFER_OUT_MOVE(uart1_rx, first_length);
                length -= first_length;
            }
            memcpy(recv_buf + first_length, &BUFFER_OUT(uart1_rx), length);
            BUFFER_OUT_MOVE(uart1_rx, length);
#endif
            break;
        default:
            return ERR_PARAM;
    }

    return total_length;
}

int32_t flushUartRxBuffer(uint8_t uart_ch)
{
    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    switch (uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
            BUFFER_CLEAR(uart0_rx)
#endif
            break;
        case UART_CH1:
#ifdef USE_UART1
            BUFFER_CLEAR(uart1_rx)
#endif
            break;
    }

    return RET_OK;
}

void handleUartZeroIRQ()
{
    UART_TypeDef* UartRegister = UART0;
    UART_InitTypeDef* UartDefinition = &UartStructure[UART_CH0].Definition;

    if (UART_GetITStatus(UartRegister, UART_IT_FLAG_RXI)) {
#ifdef USE_UART0
        if (IS_BUFFER_FULL(uart0_rx)) {
            UART_ReceiveData(UartRegister);

            flag_uart_ringbuf_full[UART_CH0] = 1;
        }
        else {
#ifdef __USE_GPIO_HARDWARE_FLOWCONTROL__
            if (UartDefinition->UART_HardwareFlowControl
                    == FLOW_RTS_CTS) {
                ;
            }
#else
            if ((UartDefinition->UART_HardwareFlowControl == FLOW_RTS_CTS) && (BUFFER_USED_SIZE(uart0_rx) > UART0_OFF_THRESHOLD)) // CTS/RTS
            {
                ; // Does nothing => RTS signal inactive
            }
            else
#endif
            {
                BUFFER_IN(uart0_rx)= UART_ReceiveData(UartRegister);
                BUFFER_IN_MOVE(uart0_rx, 1);
            }
        }
#endif
        UART_ClearITPendingBit(UartRegister, UART_IT_FLAG_RXI);
    }
}
void handleUartOneIRQ()
{
    UART_TypeDef* UartRegister = UART1;
    UART_InitTypeDef* UartDefinition = &UartStructure[UART_CH1].Definition;

    if (UART_GetITStatus(UartRegister, UART_IT_FLAG_RXI)) {
#ifdef USE_UART1
        if (IS_BUFFER_FULL(uart1_rx)) {
            UART_ReceiveData(UartRegister);
            flag_uart_ringbuf_full[UART_CH1] = 1;
        }
        else {
#ifdef __USE_GPIO_HARDWARE_FLOWCONTROL__
            if (UartDefinition->UART_HardwareFlowControl
                    == FLOW_RTS_CTS) {
                ;
            }
#else
            if ((UartDefinition->UART_HardwareFlowControl == FLOW_RTS_CTS) && (BUFFER_USED_SIZE(uart1_rx) > UART1_OFF_THRESHOLD )) // CTS/RTS
            {
                ; // Does nothing => RTS signal inactive
            }
            else
#endif
            {
                BUFFER_IN(uart1_rx)= UART_ReceiveData(UartRegister);
                BUFFER_IN_MOVE(uart1_rx, 1);
            }
        }
#endif
        UART_ClearITPendingBit(UartRegister, UART_IT_FLAG_RXI);
    }
}

int32_t getUartRS485SelectPinState(uint8_t uart_ch)
{
    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    switch (uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
            GPIO_Configuration(UART0_RTS_PORT, UART0_RTS_PIN, GPIO_Mode_IN,
                    UART0_RTS_PAD_AF);
            GPIO_SetBits(UART0_RTS_PORT, UART0_RTS_PIN);

            if (GPIO_ReadInputDataBit(UART0_RTS_PORT,
                            UART0_RTS_PIN) == UART_IF_RS422) {
                uart_rs422_or_485_selector = UART_IF_RS422;
            }
            else {
                uart_rs422_or_485_selector = UART_IF_RS485;
            }
#endif
            break;

        case UART_CH1:
#ifdef USE_UART1
            GPIO_Configuration(UART1_RTS_PORT, UART1_RTS_PIN, GPIO_Mode_IN,
            UART1_RTS_PAD_AF);
            GPIO_SetBits(UART1_RTS_PORT, UART1_RTS_PIN);

            if (GPIO_ReadInputDataBit(UART1_RTS_PORT,
            UART1_RTS_PIN) == UART_IF_RS422) {
                uart_rs422_or_485_selector = UART_IF_RS422;
            }
            else {
                uart_rs422_or_485_selector = UART_IF_RS485;
            }
#endif
            break;
    }
    return uart_rs422_or_485_selector;
}

int32_t initUartRTSpin(uint8_t uart_ch)
{
    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    switch (uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
            GPIO_Configuration(UART0_RTS_PORT, UART0_RTS_PIN, GPIO_Mode_OUT,
                    UART0_RTS_PAD_AF);
            GPIO_ResetBits(UART0_RTS_PORT, UART0_RTS_PIN);
#endif
            break;
        case UART_CH1:
#ifdef USE_UART1
            GPIO_Configuration(UART1_RTS_PORT, UART1_RTS_PIN, GPIO_Mode_OUT,
            UART1_RTS_PAD_AF);
            GPIO_ResetBits(UART1_RTS_PORT, UART1_RTS_PIN);
#endif
            break;
    }
    return RET_OK;
}

int32_t setUartRS485RTSpinToHigh(uint8_t uart_ch)
{
    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;
    if (uart_rs422_or_485_selector != UART_IF_RS485) return ERR_PARAM;

    switch (uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
            GPIO_SetBits(UART0_RTS_PORT, UART0_RTS_PIN);
            delayMsForUart(1);
#endif
            break;
        case UART_CH1:
#ifdef USE_UART1
            GPIO_SetBits(UART1_RTS_PORT, UART1_RTS_PIN);
            delayMsForUart(1);
#endif
            break;
    }
    return RET_OK;
}

int32_t setUartRS485RTSpinToLow(uint8_t uart_ch)
{
    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;
    if (uart_rs422_or_485_selector != UART_IF_RS485) return ERR_PARAM;

    switch (uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
            GPIO_ResetBits(UART0_RTS_PORT, UART0_RTS_PIN);
            delayMsForUart(1);
#endif
            break;
        case UART_CH1:
#ifdef USE_UART1
            GPIO_ResetBits(UART1_RTS_PORT, UART1_RTS_PIN);
            delayMsForUart(1);
#endif
            break;
    }
    return RET_OK;
}

void delayMsForUart(uint32_t millisecond)
{
    uart_timer_ms = 0;

    while (uart_timer_ms <= millisecond)
        ;
}

#ifdef __USE_GPIO_HARDWARE_FLOWCONTROL__

static uint8_t xonoff_status = UART_XON;

int32_t getUartFlowcontrolState(uint8_t uart_ch, uint8_t flow_ctrl)
{
    UART_TypeDef* UartRegister = UartStructure[uart_ch].Register;

    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    switch (uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
        if (flow_ctrl == FLOW_XON_XOFF) {
            if ((xonoff_status == UART_XON)
                    && (BUFFER_USED_SIZE(uart0_rx) > UART0_OFF_THRESHOLD)) {
                UartPutc(UartRegister, UART_XOFF);
                xonoff_status = UART_XOFF;
                WIZ_PRINT(" >> SEND XOFF [%d / %d]\r\n", BUFFER_USED_SIZE(uart0_rx), UART0_BUF_SIZE);
            }
        }
        else if ((xonoff_status == UART_XOFF)
                && (BUFFER_USED_SIZE(uart0_rx) < UART0_ON_THRESHOLD)) {
            UartPutc(UartRegister, UART_XON);
            xonoff_status = UART_XON;
            WIZ_PRINT(" >> SEND XON [%d / %d]\r\n", BUFFER_USED_SIZE(uart0_rx), UART0_BUF_SIZE);
        }
        else if (flow_ctrl == FLOW_RTS_CTS) {
            // Buffer full occurred
            if ((rts_status == UART_RTS_LOW)
                    && (BUFFER_USED_SIZE(uart0_rx) > UART0_OFF_THRESHOLD)) {
                setUartRTSpinToHigh(uart_ch);
                rts_status = UART_RTS_HIGH;
                WIZ_PRINT(" >> UART_RTS_HIGH [%d / %d]\r\n",
                        BUFFER_USED_SIZE(uart0_rx), UART0_BUF_SIZE);
            }
            // Clear the buffer full event
            if ((rts_status == UART_RTS_HIGH)
                    && (BUFFER_USED_SIZE(uart0_rx) <= UART0_OFF_THRESHOLD)) {
                setUartRTSpinToLow(uart_ch);
                rts_status = UART_RTS_LOW;
                WIZ_PRINT(
                        " >> UART_RTS_LOW [%d / %d]\r\n", BUFFER_USED_SIZE(uart0_rx),
                        UART0_BUF_SIZE);
            }
        }
#endif
        break;
        case UART_CH1:
#ifdef USE_UART1
        if (flow_ctrl == FLOW_XON_XOFF) {
            if (xonoff_status == UART_XON) {

                if (BUFFER_USED_SIZE(uart1_rx) > UART1_OFF_THRESHOLD)
                {
                    UartPutc(UartRegister, UART_XOFF);
                    xonoff_status = UART_XOFF;
                    WIZ_PRINT(" >> SEND XOFF [%d / %d]\r\n", BUFFER_USED_SIZE(uart1_rx), UART1_BUF_SIZE);
                }
            }
        }
        else if ((xonoff_status == UART_XOFF)
                && (BUFFER_USED_SIZE(uart1_rx) < UART1_ON_THRESHOLD))
        {
            UartPutc(UartRegister, UART_XON);
            xonoff_status = UART_XON;
            WIZ_PRINT(" >> SEND XON [%d / %d]\r\n", BUFFER_USED_SIZE(uart1_rx), UART1_BUF_SIZE);
        }
        else if (flow_ctrl == FLOW_RTS_CTS) {
            // Buffer full occurred
            if ((rts_status == UART_RTS_LOW)
                    && (BUFFER_USED_SIZE(uart1_rx) > UART1_OFF_THRESHOLD)) {
                setUartRTSpinToHigh(uart_ch);
                rts_status = UART_RTS_HIGH;
                WIZ_PRINT(" >> UART_RTS_HIGH [%d / %d]\r\n",
                        BUFFER_USED_SIZE(uart1_rx), UART1_BUF_SIZE);
            }
            // Clear the buffer full event
            if ((rts_status == UART_RTS_HIGH)
                    && (BUFFER_USED_SIZE(uart1_rx) <= UART1_OFF_THRESHOLD)) {
                setUartRTSpinToLow(uart_ch);
                rts_status = UART_RTS_LOW;
                WIZ_PRINT(
                        " >> UART_RTS_LOW [%d / %d]\r\n", BUFFER_USED_SIZE(uart1_rx),
                        UART1_BUF_SIZE);
            }
        }
#endif
        break;
    }
}

int32_t getUartCTSpinState(uint8_t uart_ch)
{
    uint8_t cts_pin;
    static uint8_t prev_cts_pin;

    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    switch(uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
        cts_pin = GPIO_ReadInputDataBit(UART0_CTS_PORT, UART0_CTS_PIN);
#endif
        break;
        case UART_CH1:
#ifdef USE_UART1
        cts_pin = GPIO_ReadInputDataBit(UART1_CTS_PORT, UART1_CTS_PIN);
#endif
        break;
    }

    if(cts_pin != prev_cts_pin)
    {
        WIZ_PRINT(" >> UART_CTS_%s\r\n", cts_pin?"HIGH":"LOW");
        prev_cts_pin = cts_pin;
    }

    return cts_pin;
}

int32_t setUartRTSpinToHigh(uint8_t uart_ch)
{
    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    switch(uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
        GPIO_SetBits(UART0_RTS_PORT, UART0_RTS_PIN);
#endif
        break;
        case UART_CH1:
#ifdef USE_UART1
        GPIO_SetBits(UART1_RTS_PORT, UART1_RTS_PIN);
#endif
        break;
    }
}

int32_t setUartRTSpinToLow(uint8_t uart_ch)
{
    if ((uart_ch > UART_CH_MAX) || (UartStructure[uart_ch].enable != ENABLE)) return ERR_PARAM;

    switch(uart_ch)
    {
        case UART_CH0:
#ifdef USE_UART0
        GPIO_ResetBits(UART0_RTS_PORT, UART0_RTS_PIN);
#endif
        break;
        case UART_CH1:
#ifdef USE_UART1
        GPIO_ResetBits(UART1_RTS_PORT, UART1_RTS_PIN);
#endif
        break;
    }
}

#endif
