################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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
LSS += \
EXT_INT.lss \

FLASH_IMAGE += \
EXT_INT.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: EXT_INT.elf secondary-outputs

# Tool invocations
EXT_INT.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,EXT_INT.map -mmcu=atmega32 -o "EXT_INT.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

EXT_INT.lss: EXT_INT.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S EXT_INT.elf  >"EXT_INT.lss"
	@echo 'Finished building: $@'
	@echo ' '

EXT_INT.hex: EXT_INT.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex EXT_INT.elf  "EXT_INT.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: EXT_INT.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 EXT_INT.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: EXT_INT.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -u -Uflash:w:EXT_INT.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) EXT_INT.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
