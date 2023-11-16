// myGpioApp.cpp

#include "LED.h"
#include "GPIO.h"
#include "AnalogIn.h"
#include <iostream>
#include <unistd.h>

int main() {
    // Configure user LEDs and push button GPIO pins
    LED led1(1);
    LED led2(2);
    LED led3(3);
    GPIO pushButton(8, 16);
    AnalogIn temperatureSensor(0);

    // Turn on user LEDs number 1 and 3
    led1.turnOn();
    led3.turnOn();

    // Flash user LED 2
    led2.flash(2);

    // Read and display the temperature sensor value
    int temperatureValue = temperatureSensor.readAdcSample();
    std::cout << "Temperature Sensor Value: " << temperatureValue << std::endl;

    // Read the push button on P8.16
    int pushButtonValue = pushButton.getValue();

    // If the push button was pushed, turn on the LED on P9.12
    if (pushButtonValue == GPIO_VALUE::HIGH) {
        GPIO ledP9_12(9, 12);
        ledP9_12.setValue(GPIO_VALUE::HIGH);
    }

    return 0;
}

