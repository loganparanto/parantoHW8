// LED.cpp

#include "LED.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>

LED::LED(int number) : number(number) {
    // Set the name and path based on the BeagleBone Black LED convention
    name = "led" + std::to_string(number);
    path = "/sys/class/leds/" + name + "/";

    // Export the LED
    write(path, "trigger", "none");
}

void LED::turnOn() {
    // Turn on the LED
    write(path, "brightness", "1");
}

void LED::turnOff() {
    // Turn off the LED
    write(path, "brightness", "0");
}

void LED::flash(int duration) {
    // Flash the LED for the specified duration in seconds
    turnOn();
    sleep(duration);
    turnOff();
}

LED::~LED() {
    // Unexport the LED upon destruction
    write("/sys/class/leds/", "unexport", std::to_string(number));
}

int LED::write(const std::string &path, const std::string &filename, const std::string &value) {
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

