################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../KEYPAD_program.c \
../LCD_program.c \
../Master1.c \
../SPI_program.c \
../UART_program.c \
../main.c 

OBJS += \
./DIO_Program.o \
./KEYPAD_program.o \
./LCD_program.o \
./Master1.o \
./SPI_program.o \
./UART_program.o \
./main.o 

C_DEPS += \
./DIO_Program.d \
./KEYPAD_program.d \
./LCD_program.d \
./Master1.d \
./SPI_program.d \
./UART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


