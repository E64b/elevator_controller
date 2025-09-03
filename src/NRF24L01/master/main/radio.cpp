#include "main.h"

static uint32_t radioTimming;
static char packet[3];

void keyStatePacket() {
  outmsg.firstByte = 0;
  outmsg.firstByte |= key.keyState1 ? (1 << 0) : 0;
  outmsg.firstByte |= key.keyState2 ? (1 << 1) : 0;
  outmsg.firstByte |= key.keyState3 ? (1 << 2) : 0;
  outmsg.firstByte |= key.keyState4 ? (1 << 3) : 0;
  outmsg.firstByte |= key.keyUp ? (1 << 4) : 0;
  outmsg.firstByte |= key.keyDown ? (1 << 5) : 0;
  outmsg.firstByte |= 0 ? (1 << 6) : 0;
  outmsg.firstByte |= 0 ? (1 << 7) : 0;

  outmsg.secondByte = 0;
  outmsg.secondByte |= key.keyState5 ? (1 << 0) : 0;
  outmsg.secondByte |= key.keyState6 ? (1 << 1) : 0;
  outmsg.secondByte |= key.keyState7 ? (1 << 2) : 0;
  outmsg.secondByte |= key.keyState8 ? (1 << 3) : 0;
  outmsg.secondByte |= key.keyMode ? (1 << 4) : 0;
  outmsg.secondByte |= key.keyWork ? (1 << 5) : 0;
  outmsg.secondByte |= 0 ? (1 << 6) : 0;
  outmsg.secondByte |= 0 ? (1 << 7) : 0;
}

void createPacket() {
  keyStatePacket();
  packet[0] = static_cast<char>(outmsg.ID);
  packet[1] = static_cast<char>(outmsg.firstByte);
  packet[2] = static_cast<char>(outmsg.secondByte);
}

void sender() {
  //createPacket();
  if (millis() - radioTimming > RADIO_TIMING) {
    createPacket();
    radioTimming = millis();
    radio.write((char *)packet, 3);
  }
}