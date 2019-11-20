cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 98)
set(PROJECT_NAME arduino_microphone)


set(${PROJECT_NAME}_BOARD uno)
project(${PROJECT_NAME})

set(${PROJECT_NAME}_SRCS arduino_microphone.cpp AnalogWindowReader.h AnalogWindowReader.cpp SerialCommunication.h SerialCommunication.cpp)

set(${PROJECT_NAME}_PROGRAMMER avrispmkii)
set(${PROJECT_NAME}_PORT /dev/cu.usbmodem141101)
generate_arduino_firmware(${PROJECT_NAME})
