// GPIO.h

#ifndef GPIO_H
#define GPIO_H

#include <string>

enum GPIO_DIRECTION {
    INPUT,
    OUTPUT
};

enum GPIO_VALUE {
    LOW,
    HIGH
};

class GPIO {
private:
    int pin1, pin2;
    std::string name, path;

public:
    GPIO(int pin1, int pin2);
    void setDirection(GPIO_DIRECTION dir);
    GPIO_DIRECTION getDirection();
    int setValue(GPIO_VALUE val);
    GPIO_VALUE getValue();
    ~GPIO(); // Destructor

private:
    int write(const std::string &path, const std::string &filename, const std::string &value);
    std::string read(const std::string &path, const std::string &filename);
};

#endif // GPIO_H

