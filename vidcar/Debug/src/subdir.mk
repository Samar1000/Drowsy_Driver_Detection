################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DIO_program.c \
../src/EXTI_program.c \
../src/GI_program.c \
../src/LED_program.c \
../src/MOTOR_program.c \
../src/TIMER0_program.c \
../src/TIMER2_program.c \
../src/Timer1_program.c \
../src/UART_Program.c \
../src/app.c \
../src/sensor.c 

OBJS += \
./src/DIO_program.o \
./src/EXTI_program.o \
./src/GI_program.o \
./src/LED_program.o \
./src/MOTOR_program.o \
./src/TIMER0_program.o \
./src/TIMER2_program.o \
./src/Timer1_program.o \
./src/UART_Program.o \
./src/app.o \
./src/sensor.o 

C_DEPS += \
./src/DIO_program.d \
./src/EXTI_program.d \
./src/GI_program.d \
./src/LED_program.d \
./src/MOTOR_program.d \
./src/TIMER0_program.d \
./src/TIMER2_program.d \
./src/Timer1_program.d \
./src/UART_Program.d \
./src/app.d \
./src/sensor.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\AvrProjects\vidcar\include" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


