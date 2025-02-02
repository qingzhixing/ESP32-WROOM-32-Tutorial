#include <Arduino.h>
#include "breathing-led.h"

void setup()
{
    breathing_led_init();
}

void loop()
{
    breathing_led_loop();
}