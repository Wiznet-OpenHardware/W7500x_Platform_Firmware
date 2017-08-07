
#ifndef __I2CHANDLER_H__
#define __I2CHANDLER_H__

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "W7500x_gpio.h"

typedef struct{
        GPIO_TypeDef* scl_port;
        uint16_t scl_pin;
        GPIO_TypeDef* sda_port;
        uint16_t sda_pin;
}HW_GpioI2CStructure;

#define GPIO_I2C_CH_MAX 1


// Define the GPIO pins for EEPROM access via I2C bus interface 
#define I2C_SCL_PIN     GPIO_Pin_4
#define I2C_SCL_PORT    GPIOC
#define I2C_SDA_PIN     GPIO_Pin_5
#define I2C_SDA_PORT    GPIOC
#define I2C_PAD_AF      PAD_AF1 // GPIO

void initSoftI2C(void);
void startSoftI2C(void);
void stopSoftI2C(void);
uint8_t waitSoftI2CAck(void);
void sendSoftI2CAck(void);
void sendSoftI2CNack(void);
void sendSoftI2CByte(uint8_t txd);
uint8_t readSoftI2CByte(unsigned char ack);

#endif
