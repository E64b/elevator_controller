#include "main.h"

static uint32_t radioTimming;
static uint8_t packet[SIZE];

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

void keyStatePacket() {
  outmsg.firstByte = 0;
  outmsg.firstByte |= key.keyState1 ? (1 << 0) : 0;
  outmsg.firstByte |= key.keyState2 ? (1 << 1) : 0;
  outmsg.firstByte |= key.keyState3 ? (1 << 2) : 0;
  outmsg.firstByte |= key.keyState4 ? (1 << 3) : 0;
  outmsg.firstByte |= key.keyUp ? (1 << 4) : 0;
  outmsg.firstByte |= key.keyDown ? (1 << 5) : 0;
  outmsg.firstByte |= 1 ? (1 << 6) : 0;
  outmsg.firstByte |= 0 ? (1 << 7) : 0;

  outmsg.secondByte = 0;
  outmsg.secondByte |= key.keyState5 ? (1 << 0) : 0;
  outmsg.secondByte |= key.keyState6 ? (1 << 1) : 0;
  outmsg.secondByte |= key.keyState7 ? (1 << 2) : 0;
  outmsg.secondByte |= key.keyState8 ? (1 << 3) : 0;
  outmsg.secondByte |= key.keyMode ? (1 << 4) : 0;
  outmsg.secondByte |= key.keyWork ? (1 << 5) : 0;
  outmsg.secondByte |= 1 ? (1 << 6) : 0;
  outmsg.secondByte |= 0 ? (1 << 7) : 0;
}

void createPacket() {
  keyStatePacket();
  packet[0] = static_cast<char>(outmsg.sof);
  packet[1] = static_cast<char>(outmsg.id);
  packet[2] = static_cast<char>(outmsg.firstByte);
  packet[3] = static_cast<char>(outmsg.secondByte);
}

void sender() {
  if (millis() - radioTimming > RADIO_TIMING) {
    createPacket();
    radioTimming = millis();
    uint8_t crc = crc8((char *)packet, SIZE);
    HC12.write((char *)packet, SIZE);    
    HC12.write(crc);
  }
}