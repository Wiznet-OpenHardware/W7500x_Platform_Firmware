################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_adc.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_crg.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_dma.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_dualtimer.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_exti.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_gpio.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_pwm.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_rng.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_ssp.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_uart.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_wdt.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_wztoe.c 

OBJS += \
./lib/W7500x_stdPeriph_Driver/src/W7500x_adc.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_crg.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_dma.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_dualtimer.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_exti.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_gpio.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_pwm.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_rng.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_ssp.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_uart.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_wdt.o \
./lib/W7500x_stdPeriph_Driver/src/W7500x_wztoe.o 

C_DEPS += \
./lib/W7500x_stdPeriph_Driver/src/W7500x_adc.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_crg.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_dma.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_dualtimer.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_exti.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_gpio.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_pwm.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_rng.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_ssp.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_uart.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_wdt.d \
./lib/W7500x_stdPeriph_Driver/src/W7500x_wztoe.d 


# Each subdirectory must supply rules for building sources it contributes
lib/W7500x_stdPeriph_Driver/src/W7500x_adc.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_crg.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_crg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_dma.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_dualtimer.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_dualtimer.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_exti.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_exti.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_gpio.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_pwm.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_pwm.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_rng.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_rng.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_ssp.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_ssp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_uart.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_wdt.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_wdt.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/W7500x_stdPeriph_Driver/src/W7500x_wztoe.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/W7500x_stdPeriph_Driver/src/W7500x_wztoe.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


