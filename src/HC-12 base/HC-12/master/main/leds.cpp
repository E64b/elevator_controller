#include "main.h"

static uint32_t ledDuration;

void leds() {
  if (millis() - ledDuration > LED_DURATION && key.keyStateChange) {
    ledDuration = millis();
    key.keyStateChange = false;
    digitalWrite(LED_1_PIN, key.keyState1);
    digitalWrite(LED_2_PIN, key.keyState2);
    digitalWrite(LED_3_PIN, key.keyState3);
    digitalWrite(LED_4_PIN, key.keyState4);
    digitalWrite(LED_5_PIN, key.keyState5);
    digitalWrite(LED_6_PIN, key.keyState6);
    digitalWrite(LED_7_PIN, key.keyState7);
    digitalWrite(LED_8_PIN, key.keyState8);
  }
}