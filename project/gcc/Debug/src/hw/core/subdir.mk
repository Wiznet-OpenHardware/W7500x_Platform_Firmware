################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/adcHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/crgHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/dmaHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/ex_uartHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/extiHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/flashHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/gpioHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/pwmHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/rngHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/softi2cHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/sspHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/timerHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/uartHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/wdtHandler.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/wztoeHandler.c 

OBJS += \
./src/hw/core/adcHandler.o \
./src/hw/core/crgHandler.o \
./src/hw/core/dmaHandler.o \
./src/hw/core/ex_uartHandler.o \
./src/hw/core/extiHandler.o \
./src/hw/core/flashHandler.o \
./src/hw/core/gpioHandler.o \
./src/hw/core/pwmHandler.o \
./src/hw/core/rngHandler.o \
./src/hw/core/softi2cHandler.o \
./src/hw/core/sspHandler.o \
./src/hw/core/timerHandler.o \
./src/hw/core/uartHandler.o \
./src/hw/core/wdtHandler.o \
./src/hw/core/wztoeHandler.o 

C_DEPS += \
./src/hw/core/adcHandler.d \
./src/hw/core/crgHandler.d \
./src/hw/core/dmaHandler.d \
./src/hw/core/ex_uartHandler.d \
./src/hw/core/extiHandler.d \
./src/hw/core/flashHandler.d \
./src/hw/core/gpioHandler.d \
./src/hw/core/pwmHandler.d \
./src/hw/core/rngHandler.d \
./src/hw/core/softi2cHandler.d \
./src/hw/core/sspHandler.d \
./src/hw/core/timerHandler.d \
./src/hw/core/uartHandler.d \
./src/hw/core/wdtHandler.d \
./src/hw/core/wztoeHandler.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/core/adcHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/adcHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/crgHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/crgHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/dmaHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/dmaHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/ex_uartHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/ex_uartHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/extiHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/extiHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/flashHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/flashHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/gpioHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/gpioHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/pwmHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/pwmHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/rngHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/rngHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/softi2cHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/softi2cHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/sspHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/sspHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/timerHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/timerHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/uartHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/uartHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/wdtHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/wdtHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/core/wztoeHandler.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/core/wztoeHandler.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


