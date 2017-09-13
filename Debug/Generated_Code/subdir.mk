################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/clockMan1.c \
../Generated_Code/gpio1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_init.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/clockMan1.o \
./Generated_Code/gpio1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_init.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/clockMan1.d \
./Generated_Code/gpio1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_init.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL03Z32VFK4" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/hal/inc" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/hal/src/sim/MKL03Z4" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/system/src/clock/MKL03Z4" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/system/inc" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/osa/inc" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/CMSIS/Include" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/devices" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/devices/MKL03Z4/include" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/utilities/src" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/utilities/inc" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/devices/MKL03Z4/startup" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/Generated_Code/SDK/platform/devices/MKL03Z4/startup" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/Sources" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/Generated_Code" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


