// GPIO.cpp

#include "GPIO.h"
#include <iostream>
#include <fstream>
#include <sstream>

GPIO::GPIO(int pin1, int pin2) : pin1(pin1), pin2(pin2) {
    // Set the name and path based on the BeagleBone Black GPIO convention
    name = "gpio" + std::to_string(pin1) + "_" + std::to_string(pin2);
    path = "/sys/class/gpio/" + name + "/";

    // Export the GPIO pins
    write("/sys/class/gpio/", "export", std::to_string(pin1));
    write("/sys/class/gpio/", "export", std::to_string(pin2));

    // Set the direction
    setDirection(INPUT);
}

void GPIO::setDirection(GPIO_DIRECTION dir) {
    // Set the direction of the GPIO pins
    write(path, "direction", (dir == OUTPUT) ? "out" : "in");
}

GPIO_DIRECTION GPIO::getDirection() {
    // Read and return the direction of the GPIO pins
    std::string direction = read(path, "direction");
    return (direction == "out") ? OUTPUT : INPUT;
}

int GPIO::setValue(GPIO_VALUE val) {
    // Set the value of the GPIO pins
    return write(path, "value", (val == HIGH) ? "1" : "0");
}

GPIO_VALUE GPIO::getValue() {
    // Read and return the value of the GPIO pins
    std::string valueStr = read(path, "value");
    return (valueStr == "1") ? HIGH : LOW;
}

GPIO::~GPIO() {
    // Unexport the GPIO pins upon destruction
    write("/sys/class/gpio/", "unexport", std::to_string(pin1));
    write("/sys/class/gpio/", "unexport", std::to_string(pin2));
}

int GPIO::write(const std::string &path, const std::string &filename, const std::string &value) {
    // Helper function to write a string value to a file
    std::ofstream file((path + filename).c_str());
    if (file.is_open()) {
        file << value;
        file.close();
        return 0;
    } else {
        std::cerr << "Unable to write to file: " << path + filename << std::endl;
        return -1;
    }
}

std::string GPIO::read(const std::string &path, const std::string &filename) {
    // Helper function to read a string value from a file
    std::ifstream file((path + filename).c_str());
    std::string value;
    if (file.is_open()) {
        file >> value;
        file.close();
    } else {
        std::cerr << "Unable to read from file: " << path + filename << std::endl;
    }
    return value;
}

