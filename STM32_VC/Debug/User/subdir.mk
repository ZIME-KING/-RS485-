################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/software_Time.c \
../User/u8g2_buffer.c \
../User/u8g2_init.c \
../User/user_function.c \
../User/user_init.c 

OBJS += \
./User/software_Time.o \
./User/u8g2_buffer.o \
./User/u8g2_init.o \
./User/user_function.o \
./User/user_init.o 

C_DEPS += \
./User/software_Time.d \
./User/u8g2_buffer.d \
./User/u8g2_init.d \
./User/user_function.d \
./User/user_init.d 


# Each subdirectory must supply rules for building sources it contributes
User/software_Time.o: ../User/software_Time.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/king_pc1/Desktop/STM32_VC/User/KEY" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/LED" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/SYS" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/UART" -I"C:/Users/king_pc1/Desktop/STM32_VC/User" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/u8g2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/software_Time.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/u8g2_buffer.o: ../User/u8g2_buffer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/king_pc1/Desktop/STM32_VC/User/KEY" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/LED" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/SYS" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/UART" -I"C:/Users/king_pc1/Desktop/STM32_VC/User" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/u8g2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/u8g2_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/u8g2_init.o: ../User/u8g2_init.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/king_pc1/Desktop/STM32_VC/User/KEY" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/LED" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/SYS" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/UART" -I"C:/Users/king_pc1/Desktop/STM32_VC/User" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/u8g2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/u8g2_init.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/user_function.o: ../User/user_function.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/king_pc1/Desktop/STM32_VC/User/KEY" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/LED" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/SYS" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/UART" -I"C:/Users/king_pc1/Desktop/STM32_VC/User" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/u8g2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/user_function.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/user_init.o: ../User/user_init.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/king_pc1/Desktop/STM32_VC/User/KEY" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/LED" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/SYS" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/UART" -I"C:/Users/king_pc1/Desktop/STM32_VC/User" -I"C:/Users/king_pc1/Desktop/STM32_VC/User/u8g2" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"User/user_init.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

