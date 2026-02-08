#include <Arduino.h>

static const int LED_PIN = 2; // burada 2, sonra gerekirse degistir
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
