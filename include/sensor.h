#pragma once
#include <stdbool.h>

typedef struct {
  float temp_c;
  float humidity;
  bool ok;
} sensor_reading_t;

void sensor_init(void);
sensor_reading_t sensor_read(void);
