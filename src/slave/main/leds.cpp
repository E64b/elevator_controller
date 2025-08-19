#include "main.h"

static uint32_t ledDuration;

void leds() {
  if (millis() - ledDuration > LED_DURATION && key.keyStateChange == true) {
    ledDuration = millis();
    key.keyStateChange = false;
    digitalWrite(BUSY_1_LED, key.keyState1);
    digitalWrite(BUSY_2_LED, key.keyState2);
    digitalWrite(POWER_LED, key.keyState3);
  }
}