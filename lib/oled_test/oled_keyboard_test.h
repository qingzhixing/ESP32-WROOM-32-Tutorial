#pragma once

#include <Arduino.h>

#define KEY_UP (27U)
#define KEY_DOWN (14U)
#define KEY_LEFT (12U)
#define KEY_RIGHT (13U)

void oled_keyboard_test_init();
void do_oled_keyboard_loop();