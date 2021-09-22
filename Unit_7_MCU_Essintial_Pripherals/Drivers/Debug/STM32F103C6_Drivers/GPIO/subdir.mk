################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/GPIO/stm32f103c6_gpio_driver.c 

OBJS += \
./STM32F103C6_Drivers/GPIO/stm32f103c6_gpio_driver.o 

C_DEPS += \
./STM32F103C6_Drivers/GPIO/stm32f103c6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/GPIO/stm32f103c6_gpio_driver.o: ../STM32F103C6_Drivers/GPIO/stm32f103c6_gpio_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/embedded diploma/REPO/embedded-systems-diploma/Unit_7_MCU_Essintial_Pripherals/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/GPIO/stm32f103c6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

