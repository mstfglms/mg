#include <Arduino.h>
#include "sensor.h"
#include "display.h"

unsigned long lastPrint = 0;

void setup() {
  Serial.begin(115200);
  delay(200);

  sensor_init();
  display_init();

  Serial.println("DHT22 + OLED started");
}

void loop() {
  unsigned long now = millis();
  if (now - lastPrint >= 2000) {
    lastPrint = now;

    sensor_reading_t r = sensor_read();

    if (!r.ok) {
      Serial.println("DHT read failed");
    } else {
      Serial.print("Temp C: "); Serial.print(r.temp_c, 1);
      Serial.print("  Hum: ");  Serial.print(r.humidity, 1);
      Serial.println(" %");
    }

    display_show(r.temp_c, r.humidity, r.ok);
  }
}
