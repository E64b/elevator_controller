#include "main.h"

static uint32_t radioTimming = 0;
static bool recived = false;
static uint8_t currentID;
static bool firsPacket = true;
static char packet[SIZE];

uint8_t crc8(const char *data, size_t length) {
  uint8_t crc = 0x00;
  uint8_t polynomial = 0x07;

  for (size_t i = 0; i < length; i++) {
    crc ^= data[i];
    for (byte j = 0; j < 8; j++) {
      if (crc & 0x80) {
        crc = (crc << 1) ^ polynomial;
      } else {
        crc <<= 1;
      }
    }
  }
  return crc;
}

void commandDecoding() {
  key.keyState1 = incmsg.firstByte & (1 << 0);
  key.keyState2 = incmsg.firstByte & (1 << 1);
  key.keyState3 = incmsg.firstByte & (1 << 2);
  key.keyState4 = incmsg.firstByte & (1 << 3);
  key.keyUp = incmsg.firstByte & (1 << 4);
  key.keyDown = incmsg.firstByte & (1 << 5);
  // val = incmsg.firstByte & (1 << 6);
  // val = incmsg.firstByte & (1 << 7);

  key.keyState5 = incmsg.secondByte & (1 << 0);
  key.keyState6 = incmsg.secondByte & (1 << 1);
  key.keyState7 = incmsg.secondByte & (1 << 2);
  key.keyState8 = incmsg.secondByte & (1 << 3);
  key.mode = incmsg.secondByte & (1 << 4);
  key.work = incmsg.secondByte & (1 << 5);
  // val = incmsg.secondByte & (1 << 6);
  // val = incmsg.secondByte & (1 << 7);
  led.ledStateChange = true;
}

void reciver() {
 if (millis() - radioTimming > RADIO_TIMING) {
    radioTimming = millis();
    if (HC12.available() > 0) {
      if (HC12.read() == incmsg.SOF) {
        for (uint8_t i = 1; i < SIZE; i++) {
          packet[i] = HC12.read();
        }
        packet[0] = incmsg.SOF;
     }
      uint8_t receivedCRC = HC12.read();
      uint8_t calculatedCRC = crc8((const char *)packet, SIZE);

      if (receivedCRC == calculatedCRC) {
        incmsg.ID = packet[1];
        incmsg.firstByte = packet[2];
        incmsg.secondByte = packet[3];
        for (uint8_t i = 0; i < SIZE; i++) {
          packet[i] = 0;
        }
        recived = true;
      }
    }

    if (recived) {
      commandDecoding();
      recived = false;
    }
  }
}