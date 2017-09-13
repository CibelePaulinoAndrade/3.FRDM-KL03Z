################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/utilities/src/fsl_debug_console.c \
../SDK/platform/utilities/src/fsl_misc_utilities.c \
../SDK/platform/utilities/src/print_scan.c 

OBJS += \
./SDK/platform/utilities/src/fsl_debug_console.o \
./SDK/platform/utilities/src/fsl_misc_utilities.o \
./SDK/platform/utilities/src/print_scan.o 

C_DEPS += \
./SDK/platform/utilities/src/fsl_debug_console.d \
./SDK/platform/utilities/src/fsl_misc_utilities.d \
./SDK/platform/utilities/src/print_scan.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/utilities/src/%.o: ../SDK/platform/utilities/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"FSL_OSA_BM_TIMER_CONFIG=2" -D"CPU_MKL03Z32VFK4" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/hal/inc" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/hal/src/sim/MKL03Z4" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/system/src/clock/MKL03Z4" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/system/inc" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/osa/inc" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/CMSIS/Include" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/devices" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/devices/MKL03Z4/include" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/utilities/src" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/utilities/inc" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/devices/MKL03Z4/startup" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/Generated_Code/SDK/platform/devices/MKL03Z4/startup" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/Sources" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/Generated_Code" -I"C:/Users/Cibele/workspace.kds/Blinky3_KL03Z/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


