#include "main.h"

static uint32_t ledDuration;

void leds() {
  if (millis() - ledDuration > LED_DURATION && key.keyStateChange == true) {
    ledDuration = millis();
    led.ledStateChange = false;
    digitalWrite(BUSY_1_LED, led.busy1Led);
    digitalWrite(BUSY_2_LED, led.busy2Led);
    digitalWrite(POWER_LED, led.powerLed);
  }
}