/* Includes ------------------------------------------------------------------*/

#include "hw.h"
#include "common.h"
#include "W7500x_gpio.h"

typedef struct
{
    GPIO_TypeDef* scl_port;
    uint16_t scl_pin;
    GPIO_TypeDef* sda_port;
    uint16_t sda_pin;
} HW_GpioI2CStructure;

HW_GpioI2CStructure GpioI2C[GPIO_I2C_CH_MAX];

/* Private functions prototype -----------------------------------------------*/
void setSCLPinToHigh(void);
void setSCLPinToLow(void);
void setSDAPinToHigh(void);
void setSDAPinToLow(void);
void delayUsForSoftI2C(uint16_t microsecond);

/* Public functions ----------------------------------------------------------*/
void initSoftI2C(void)
{
    // SCL
    GPIO_Configuration(I2C_SCL_PORT, I2C_SCL_PIN, GPIO_Mode_OUT, I2C_PAD_AF);
    GPIO_SetBits(I2C_SCL_PORT, I2C_SCL_PIN);

    // SDA
    GPIO_Configuration(I2C_SDA_PORT, I2C_SDA_PIN, GPIO_Mode_IN, I2C_PAD_AF);
    GPIO_ResetBits(I2C_SCL_PORT, I2C_SCL_PIN);
}

void startSoftI2C(void)
{
    setSDAPinToHigh();
    setSCLPinToHigh();
    delayUsForSoftI2C(4);
    setSDAPinToLow();
    delayUsForSoftI2C(4);
    setSCLPinToLow();
}

void stopSoftI2C(void)
{
    setSCLPinToLow();
    setSDAPinToLow();
    delayUsForSoftI2C(4);
    setSCLPinToHigh();
    setSDAPinToHigh();
    delayUsForSoftI2C(4);
}

uint8_t waitSoftI2CAck(void)
{
    uint16_t ucErrTime = 0;

    setSDAPinToHigh();
    delayUsForSoftI2C(1);
    setSCLPinToHigh();
    delayUsForSoftI2C(1);

    while (GPIO_ReadInputDataBit(I2C_SDA_PORT, I2C_SDA_PIN)) {
        ucErrTime++;
        if (ucErrTime > 2500) {
            stopSoftI2C();
            return 1;
        }
    }

    setSCLPinToLow();

    return 0;
}

void sendSoftI2CAck(void)
{
    setSCLPinToLow();
    setSDAPinToLow();
    delayUsForSoftI2C(2);
    setSCLPinToHigh();
    delayUsForSoftI2C(2);
    setSCLPinToLow();
}

void sendSoftI2CNack(void)
{
    setSCLPinToLow();
    setSDAPinToHigh();
    delayUsForSoftI2C(2);
    setSCLPinToHigh();
    delayUsForSoftI2C(2);
    setSCLPinToLow();
}

void sendSoftI2CByte(uint8_t txd)
{
    uint8_t t;

    setSCLPinToLow();

    for (t = 0; t < 8; t++) {
        if (txd & 0x80) setSDAPinToHigh();
        else setSDAPinToLow();

        txd <<= 1;

        delayUsForSoftI2C(2);
        setSCLPinToHigh();
        delayUsForSoftI2C(2);
        setSCLPinToLow();
        delayUsForSoftI2C(2);
    }
}

uint8_t readSoftI2CByte(unsigned char ack)
{
    unsigned char i, receive = 0;

    setSDAPinToHigh();

    for (i = 0; i < 8; i++) {
        setSCLPinToLow();
        delayUsForSoftI2C(2);
        setSCLPinToHigh();
        receive <<= 1;

        if (GPIO_ReadInputDataBit(I2C_SDA_PORT, I2C_SDA_PIN)) receive++;

        delayUsForSoftI2C(1);
    }

    if (!ack) sendSoftI2CNack();
    else sendSoftI2CAck();

    return receive;
}

void setSCLPinToHigh(void)
{
    GPIO_SetBits(I2C_SCL_PORT, I2C_SCL_PIN);
}

void setSCLPinToLow(void)
{
    GPIO_ResetBits(I2C_SCL_PORT, I2C_SCL_PIN);
}

void setSDAPinToHigh(void)
{
    I2C_SDA_PORT->OUTENCLR = I2C_SDA_PIN;
}

void setSDAPinToLow(void)
{
    I2C_SDA_PORT->OUTENSET = I2C_SDA_PIN;
}

void delayUsForSoftI2C(uint16_t microsecond)
{
    volatile uint32_t clk_cnt;

    clk_cnt = microsecond * (GetSystemClock() / 1000000 / 10);
    while (clk_cnt--)
        ;
}
