################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/circbuf.c \
../Sources/data.c \
../Sources/led.c \
../Sources/log.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/prof_test.c \
../Sources/profile.c \
../Sources/uart.c \
../Sources/unittest.c 

OBJS += \
./Sources/circbuf.o \
./Sources/data.o \
./Sources/led.o \
./Sources/log.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/prof_test.o \
./Sources/profile.o \
./Sources/uart.o \
./Sources/unittest.o 

C_DEPS += \
./Sources/circbuf.d \
./Sources/data.d \
./Sources/led.d \
./Sources/log.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/prof_test.d \
./Sources/profile.d \
./Sources/uart.d \
./Sources/unittest.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


