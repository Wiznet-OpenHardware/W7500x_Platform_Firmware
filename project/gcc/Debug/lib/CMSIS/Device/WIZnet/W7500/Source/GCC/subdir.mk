################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_W7500.S 

OBJS += \
./lib/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_W7500.o 

S_UPPER_DEPS += \
./lib/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_W7500.d 


# Each subdirectory must supply rules for building sources it contributes
lib/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_W7500.o: D:/Workspace/Source/WIZnet/W7500x_Platform_FW/lib/CMSIS/Device/WIZnet/W7500/Source/GCC/startup_W7500.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -x assembler-with-cpp -DUSE_STDPERIPH_DRIVER -I"D:\Workspace\Source\WIZnet\W7500x_Platform_FW\lib\CMSIS\Device\WIZnet\W7500\Source\GCC" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


