################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Lib/STLibs/Servo/Servo.c 

OBJS += \
./Core/Lib/STLibs/Servo/Servo.o 

C_DEPS += \
./Core/Lib/STLibs/Servo/Servo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Lib/STLibs/Servo/%.o: ../Core/Lib/STLibs/Servo/%.c Core/Lib/STLibs/Servo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I"C:/Users/slimf/STM32CubeIDE/workspace_1.7.0/ServoTest/Core/Lib/STLibs" -I"C:/Users/slimf/STM32CubeIDE/workspace_1.7.0/ServoTest/Core/Lib" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

