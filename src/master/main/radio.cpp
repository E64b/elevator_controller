#include "main.h"

static uint32_t radioTimming;

// ”паковка в uint8_t
void keyStatePacket() {
  outmsg.keyState = 0;
  outmsg.keyState |= key.keyState1 ? (1 << 0) : 0;
  outmsg.keyState |= key.keyState2 ? (1 << 1) : 0;
  outmsg.keyState |= key.keyState3 ? (1 << 2) : 0;
  outmsg.keyState |= key.keyState4 ? (1 << 3) : 0;
  outmsg.keyState |= key.keyState5 ? (1 << 4) : 0;
  outmsg.keyState |= key.keyState6 ? (1 << 5) : 0;
  outmsg.keyState |= key.keyState7 ? (1 << 6) : 0;
  outmsg.keyState |= key.keyState8 ? (1 << 7) : 0;
}

void radio() {
  if (millis() - radioTimming > RADIO_TIMING) {
    keyStatePacket();
    radioTimming = millis();
    LoRa.beginPacket();
    LoRa.print("hello ");
    LoRa.print()
    LoRa.endPacket();
  }
}