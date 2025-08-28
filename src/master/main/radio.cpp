#include "main.h"

static uint32_t radioTimming;
static char packet[3];

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

void workStatePacket() {  
    outmsg.working = 0;
    outmsg.working |= key.keyUp ? (1 << 0) : 0;
    outmsg.working |= key.keyDown ? (1 << 1) : 0;
    outmsg.working |= key.keyMode ? (1 << 2) : 0;
    outmsg.working |= key.keyWork ? (1 << 3) : 0;
    outmsg.working |= 0 ? (1 << 4) : 0;
    outmsg.working |= 0 ? (1 << 5) : 0;
    outmsg.working |= 0 ? (1 << 6) : 0;
    outmsg.working |= 0 ? (1 << 7) : 0;   
}

void createPacket() {
  keyStatePacket();
  workStatePacket();

  packet[0] = static_cast<char>(outmsg.ID);
  packet[1] = static_cast<char>(outmsg.keyState);
  packet[2] = static_cast<char>(outmsg.working);
}

void radio() {
  createPacket();
  if (millis() - radioTimming > RADIO_TIMING) {
    //createPacket();
    radioTimming = millis();
    LoRa.beginPacket();
    LoRa.write((char *)packet, 3);
    LoRa.endPacket();
  }
}