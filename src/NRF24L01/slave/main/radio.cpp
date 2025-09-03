#include "main.h"

static uint32_t radioTimming;
static bool recived;
static uint8_t currentID;
static bool firsPacket = true;

void commandDecoding() {
  key.keyState1 = incmsg.firstByte & (1 << 0);
  key.keyState2 = incmsg.firstByte & (1 << 1);
  key.keyState3 = incmsg.firstByte & (1 << 2);
  key.keyState4 = incmsg.firstByte & (1 << 3);
  key.keyUp = incmsg.firstByte & (1 << 4);
  key.keyDown = incmsg.firstByte & (1 << 5);
  // key.keyState7 = incmsg.firstByte & (1 << 6);
  // key.keyState8 = incmsg.firstByte & (1 << 7);

  key.keyState5 = incmsg.secondByte & (1 << 0);
  key.keyState6 = incmsg.secondByte & (1 << 1);
  key.keyState7 = incmsg.secondByte & (1 << 2);
  key.keyState8 = incmsg.secondByte & (1 << 3);
  key.mode = incmsg.secondByte & (1 << 4);
  key.work = incmsg.secondByte & (1 << 5);
  // key.keyState7 = 0 & (1 << 6);
  // key.keyState8 = 0 & (1 << 7);
  led.ledStateChange = true;
}


void reciver() {
  if (radio.available()) {
    uint8_t receivedData[3];
    radio.read(&receivedData, sizeof(receivedData));
    incmsg.ID = receivedData[0];
    if (firsPacket) {
      currentID = incmsg.ID;
      firsPacket = false;
    }
    incmsg.firstByte = receivedData[1];
    incmsg.secondByte = receivedData[2];
    recived = true;
    if (millis() - radioTimming > RADIO_TIMING && recived) {
      radioTimming = millis();
      if (currentID == incmsg.ID) {
        commandDecoding();
      }
      recived = false;
    }
  }