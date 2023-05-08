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
SPI_3_Slave.lss \

FLASH_IMAGE += \
SPI_3_Slave.hex \

EEPROM_IMAGE += \
SPI_3_Slave.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: SPI_3_Slave.elf secondary-outputs

# Tool invocations
SPI_3_Slave.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_3_Slave.map -mmcu=atmega32 -o "SPI_3_Slave.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_3_Slave.lss: SPI_3_Slave.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_3_Slave.elf  >"SPI_3_Slave.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_3_Slave.hex: SPI_3_Slave.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_3_Slave.elf  "SPI_3_Slave.hex"
	@echo 'Finished building: $@'
	@echo ' '

SPI_3_Slave.eep: SPI_3_Slave.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SPI_3_Slave.elf  "SPI_3_Slave.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_3_Slave.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SPI_3_Slave.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_3_Slave.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
