#include "main.h"

static uint32_t radioTimming = 0;
static bool recived = false;
static uint8_t currentID;
static bool firsPacket = true;
static char packet[3];

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
  recived = false;
 //Serial.print(incmsg.ID);
  //Serial.print(incmsg.firstByte);
 //Serial.print(incmsg.secondByte);
}

void reciver() {
  if (millis() - radioTimming > RADIO_TIMING) {    
    radioTimming = millis();
    if (radio.available()) {
      radio.read(&packet, sizeof(packet));      
      recived = true;
    }  
    incmsg.ID = packet[0];    
    if (firsPacket) {
      currentID = incmsg.ID;
      firsPacket = false;
    }
    incmsg.firstByte = packet[1];    
    incmsg.secondByte = packet[2];        
    if (recived) {
      commandDecoding();     
    }
  }
}
