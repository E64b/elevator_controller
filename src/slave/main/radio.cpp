#include "main.h"

static uint32_t radioTimming;

void radio() {

  if (millis() - radioTimming > RADIO_TIMING) {
    radioTimming = millis();
    LoRa.beginPacket();
    LoRa.endPacket();
  }
}