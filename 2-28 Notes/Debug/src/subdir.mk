################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/2-28\ Notes.cpp 

OBJS += \
./src/2-28\ Notes.o 

CPP_DEPS += \
./src/2-28\ Notes.d 


# Each subdirectory must supply rules for building sources it contributes
src/2-28\ Notes.o: ../src/2-28\ Notes.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/2-28 Notes.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


