// test_analog.cpp

#include "AnalogIn.h"
#include <iostream>

int main() {
    // Declare an object of type AnalogIn
    AnalogIn AIN(0);

    // Call the function readAdcSample() and print out its value
    int adcSample = AIN.readAdcSample();
    std::cout << "ADC Sample Value: " << adcSample << std::endl;

    return 0;
}

