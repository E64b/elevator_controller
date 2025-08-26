#include "main.h"

static uint32_t radioTimming;
static bool recived;

void senderIdDecoding() { led.ledStateChange = true; }

void keyStateDecoding() {
  key.keyState1 = incmsg.keyState & (1 << 0); // Проверка 0-го бита
  key.keyState2 = incmsg.keyState & (1 << 1); // Проверка 1-го бита
  key.keyState3 = incmsg.keyState & (1 << 2); // Проверка 2-го бита
  key.keyState4 = incmsg.keyState & (1 << 3); // Проверка 3-го бита
  key.keyState6 = incmsg.keyState & (1 << 4); // Проверка 4-го бита
  key.keyState7 = incmsg.keyState & (1 << 5); // Проверка 5-го бита
  key.keyState8 = incmsg.keyState & (1 << 6); // Проверка 6-го бита
  key.keyState9 = incmsg.keyState & (1 << 7); // Проверка 7-го бита
}

void commandDecoding() {}

void modeDecoding() { led.ledStateChange = true; }

void packetDecoding() {
  senderIdDecoding();
  keyStateDecoding();
  commandDecoding();
  modeDecoding();
}

void radio() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    while (LoRa.available()) {
      (char)LoRa.read();
      recived = true;
    }
  }

  if (millis() - radioTimming > RADIO_TIMING && recived) {
    radioTimming = millis();
    packetDecoding();
    recived = false;
  }
}