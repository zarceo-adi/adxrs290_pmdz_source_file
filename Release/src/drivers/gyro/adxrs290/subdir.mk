################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/drivers/gyro/adxrs290/adxrs290.c 

SRC_OBJS += \
./src/drivers/gyro/adxrs290/adxrs290.o 

C_DEPS += \
./src/drivers/gyro/adxrs290/adxrs290.d 


# Each subdirectory must supply rules for building sources it contributes
src/drivers/gyro/adxrs290/%.o: ../src/drivers/gyro/adxrs290/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Compiler'
	arm-none-eabi-gcc -ffunction-sections -fdata-sections -DCORE0 -DNDEBUG -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0x100 @includes-a373deeda79d3d8536aa48e627b2c2fa.txt -Wall -c -mcpu=cortex-m3 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


