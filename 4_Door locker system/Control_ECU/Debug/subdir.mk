################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../EXTI_program.c \
../TIMER0_program.c \
../UART_program.c \
../app.c \
../main.c 

OBJS += \
./DIO_Program.o \
./EXTI_program.o \
./TIMER0_program.o \
./UART_program.o \
./app.o \
./main.o 

C_DEPS += \
./DIO_Program.d \
./EXTI_program.d \
./TIMER0_program.d \
./UART_program.d \
./app.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


