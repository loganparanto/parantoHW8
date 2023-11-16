// myGpio.cpp

#include "myGPIO.h"
#include <sstream>
#include <unistd.h>

MYGPIO::MYGPIO(int number) : number(number) {
    // Set the name and path based on the BeagleBone Black GPIO convention
    name = "gpio" + to_string(number);
    path = "/sys/class/gpio/" + name + "/";

    // Export the GPIO pin
    write("/sys/class/gpio/", "export", number);
}

int MYGPIO::getNumber() {
    return number;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir) {
    // Set the direction of the GPIO pin
    write(path, "direction", (dir == OUTPUT) ? "out" : "in");
}

GPIO_DIRECTION MYGPIO::getDirection() {
    // Read and return the direction of the GPIO pin
    string direction = read(path, "direction");
    return (direction == "out") ? OUTPUT : INPUT;
}

int MYGPIO::setValue(GPIO_VALUE val) {
    // Set the value of the GPIO pin
    return write(path, "value", (val == HIGH) ? "1" : "0");
}

GPIO_VALUE MYGPIO::getValue() {
    // Read and return the value of the GPIO pin
    string valueStr = read(path, "value");
    return (valueStr == "1") ? HIGH : LOW;
}

void MYGPIO::toggleOutput() {
    // Toggle the output value of the GPIO pin
    GPIO_VALUE currentVal = getValue();
    setValue((currentVal == HIGH) ? LOW : HIGH);
}

MYGPIO::~MYGPIO() {
    // Unexport the GPIO pin upon destruction
    write("/sys/class/gpio/", "unexport", number);
}

int MYGPIO::write(string path, string filename, string value) {
    // Helper function to write a string value to a file
    ofstream file((path + filename).c_str());
    if (file.is_open()) {
        file << value;
        file.close();
        return 0;
    } else {
        cerr << "Unable to write to file: " << path + filename << endl;
        return -1;
    }
}

int MYGPIO::write(string path, string filename, int value) {
    // Helper function to write an integer value to a file
    stringstream ss;
    ss << value;
    return write(path, filename, ss.str());
}

string MYGPIO::read(string path, string filename) {
    // Helper function to read a string value from a file
    ifstream file((path + filename).c_str());
    string value;
    if (file.is_open()) {
        file >> value;
        file.close();
    } else {
        cerr << "Unable to read from file: " << path + filename << endl;
    }
    return value;
}

