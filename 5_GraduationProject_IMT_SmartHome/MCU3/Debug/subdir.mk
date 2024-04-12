################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_progarm.c \
../DIO_Program.c \
../EXTI_program.c \
../LCD_program.c \
../SPI_program.c \
../main.c 

OBJS += \
./ADC_progarm.o \
./DIO_Program.o \
./EXTI_program.o \
./LCD_program.o \
./SPI_program.o \
./main.o 

C_DEPS += \
./ADC_progarm.d \
./DIO_Program.d \
./EXTI_program.d \
./LCD_program.d \
./SPI_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


