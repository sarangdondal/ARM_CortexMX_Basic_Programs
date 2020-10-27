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
Interrupt_Priority.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Interrupt_Priority.list \

OBJCOPY_BIN += \
Interrupt_Priority.bin \


# All Target
all: Interrupt_Priority.elf secondary-outputs

# Tool invocations
Interrupt_Priority.elf: $(OBJS) $(USER_OBJS) D:\Embedded_System\ARM_cortexMx_projects\cortexMx\Interrupt_Priority\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "Interrupt_Priority.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\Embedded_System\ARM_cortexMx_projects\cortexMx\Interrupt_Priority\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Interrupt_Priority.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Interrupt_Priority.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Interrupt_Priority.list"
	@echo 'Finished building: $@'
	@echo ' '

Interrupt_Priority.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Interrupt_Priority.bin"
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
