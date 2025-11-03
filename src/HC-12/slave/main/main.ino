#include "main.h"

LEDS led;
// PACKET outmsg;
MAIL incmsg;
KEY key;
SoftwareSerial HC12(10, 11);

void pinRelayInit() {
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
}

void radioInit() {
  pinMode(HC_SET_PIN, OUTPUT);
  digitalWrite(HC_SET_PIN, LOW);
  delay(100);
  HC12.print("AT+C001");
  delay(100);
  HC12.print("AT+P8");
  delay(100);
  HC12.print("AT+FU3");
  delay(100);
  digitalWrite(HC_SET_PIN, HIGH);
}

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  pinRelayInit();
  radioInit();
}

void loop() {
  reciver();
  // sensor();
  leds();
  work();
}