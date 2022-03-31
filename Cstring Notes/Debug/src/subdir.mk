################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cstring\ Notes.cpp 

OBJS += \
./src/Cstring\ Notes.o 

CPP_DEPS += \
./src/Cstring\ Notes.d 


# Each subdirectory must supply rules for building sources it contributes
src/Cstring\ Notes.o: ../src/Cstring\ Notes.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Cstring Notes.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


