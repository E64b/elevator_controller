#include "main.h"

LEDS led;
// PACKET outmsg;
MAIL incmsg;
KEY key;
RAD rad;
RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

void initializeRadio() {
  radio.begin();
  radio.setChannel(CHANNEL);
  radio.setDataRate(SPEED);
  radio.setPALevel(POWER);
  radio.setAutoAck(false);
  //  radio.disableDynamicPayloads();
  radio.setPayloadSize(SIZE);
  radio.setCRCLength(CRC);
  radio.openReadingPipe(0, address);
  // radio.disableCRC();
  radio.startListening();
}

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

  digitalWrite(BUSY_1_LED, HIGH);
  digitalWrite(BUSY_2_LED, HIGH);
  digitalWrite(POWER_LED, HIGH);
  delay(DELAY_TIME);
  digitalWrite(POWER_LED, LOW);
  delay(DELAY_TIME);
  digitalWrite(BUSY_1_LED, LOW);
  delay(DELAY_TIME);
  digitalWrite(BUSY_2_LED, LOW);
  delay(DELAY_TIME);

  digitalWrite(BUSY_1_LED, HIGH);
  digitalWrite(BUSY_2_LED, HIGH);
  digitalWrite(POWER_LED, HIGH);

  //pinMode(IRQ_PIN, INPUT);
  initializeRadio(); 

  rad.lastReceiveTime = millis();
}

void loop() {
  radio.startListening();
  reciver();
  // sensor();
  leds();
  work();
}