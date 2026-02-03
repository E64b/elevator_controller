#include "main.h"

LEDS led;
// PACKET outmsg;
MAIL incmsg;
KEY key;
DataMemory dataMem;
DATA data;
SoftwareSerial HC12(HC_TX_PIN, HC_RX_PIN);

void pinRelayInit() {
  pinMode(POWER_LED, OUTPUT);
  pinMode(BUSY_1_LED, OUTPUT);
  pinMode(BUSY_2_LED, OUTPUT);

  pinMode(POWER_RELAY, OUTPUT);
  digitalWrite(POWER_RELAY, LOW);
  pinMode(UP_OUTPUT, OUTPUT);
  digitalWrite(UP_OUTPUT, LOW);
  pinMode(DOWN_OUTPUT, OUTPUT);
  digitalWrite(DOWN_OUTPUT, LOW);

  digitalWrite(BUSY_1_LED, LOW);
  digitalWrite(BUSY_2_LED, LOW);
  digitalWrite(POWER_LED, LOW);
  delay(DELAY_TIME);
  digitalWrite(POWER_LED, HIGH);
  delay(DELAY_TIME);
  digitalWrite(BUSY_1_LED, HIGH);
  delay(DELAY_TIME);
  digitalWrite(BUSY_2_LED, HIGH);
  delay(DELAY_TIME);

  digitalWrite(BUSY_1_LED, LOW);
  digitalWrite(BUSY_2_LED, LOW);
  digitalWrite(POWER_LED, LOW);
}

void radioInit() {
  if (!dataMem.firstInit) {
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
    dataMem.firstInit = true;
  }
}

void eepromReading() {
  /*Reading EEPROM*/
  if (!EEPROM.get(0, dataMem.testDataMem)) {
    EEPROM.put(0, dataMem);
    dataMem.testDataMem = true;
    delay(1000);
  } else {
    EEPROM.get(0, dataMem);
    delay(1000);
  }
}

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
  eepromReading();
  pinRelayInit();
  radioInit();
  Serial.end();
}

void loop() {
  reciver();
  // sensor();
  leds();  
  work();
  protection();
}