################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ARM.c 

OBJS += \
./src/ARM.o 

C_DEPS += \
./src/ARM.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler 4 [arm-linux-gnueabihf]'
	arm-linux-gnueabihf-gcc -Dsoc_cv_av -I"C:\Users\prodrigu\git\arqui2\MedianFilter-DE1-SoC\nios2_bsp" -I"C:\intelFPGA\18.1\embedded\ip\altera\hps\altera_hps\hwlib\include" -I"C:\intelFPGA\18.1\embedded\ip\altera\hps\altera_hps\hwlib\include\soc_cv_av" -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


