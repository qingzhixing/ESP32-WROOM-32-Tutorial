#include "breathing-led-deeper.h"
#include <Arduino.h>

static const int LED_PIN = 2;
static const int DELAY_MS = 10;
static const int STEP_SIZE = 3;

static const int PWM_FREQ = 1000;                    // Hz
static const int PWM_RESOLUTION = 8;                 // bits
static const int PWM_RANGE = pow(2, PWM_RESOLUTION); // [0, 2^PWM_RESOLUTION-1]
static const int PWM_CHANNEL = 0;                    // channel 0

void breathing_led_deeper_init(void)
{
    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void breathing_led_deeper_loop(void)
{
    // forward
    for (int i = 0; i < PWM_RANGE; i += STEP_SIZE)
    {
        ledcWrite(PWM_CHANNEL, i);
        delay(DELAY_MS);
    }
    // backward
    for (int i = PWM_RANGE - 1; i >= 0; i -= STEP_SIZE)
    {
        ledcWrite(PWM_CHANNEL, i);
        delay(DELAY_MS);
    }
}