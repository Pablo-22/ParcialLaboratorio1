################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/1Parcial_Cordoba.c \
../source/Menu.c \
../source/Servicios.c \
../source/Trabajo.c \
../source/getFunctions.c \
../source/terminalFunctions.c 

OBJS += \
./source/1Parcial_Cordoba.o \
./source/Menu.o \
./source/Servicios.o \
./source/Trabajo.o \
./source/getFunctions.o \
./source/terminalFunctions.o 

C_DEPS += \
./source/1Parcial_Cordoba.d \
./source/Menu.d \
./source/Servicios.d \
./source/Trabajo.d \
./source/getFunctions.d \
./source/terminalFunctions.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


