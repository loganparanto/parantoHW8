// LED.h

#ifndef LED_H
#define LED_H

#include <string>

class LED {
private:
    int number;
    std::string name, path;

public:
    LED(int number);
    void turnOn();
    void turnOff();
    void flash(int duration);
    ~LED(); // Destructor

private:
    int write(const std::string &path, const std::string &filename, const std::string &value);
};

#endif // LED_H

