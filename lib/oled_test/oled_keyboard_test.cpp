#include "oled_keyboard_test.h"
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/SCL, /* data=*/SDA);
void oled_keyboard_test_init()
{
    u8g2.begin();
    Serial.begin(115200);
    u8g2.clearBuffer();

    pinMode(KEY_UP, INPUT_PULLDOWN);
    pinMode(KEY_DOWN, INPUT_PULLDOWN);
    pinMode(KEY_LEFT, INPUT_PULLDOWN);
    pinMode(KEY_RIGHT, INPUT_PULLDOWN);
}

void do_oled_keyboard_loop()
{
    u8g2.drawBox(0, 0, 128, 64);
    u8g2.sendBuffer();
}