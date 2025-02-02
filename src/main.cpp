#include <Arduino.h>
#include "breathing-led-deeper.h"

void setup()
{
    breathing_led_deeper_init();
}

void loop()
{
    breathing_led_deeper_loop();
}