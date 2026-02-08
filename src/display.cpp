#include "display.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

static const int SCREEN_W = 128;
static const int SCREEN_H = 64;

// Adres genelde 0x3C. Bazi ekranlar 0x3D olabilir.
static const uint8_t OLED_ADDR = 0x3C;

Adafruit_SSD1306 oled(SCREEN_W, SCREEN_H, &Wire, -1);

void display_init(void) {
  Wire.begin(); // ESP32: SDA=21, SCL=22 default

  if (!oled.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    // Ekran yoksa takilmamak icin sadece Serial'a yazip devam edelim
    Serial.println("OLED init failed");
    return;
  }

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0, 0);
  oled.println("OLED ready");
  oled.display();
}

void display_show(float temp_c, float humidity, bool ok) {
  oled.clearDisplay();
  oled.setTextColor(SSD1306_WHITE);

  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.println("DHT22");

  if (!ok) {
    oled.println("READ ERROR");
    oled.display();
    return;
  }

  // Büyük sayılar: text size 2 sadece sayılarda
  oled.setTextSize(2);
  oled.setCursor(0, 16);
  oled.print(temp_c, 0);
  oled.print("C");

  oled.setCursor(0, 40);
  oled.print(humidity, 0);
  oled.print("%");

  oled.display();
}

