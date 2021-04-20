################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/UART/uart.c 

OBJS += \
./User/UART/uart.o 

C_DEPS += \
./User/UART/uart.d 


# Each subdirectory must supply rules for building sources it contributes
User/UART/uart.o: ../User/UART/uart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/king_pc1/Desktop/STM32_VC/User/KEY" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/LED" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/SYS" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/UART" -I"C:/Users/king_pc1/Desktop/STM32_VC/User" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/u8g2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/UART/uart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

