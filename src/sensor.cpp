#include "sensor.h"
#include <Arduino.h>
#include <DHT.h>

static const int DHT_PIN = 4;
static const int DHT_TYPE = DHT22;

static DHT dht(DHT_PIN, DHT_TYPE);

void sensor_init(void) {
  dht.begin();
}

sensor_reading_t sensor_read(void) {
  sensor_reading_t r;
  r.humidity = dht.readHumidity();
  r.temp_c   = dht.readTemperature(); // Celsius

  // DHT bazen NaN doner; bunu yakala
  if (isnan(r.humidity) || isnan(r.temp_c)) {
    r.ok = false;
    r.humidity = NAN;
    r.temp_c = NAN;
  } else {
    r.ok = true;
  }
  return r;
}
