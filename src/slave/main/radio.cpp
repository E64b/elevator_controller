#include "main.h"

static uint32_t radioTimming;
static bool recived;

void senderIdDecoding() { led.ledStateChange = true; }

void keyStateDecoding() {
  key.keyState1 = incmsg.keyState & (1 << 0); // �������� 0-�� ����
  key.keyState2 = incmsg.keyState & (1 << 1); // �������� 1-�� ����
  key.keyState3 = incmsg.keyState & (1 << 2); // �������� 2-�� ����
  key.keyState4 = incmsg.keyState & (1 << 3); // �������� 3-�� ����
  key.keyState6 = incmsg.keyState & (1 << 4); // �������� 4-�� ����
  key.keyState7 = incmsg.keyState & (1 << 5); // �������� 5-�� ����
  key.keyState8 = incmsg.keyState & (1 << 6); // �������� 6-�� ����
  key.keyState9 = incmsg.keyState & (1 << 7); // �������� 7-�� ����
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