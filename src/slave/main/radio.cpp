#include "main.h"

static uint32_t radioTimming;
static bool recived;

void senderIdDecoding() {}

void keyStateDecoding() {
  key.keyState1 = incmsg.keyState & (1 << 0); // �������� 0-�� ����
  key.keyState2 = incmsg.keyState & (1 << 1); // �������� 1-�� ����
  key.keyState3 = incmsg.keyState & (1 << 2); // �������� 2-�� ����
  key.keyState4 = incmsg.keyState & (1 << 3); // �������� 3-�� ����
  key.keyState6 = incmsg.keyState & (1 << 4); // �������� 4-�� ����
  key.keyState7 = incmsg.keyState & (1 << 5); // �������� 5-�� ����
  key.keyState8 = incmsg.keyState & (1 << 6); // �������� 6-�� ����
  key.keyState9 = incmsg.keyState & (1 << 7); // �������� 7-�� ����
  led.ledStateChange = true;
}

void commandDecoding() {
  incmsg.keyUp = incmsg.working & (1 << 0); // �������� 0-�� ����
  incmsg.keyDown = incmsg.working & (1 << 1); // �������� 1-�� ����
  incmsg.mode = incmsg.working & (1 << 2); // �������� 2-�� ����
  incmsg.work = incmsg.working & (1 << 3); // �������� 3-�� ����
  /*
  key.keyState6 = 0 & (1 << 4); // �������� 4-�� ����
  key.keyState7 = 0 & (1 << 5); // �������� 5-�� ����
  key.keyState8 = 0 & (1 << 6); // �������� 6-�� ����
  key.keyState9 = 0 & (1 << 7); // �������� 7-�� ����
  */
  led.ledStateChange = true;
}

void packetDecoding() {
  senderIdDecoding();
  keyStateDecoding();
  commandDecoding();
}

void radio() {
  int packetSize = LoRa.parsePacket();
  if (packetSize == 3) { // ��������� ������ ������
    char packet[3];
    int i = 0;
    // ������ �����
    while (LoRa.available() && i < 3) {
      packet[i++] = (char)LoRa.read();
    }

    // ������������� ������
    incmsg.ID = static_cast<uint8_t>(packet[0]);
    incmsg.keyState = static_cast<uint8_t>(packet[1]);
    incmsg.working = static_cast<uint8_t>(packet[2]);
    recived = true;

    if (millis() - radioTimming > RADIO_TIMING && recived) {
      radioTimming = millis();
      packetDecoding();
      recived = false;
    }
  }