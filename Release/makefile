################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := ${ComSpec}

-include ../makefile.init

RM := clean

# All of the sources participating in the build are defined here
-include sources.mk
-include system/pinmux/GeneratedSources/subdir.mk
-include system/subdir.mk
-include src/util/subdir.mk
-include src/drivers/platform/aducm3029/subdir.mk
-include src/drivers/gyro/adxrs290/subdir.mk
-include src/subdir.mk
-include RTE/Device/ADuCM3029/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
OBJS := $(SRC_OBJS)
# Quote makefile variable : OBJS 
OBJS := $(subst \ ,@, $(OBJS))
OBJS := $(foreach var, $(OBJS), "$(subst @, ,$(var))")
# Quote makefile variable : C_DEPS 
C_DEPS := $(subst \ ,@, $(C_DEPS))
C_DEPS := $(foreach var, $(C_DEPS), "$(subst @, ,$(var))")

# All Target
all: adxrs290_prod_test

# Tool invocations

PREPROC:
	@echo 'Preprocessing LD script: adxrs290_prod_test.ld'
	arm-none-eabi-cpp -E -P -DCORE0 -DRELEASE -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0x100 -I"C:/CCES2.9.2/ARM/packs/ARM/CMSIS/5.7.0/CMSIS/Core/Include" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/dma" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/gpio" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/pwr" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/rtc" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/spi" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/tmr" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/uart" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/xint" -I"C:\Users\ZArceo\Downloads\adxrs290-pmdz-prod-test\adxrs290-pmdz-prod-test/RTE" -I"C:\Users\ZArceo\Downloads\adxrs290-pmdz-prod-test\adxrs290-pmdz-prod-test/RTE/Device/ADuCM3029" -o  "adxrs290_prod_test.ld" "C:\Users\ZArceo\Downloads\adxrs290-pmdz-prod-test\adxrs290-pmdz-prod-test/RTE/Device/ADuCM3029/ADuCM3029.ld"

adxrs290_prod_test: $(USER_OBJS) $(SRC_OBJS) PREPROC
	@echo 'Building target: $@'
	@echo 'Invoking: CrossCore GCC ARM Embedded C Linker'
	arm-none-eabi-gcc -Tadxrs290_prod_test.ld -DCORE0 -DRELEASE -D_RTE_ -D__ADUCM3029__ -D__SILICON_REVISION__=0x100 -I"C:/CCES2.9.2/ARM/packs/ARM/CMSIS/5.7.0/CMSIS/Core/Include" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/dma" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/gpio" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/pwr" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/rtc" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/spi" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/tmr" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/uart" -I"C:/CCES2.9.2/ARM/packs/AnalogDevices/ADuCM302x_DFP/3.2.0/Include/drivers/xint" -I"C:\Users\ZArceo\Downloads\adxrs290-pmdz-prod-test\adxrs290-pmdz-prod-test/RTE" -I"C:\Users\ZArceo\Downloads\adxrs290-pmdz-prod-test\adxrs290-pmdz-prod-test/RTE/Device/ADuCM3029" -Wl,--gc-sections -mcpu=cortex-m3 -mthumb -specs=nosys.specs -o  "adxrs290_prod_test" @input-file.txt -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) adxrs290_prod_test
	-@echo ' '

post-build:
	-arm-none-eabi-objcopy -O ihex adxrs290_prod_test adxrs290_prod_test.hex
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
