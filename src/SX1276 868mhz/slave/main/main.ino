#include "main.h"

LEDS led;
//PACKET outmsg;
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
  digitalWrite(POWER_RELAY, HIGH);
  pinMode(UP_OUTPUT, OUTPUT);
  digitalWrite(UP_OUTPUT, HIGH);
  pinMode(DOWN_OUTPUT, OUTPUT);
  digitalWrite(DOWN_OUTPUT, HIGH);
 

  digitalWrite(POWER_RELAY, HIGH);
  delay(DELAY_TIME);
  digitalWrite(POWER_LED, LOW);
  delay(DELAY_TIME);
  digitalWrite(BUSY_1_LED, LOW);
  delay(DELAY_TIME);
  digitalWrite(BUSY_2_LED, LOW);
  delay(DELAY_TIME);

  LoRa.begin(LORA_FREQ);
  LoRa.setSpreadingFactor(SPREADING_FACTOR);
  LoRa.setSignalBandwidth(SIGNAL_BANDWIDTH);
  LoRa.setTxPower(TX_POWER);
  // LoRa.enableCrc();
  LoRa.disableCrc();

  digitalWrite(BUSY_1_LED, HIGH);
  digitalWrite(BUSY_2_LED, HIGH);
  digitalWrite(POWER_LED, HIGH);
  digitalWrite(UP_OUTPUT, HIGH);
  digitalWrite(DOWN_OUTPUT, HIGH);
  digitalWrite(POWER_RELAY, HIGH);  
    pinMode(1, OUTPUT);
}

void loop() {
  leds();
  sensor();
  radio();
  work();
  //debugMode();
}