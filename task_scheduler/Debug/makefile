################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
task_scheduler.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
task_scheduler.list \

OBJCOPY_BIN += \
task_scheduler.bin \


# All Target
all: task_scheduler.elf secondary-outputs

# Tool invocations
task_scheduler.elf: $(OBJS) $(USER_OBJS) D:\Embedded_System\ARM_cortexMx_projects\cortexMx\task_scheduler\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "task_scheduler.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\Embedded_System\ARM_cortexMx_projects\cortexMx\task_scheduler\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="task_scheduler.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

task_scheduler.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "task_scheduler.list"
	@echo 'Finished building: $@'
	@echo ' '

task_scheduler.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "task_scheduler.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
