################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/util/circular_buffer.c \
../src/util/list.c \
../src/util/util.c 

SRC_OBJS += \
./src/util/circular_buffer.o \
./src/util/list.o \
./src/util/util.o 

C_DEPS += \
./src/util/circular_buffer.d \
./src/util/list.d \
./src/util/util.d 


# Each subdirectory must supply rules for building sources it contributes
src/util/%.o: ../src/util/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -ffunction-sections -fdata-sections -DCORE0 -D_DEBUG -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0x100 @includes-a373deeda79d3d8536aa48e627b2c2fa.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


