#include "main.h"

LEDS led;
PACKET outmsg;
MAIL incmsg;
KEY key;

void setup() {
  /*
  Serial.begin(9600);
  while (!Serial)    ;
  Serial.println("LoRa Receiver");*/

  pinMode(POWER_LED, OUTPUT);
  pinMode(BUSY_1_LED, OUTPUT);
  pinMode(BUSY_2_LED, OUTPUT);  
  
  pinMode(POWER_RELAY, OUTPUT);
  digitalWrite(POWER_RELAY, LOW);
  pinMode(UP_OUTPUT, OUTPUT);
  digitalWrite(UP_OUTPUT, LOW);
  pinMode(DOWN_OUTPUT, OUTPUT);
  digitalWrite(DOWN_OUTPUT, LOW);
 

  digitalWrite(POWER_RELAY, HIGH);
  delay(DELAY_TIME);
  digitalWrite(POWER_LED, HIGH);
  delay(DELAY_TIME);
  digitalWrite(BUSY_1_LED, HIGH);
  delay(DELAY_TIME);
  digitalWrite(BUSY_2_LED, HIGH);
  delay(DELAY_TIME);

  LoRa.begin(LORA_FREQ);
  //LoRa.setTxPower(20);

  digitalWrite(BUSY_1_LED, LOW);
  digitalWrite(BUSY_2_LED, LOW);
  digitalWrite(POWER_LED, LOW);
  digitalWrite(UP_OUTPUT, LOW);
  digitalWrite(DOWN_OUTPUT, LOW);
  digitalWrite(POWER_RELAY, LOW);  
}

void loop() {
  leds();
  sensor();
  radio();
  work();
  //debugMode();
}