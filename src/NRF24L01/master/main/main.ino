#include "main.h"

KEY key;
PACKET outmsg;
//MAIL incmsg;
RF24 radio(CE_PIN, CSN_PIN);

const byte address[6] = "00001";

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
  pinMode(LED_5_PIN, OUTPUT);
  pinMode(LED_6_PIN, OUTPUT);
  pinMode(LED_7_PIN, OUTPUT);
  pinMode(LED_8_PIN, OUTPUT);

  pinMode(KEY_PIN, INPUT);

  digitalWrite(LED_1_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_2_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_3_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_4_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_5_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_6_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_7_PIN, HIGH);
  delay(DELAY_TIME);
  digitalWrite(LED_8_PIN, HIGH);
  delay(DELAY_TIME);

  digitalWrite(LED_1_PIN, LOW);
  digitalWrite(LED_2_PIN, LOW);
  digitalWrite(LED_3_PIN, LOW);
  digitalWrite(LED_4_PIN, LOW);
  digitalWrite(LED_5_PIN, LOW);
  digitalWrite(LED_6_PIN, LOW);
  digitalWrite(LED_7_PIN, LOW);
  digitalWrite(LED_8_PIN, LOW);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setChannel(CHANNEL);  
  radio.setPALevel(POWER);
  radio.setDataRate(SPEED);
  radio.setCRCLength(RF24_CRC_16);
  radio.stopListening();
}

void loop() {
  leds();
  keys();
  sender();
}