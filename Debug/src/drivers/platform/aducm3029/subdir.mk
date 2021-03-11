################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/drivers/platform/aducm3029/delay.c \
../src/drivers/platform/aducm3029/gpio.c \
../src/drivers/platform/aducm3029/irq.c \
../src/drivers/platform/aducm3029/platform_init.c \
../src/drivers/platform/aducm3029/rtc.c \
../src/drivers/platform/aducm3029/spi.c \
../src/drivers/platform/aducm3029/timer.c \
../src/drivers/platform/aducm3029/uart.c 

SRC_OBJS += \
./src/drivers/platform/aducm3029/delay.o \
./src/drivers/platform/aducm3029/gpio.o \
./src/drivers/platform/aducm3029/irq.o \
./src/drivers/platform/aducm3029/platform_init.o \
./src/drivers/platform/aducm3029/rtc.o \
./src/drivers/platform/aducm3029/spi.o \
./src/drivers/platform/aducm3029/timer.o \
./src/drivers/platform/aducm3029/uart.o 

C_DEPS += \
./src/drivers/platform/aducm3029/delay.d \
./src/drivers/platform/aducm3029/gpio.d \
./src/drivers/platform/aducm3029/irq.d \
./src/drivers/platform/aducm3029/platform_init.d \
./src/drivers/platform/aducm3029/rtc.d \
./src/drivers/platform/aducm3029/spi.d \
./src/drivers/platform/aducm3029/timer.d \
./src/drivers/platform/aducm3029/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/drivers/platform/aducm3029/%.o: ../src/drivers/platform/aducm3029/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0x100 @includes-a373deeda79d3d8536aa48e627b2c2fa.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


