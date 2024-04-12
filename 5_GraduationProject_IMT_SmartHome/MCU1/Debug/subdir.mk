################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_progarm.c \
../DIO_Program.c \
../Door.c \
../KEYPAD_program.c \
../LCD_program.c \
../Servo_program.c \
../Timer1_program.c \
../UART_program.c \
../main.c 

OBJS += \
./ADC_progarm.o \
./DIO_Program.o \
./Door.o \
./KEYPAD_program.o \
./LCD_program.o \
./Servo_program.o \
./Timer1_program.o \
./UART_program.o \
./main.o 

C_DEPS += \
./ADC_progarm.d \
./DIO_Program.d \
./Door.d \
./KEYPAD_program.d \
./LCD_program.d \
./Servo_program.d \
./Timer1_program.d \
./UART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


