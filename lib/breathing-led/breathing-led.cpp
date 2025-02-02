#include "breathing-led.h"
#include <Arduino.h>

static const int LED_PIN = 2;
static const int DELAY_MS = 10;
static const int STEP_SIZE = 3;

void breathing_led_init(void)
{
    // Set up
    pinMode(LED_PIN, OUTPUT);
}

void breathing_led_loop(void)
{
    for (int value = 0; value <= 255; value += STEP_SIZE)
    {
        analogWrite(LED_PIN, value);
        delay(DELAY_MS);
    }
    for (int value = 255; value >= 0; value -= STEP_SIZE)
    {
        analogWrite(LED_PIN, value);
        delay(DELAY_MS);
    }
}