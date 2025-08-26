#include "main.h"

static uint32_t radioTimming;
static bool recived;

void senderIdDecoding() {}

void keyStateDecoding() {
  key.keyState1 = incmsg.keyState & (1 << 0); // Проверка 0-го бита
  key.keyState2 = incmsg.keyState & (1 << 1); // Проверка 1-го бита
  key.keyState3 = incmsg.keyState & (1 << 2); // Проверка 2-го бита
  key.keyState4 = incmsg.keyState & (1 << 3); // Проверка 3-го бита
  key.keyState6 = incmsg.keyState & (1 << 4); // Проверка 4-го бита
  key.keyState7 = incmsg.keyState & (1 << 5); // Проверка 5-го бита
  key.keyState8 = incmsg.keyState & (1 << 6); // Проверка 6-го бита
  key.keyState9 = incmsg.keyState & (1 << 7); // Проверка 7-го бита
  led.ledStateChange = true;
}

void commandDecoding() {
  incmsg.keyUp = incmsg.working & (1 << 0); // Проверка 0-го бита
  incmsg.keyDown = incmsg.working & (1 << 1); // Проверка 1-го бита
  incmsg.mode = incmsg.working & (1 << 2); // Проверка 2-го бита
  incmsg.work = incmsg.working & (1 << 3); // Проверка 3-го бита
  /*
  key.keyState6 = 0 & (1 << 4); // Проверка 4-го бита
  key.keyState7 = 0 & (1 << 5); // Проверка 5-го бита
  key.keyState8 = 0 & (1 << 6); // Проверка 6-го бита
  key.keyState9 = 0 & (1 << 7); // Проверка 7-го бита
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
  if (packetSize == 3) { // Проверяем размер пакета
    char packet[3];
    int i = 0;
    // Читаем пакет
    while (LoRa.available() && i < 3) {
      packet[i++] = (char)LoRa.read();
    }

    // Распаковываем данные
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