#include <Arduino.h>
#include "oled_keyboard_test.h"

bool buttonPressed = false, buttonReleased = false;

void IRAM_ATTR buttonPressedHandler()
{
    buttonPressed = true;
}

void IRAM_ATTR buttonReleasedHandler()
{
    buttonReleased = true;
}

void setup()
{
    oled_keyboard_test_init();
    attachInterrupt(digitalPinToInterrupt(KEY_UP), buttonPressedHandler, RISING);
    attachInterrupt(digitalPinToInterrupt(KEY_UP), buttonReleasedHandler, FALLING);
}

void loop()
{
    Serial.println(digitalRead(KEY_UP) == HIGH ? "HIGH" : "LOW");
    do_oled_keyboard_loop();
    if (buttonPressed)
    {
        Serial.println("Button Up pressed");
        buttonPressed = false;
    }
    if (buttonReleased)
    {
        Serial.println("Button Up released");
        buttonReleased = false;
    }
}