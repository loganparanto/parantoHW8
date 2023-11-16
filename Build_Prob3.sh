#!/bin/bash

# Build script for myGpioApp

# Add compilation commands here
g++ -o myGpioApp myGpioApp.cpp LED.cpp GPIO.cpp AnalogIn.cpp -std=c++11

# Example invocation
# ./myGpioApp

