################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/USART/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
-include APP/subdir.mk
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
USART_Laptop_Communication.lss \

FLASH_IMAGE += \
USART_Laptop_Communication.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: USART_Laptop_Communication.elf secondary-outputs

# Tool invocations
USART_Laptop_Communication.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,USART_Laptop_Communication.map -mmcu=atmega32 -o "USART_Laptop_Communication.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

USART_Laptop_Communication.lss: USART_Laptop_Communication.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S USART_Laptop_Communication.elf  >"USART_Laptop_Communication.lss"
	@echo 'Finished building: $@'
	@echo ' '

USART_Laptop_Communication.hex: USART_Laptop_Communication.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex USART_Laptop_Communication.elf  "USART_Laptop_Communication.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: USART_Laptop_Communication.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 USART_Laptop_Communication.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) USART_Laptop_Communication.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
