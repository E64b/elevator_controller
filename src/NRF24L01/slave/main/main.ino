#include "main.h"

LEDS led;
// PACKET outmsg;
MAIL incmsg;
KEY key;
RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

 void setup() {
  pinMode(POWER_LED, OUTPUT);
  pinMode(BUSY_1_LED, OUTPUT);
  pinMode(BUSY_2_LED, OUTPUT);

  pinMode(POWER_RELAY, OUTPUT);
  digitalWrite(POWER_RELAY, HIGH);
  pinMode(UP_OUTPUT, OUTPUT);
  digitalWrite(UP_OUTPUT, HIGH);
  pinMode(DOWN_OUTPUT, OUTPUT);
  digitalWrite(DOWN_OUTPUT, HIGH);

  digitalWrite(POWER_LED, LOW);
  delay(DELAY_TIME);
  digitalWrite(BUSY_1_LED, LOW);
  delay(DELAY_TIME);
  digitalWrite(BUSY_2_LED, LOW);
  delay(DELAY_TIME);

  digitalWrite(BUSY_1_LED, HIGH);
  digitalWrite(BUSY_2_LED, HIGH);
  digitalWrite(POWER_LED, HIGH);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setChannel(CHANNEL);
  radio.setPALevel(POWER);
  radio.setDataRate(SPEED);
  radio.setCRCLength(RF24_CRC_16);
  radio.startListening();
}

void loop() {
  leds();
  sensor();
  reciver();
  work();
}