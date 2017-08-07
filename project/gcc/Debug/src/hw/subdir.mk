################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/W7500x_it.c \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/hw.c 

OBJS += \
./src/hw/W7500x_it.o \
./src/hw/hw.o 

C_DEPS += \
./src/hw/W7500x_it.d \
./src/hw/hw.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/W7500x_it.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/W7500x_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hw/hw.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/src/hw/hw.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Include" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Application\loopback" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Ethernet" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DHCP" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\DNS" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\Internet\httpServer" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\ioLibrary\MDIO" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\W7500x_stdPeriph_Driver\inc" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\common" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\app" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\hw" -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\src\testSuite" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


