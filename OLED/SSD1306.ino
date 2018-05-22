

#include <Wire.h>  
#include "SSD1306.h"

//OLED pins to ESP32 GPIOs via this connecthin:
//OLED_SDA -- GPIO5
//OLED_SCL -- GPIO4

SSD1306  display(0x3c, 5, 4);

void setup() {
  display.init();
  display.flipScreenVertically();
  display.clear();
}

void loop() {

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Hello world");
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 10, "Hello world");
  display.setFont(ArialMT_Plain_24);
  display.drawString(0, 26, "Hello world");

  display.display();

  while(1);
}
