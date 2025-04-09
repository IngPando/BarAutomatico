#include "Button.h"
#include <Config.h>

#define LONG_PRESS_TIME 1000 // 1 second

bool isTimeElapsed(unsigned long startTime, unsigned long duration) {
    return (millis() - startTime) >= duration;
}

Button::Button(int pin) : _pin(pin) {
    pinMode(_pin, INPUT);
}

bool Button::isPressed() {
    return digitalRead(_pin) == HIGH;
}

bool Button::isLongPressed() {
    static unsigned long pressTime = 0;
    if (digitalRead(_pin) == HIGH) {
        if (pressTime == 0) {
            pressTime = millis();
        } else if (isTimeElapsed(pressTime, LONG_PRESS_TIME)) {
            return true;
        }
    } else {
        pressTime = 0;
    }
    return false;
}