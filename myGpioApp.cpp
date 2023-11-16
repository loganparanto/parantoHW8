// myGpioApp.cpp

#include "myGPIO.h"
#include <unistd.h>

int main() {
    // Instantiate an object as an output gpio using pin p9.12.
    MYGPIO gpioOutput(9);
    gpioOutput.setDirection(OUTPUT);

    // Instantiate an object as an input gpio using pin p8.16.
    MYGPIO gpioInput(8);
    gpioInput.setDirection(INPUT);

    // Set p9.12 high for 3 seconds, and then set it low. Print out its value in both cases.
    gpioOutput.setValue(HIGH);
    cout << "p9.12 value: " << gpioOutput.getValue() << endl;
    sleep(3);  // Sleep for 3 seconds
    gpioOutput.setValue(LOW);
    cout << "p9.12 value: " << gpioOutput.getValue() << endl;

    // Read p8.16 and print out its value.
    cout << "p8.16 value: " << gpioInput.getValue() << endl;

    return 0;
}

