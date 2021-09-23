################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/KeyPad_Driver/keyPad.c 

OBJS += \
./STM32F103C6_Drivers/KeyPad_Driver/keyPad.o 

C_DEPS += \
./STM32F103C6_Drivers/KeyPad_Driver/keyPad.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/KeyPad_Driver/keyPad.o: ../STM32F103C6_Drivers/KeyPad_Driver/keyPad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/embedded diploma/REPO/embedded-systems-diploma/Unit_7_MCU_Essintial_Pripherals/Lesson_4/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/KeyPad_Driver/keyPad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

