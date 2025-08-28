#include "main.h"

KEY key;
PACKET outmsg;
// MAIL incmsg;

void setup() {
  /*
  Serial.begin(9600);
  while (!Serial)    ;
  Serial.println("LoRa Receiver");*/

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

  LoRa.begin(LORA_FREQ);
  LoRa.setSpreadingFactor(SPREADING_FACTOR); 
  LoRa.setSignalBandwidth(SIGNAL_BANDWIDTH);
  LoRa.setTxPower(TX_POWER);
  //LoRa.enableCrc();
  LoRa.disableCrc();
}
void loop() {
  leds();
  keys();
  radio();
  // debugMode();
}