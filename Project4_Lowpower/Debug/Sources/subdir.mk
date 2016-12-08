################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/I2C.c \
../Sources/SPI.c \
../Sources/accelerometer.c \
../Sources/adc.c \
../Sources/calibrate.c \
../Sources/circbuf.c \
../Sources/dac.c \
../Sources/data.c \
../Sources/dma.c \
../Sources/led.c \
../Sources/log.c \
../Sources/main.c \
../Sources/memory.c \
../Sources/message.c \
../Sources/motor.c \
../Sources/profile.c \
../Sources/rtc.c \
../Sources/sdcard.c \
../Sources/tsi.c \
../Sources/uart.c 

OBJS += \
./Sources/I2C.o \
./Sources/SPI.o \
./Sources/accelerometer.o \
./Sources/adc.o \
./Sources/calibrate.o \
./Sources/circbuf.o \
./Sources/dac.o \
./Sources/data.o \
./Sources/dma.o \
./Sources/led.o \
./Sources/log.o \
./Sources/main.o \
./Sources/memory.o \
./Sources/message.o \
./Sources/motor.o \
./Sources/profile.o \
./Sources/rtc.o \
./Sources/sdcard.o \
./Sources/tsi.o \
./Sources/uart.o 

C_DEPS += \
./Sources/I2C.d \
./Sources/SPI.d \
./Sources/accelerometer.d \
./Sources/adc.d \
./Sources/calibrate.d \
./Sources/circbuf.d \
./Sources/dac.d \
./Sources/data.d \
./Sources/dma.d \
./Sources/led.d \
./Sources/log.d \
./Sources/main.d \
./Sources/memory.d \
./Sources/message.d \
./Sources/motor.d \
./Sources/profile.d \
./Sources/rtc.d \
./Sources/sdcard.d \
./Sources/tsi.d \
./Sources/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


