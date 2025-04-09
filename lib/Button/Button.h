#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  public:
    Button(int pin);
    bool isPressed();
    bool isLongPressed();
  private:
    int _pin;
};


#endif