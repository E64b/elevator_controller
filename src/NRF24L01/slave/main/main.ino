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

  //Serial.begin(115200);

  radio.begin();
  radio.setChannel(CHANNEL);
  radio.setDataRate(SPEED);
  radio.setPALevel(POWER);
  // radio.disableDynamicPayloads();
  radio.setPayloadSize(SIZE);
  radio.setCRCLength(CRC);
  radio.openReadingPipe(0, address);
  // radio.disableCRC();
  radio.startListening();
}

void loop() {
  reciver();
  // sensor();
  leds();
  work();
  /*
  if (radio.available()) {
    char packet[3] = "";
        radio.read(&packet, sizeof(packet));
    Serial.println(packet);
    Serial.println("2");
  }*/
}