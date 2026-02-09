#include "main.h"

static uint32_t noMsgBlinkTimer = 0;

void errorBlink() {
  if (millis() - noMsgBlinkTimer >= LED_DURATION) {
    noMsgBlinkTimer = millis();
    led.ledStateChange = true;
    {
      if (!led.powerLed) {
        led.powerLed = true;
      } else {
        led.powerLed = false;
      }
    }
  }
}

void protection() {
  if (millis() - data.msgTime >= LOSS_MSG_TIME) {
    key.keyUp = false;
    key.keyDown = false;
    key.work = false;
    errorBlink();
    data.error = true;
  }
}