#include <stdio.h>

#include "W7500x.h"
#include "W7500x_gpio.h"

#include "common.h"
#include "hw.h"

int32_t initGpioPin(uint8_t port, uint8_t pin, uint8_t direction, uint8_t mode)
{
    GPIO_TypeDef* PortRegister = GPIOA;
    GPIO_InitTypeDef GpioDefinition;
    PAD_Type PortNum = PAD_PA;

    if ((port != PORT_A) && (port != PORT_B) && (port != PORT_C)) return ERR_PARAM;
    if (pin > 15) return ERR_PARAM;
    if ((direction != INPUT) && (direction != OUTPUT)) return ERR_PARAM;
    if ((mode != PULL_DOWN) && (mode != PULL_UP)) return ERR_PARAM;

    switch (port)
    {
        case PORT_A:
            PortRegister = GPIOA;
            PortNum = PAD_PA;
            break;
        case PORT_B:
            PortRegister = GPIOB;
            PortNum = PAD_PB;
            break;
        case PORT_C:
            PortRegister = GPIOC;
            PortNum = PAD_PC;
            break;
    }

#if (USING_CHIP == W7500P)
    if(((port == PORT_A)&&(pin > PORT_A_MAX_PIN))||((port == PORT_B)&&(pin > PORT_B_MAX_PIN))) return ERR_PARAM;
#endif
    GpioDefinition.GPIO_Pin = (uint32_t) (0x01 << pin);

    switch (direction)
    {
        case INPUT:
            GpioDefinition.GPIO_Mode = GPIO_Mode_IN;
            break;
        case OUTPUT:
            GpioDefinition.GPIO_Mode = GPIO_Mode_OUT;
            break;
    }

    GpioDefinition.GPIO_Pad = (GPIOPad_TypeDef) (GPIO_SUMMIT | GPIO_IE);
    switch (mode)
    {
        case PULL_DOWN:
            GpioDefinition.GPIO_Pad |= GPIO_PuPd_DOWN;
            break;
        case PULL_UP:
            GpioDefinition.GPIO_Pad |= GPIO_PuPd_UP;
            break;
    }

    GPIO_Init(PortRegister, &GpioDefinition);
    PAD_AFConfig(PortNum, GpioDefinition.GPIO_Pin, PAD_AF1);

    return RET_OK;
}

int32_t setGpioPin(uint8_t port, uint8_t pin, uint8_t one_bit)
{
    GPIO_TypeDef* PortRegister = GPIOA;
    uint16_t pin_num = (uint16_t) (0x01 << pin);

    if (port > PORT_C) return ERR_PARAM;
    if (pin > 15) return ERR_PARAM;
    if ((one_bit != LOW) && (one_bit != HIGH)) return ERR_PARAM;

    switch (port)
    {
        case PORT_A:
            PortRegister = GPIOA;
            break;
        case PORT_B:
            PortRegister = GPIOB;
            break;
        case PORT_C:
            PortRegister = GPIOC;
            break;
    }

    switch (one_bit)
    {
        case LOW:
            GPIO_ResetBits(PortRegister, pin_num);
            break;
        case HIGH:
            GPIO_SetBits(PortRegister, pin_num);
            break;
    }

    return RET_OK;
}

int32_t getGpioPinInputState(uint8_t port, uint8_t pin)
{
    uint16_t pin_num = (uint16_t) (0x01 << pin);
    uint8_t pin_state = 0;

    if (port > PORT_C) return ERR_PARAM;
    if (pin > 15) return ERR_PARAM;

    switch (port)
    {
        case PORT_A:
            pin_state = GPIO_ReadInputDataBit(GPIOA, pin_num);
            break;
        case PORT_B:
            pin_state = GPIO_ReadInputDataBit(GPIOB, pin_num);
            break;
        case PORT_C:
            pin_state = GPIO_ReadInputDataBit(GPIOC, pin_num);
            break;
    }
    return (int32_t) pin_state;
}

int32_t getGpioPinOutputState(uint8_t port, uint8_t pin)
{
    uint16_t pin_num = (uint16_t) (0x01 << pin);

    if (port > PORT_C) return ERR_PARAM;
    if (pin > 15) return ERR_PARAM;

    switch (port)
    {
        case PORT_A:
            GPIO_ReadOutputDataBit(GPIOA, pin_num);
            break;
        case PORT_B:
            GPIO_ReadOutputDataBit(GPIOB, pin_num);
            break;
        case PORT_C:
            GPIO_ReadOutputDataBit(GPIOC, pin_num);
            break;
    }
    return RET_OK;
}
