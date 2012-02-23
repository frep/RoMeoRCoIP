################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include redfly/src/subdir.mk
-include main/src/subdir.mk
-include arduinolib/src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
FLASH_IMAGE += \
RoMeoRCoIP.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: RoMeoRCoIP.elf secondary-outputs

# Tool invocations
RoMeoRCoIP.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ --cref -s -Os -o"RoMeoRCoIP.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lm -Wl,-Map,RoMeoRCoIP.map,--cref -Wl,--gc-sections -L"/Users/frehnerp/Documents/eclipse/ws/Arduino/ArduinoCore/328P_16MHz" -mmcu=atmega328p
	@echo 'Finished building target: $@'
	@echo ' '

RoMeoRCoIP.hex: RoMeoRCoIP.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex RoMeoRCoIP.elf  "RoMeoRCoIP.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: RoMeoRCoIP.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega328p RoMeoRCoIP.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(FLASH_IMAGE)$(ELFS)$(S_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C++_DEPS)$(ASM_DEPS)$(CC_DEPS)$(INO_DEPS)$(CPP_DEPS)$(PDE_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) RoMeoRCoIP.elf
	-@echo ' '

secondary-outputs: $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
