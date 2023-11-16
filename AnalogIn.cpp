// AnalogIn.cpp

#include "AnalogIn.h"
#include <iostream>

AnalogIn::AnalogIn() : number(0) {
    // Default constructor
}

AnalogIn::AnalogIn(unsigned int n) : number(n) {
    // Constructor with a specified analog input number
}

void AnalogIn::setNumber(unsigned int n) {
    // Set the analog input number
    number = n;
}

int AnalogIn::readAdcSample() {
    // Read the ADC sample for the specified analog input
    // Stub implementation
    std::cout << "Inside readAdcSample()" << std::endl;
    return 0;  // Return a dummy value for now
}

AnalogIn::~AnalogIn() {
    // Destructor
}


