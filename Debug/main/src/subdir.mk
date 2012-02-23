################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../main/src/AnalogSetter.cpp \
../main/src/DigitalSetter.cpp \
../main/src/Ps3Rx.cpp \
../main/src/RCRx.cpp \
../main/src/RCoIP.cpp \
../main/src/RoMeo.cpp \
../main/src/Setter.cpp 

OBJS += \
./main/src/AnalogSetter.o \
./main/src/DigitalSetter.o \
./main/src/Ps3Rx.o \
./main/src/RCRx.o \
./main/src/RCoIP.o \
./main/src/RoMeo.o \
./main/src/Setter.o 

CPP_DEPS += \
./main/src/AnalogSetter.d \
./main/src/DigitalSetter.d \
./main/src/Ps3Rx.d \
./main/src/RCRx.d \
./main/src/RCoIP.d \
./main/src/RoMeo.d \
./main/src/Setter.d 


# Each subdirectory must supply rules for building sources it contributes
main/src/%.o: ../main/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/Users/frehnerp/Documents/eclipse/ws/Arduino/ArduinoCore/source/inc" -I"/Users/frehnerp/Documents/eclipse/ws/Arduino/ArduinoCore/source/src" -I"/Users/frehnerp/Documents/eclipse/ws/Arduino/RoMeoRCoIP/arduinolib/inc" -I"/Users/frehnerp/Documents/eclipse/ws/Arduino/RoMeoRCoIP/arduinolib/src" -I"/Users/frehnerp/Documents/eclipse/ws/Arduino/RoMeoRCoIP/redfly/inc" -I"/Users/frehnerp/Documents/eclipse/ws/Arduino/RoMeoRCoIP/redfly/src" -I"/Users/frehnerp/Documents/eclipse/ws/Arduino/RoMeoRCoIP/main/inc" -I"/Users/frehnerp/Documents/eclipse/ws/Arduino/RoMeoRCoIP/main/src" -D__AVR_ATmega328P__ -DARDUINO=100 -U__AVR_ATmega2560__ -Wall -g2 -gstabs -Os -ffunction-sections -fdata-sections -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


