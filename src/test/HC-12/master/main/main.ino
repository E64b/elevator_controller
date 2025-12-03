 #include "main.h"

KEY key;
PACKET outmsg;
//MAIL incmsg;
SoftwareSerial HC12(HC_TX_PIN, HC_RX_PIN);

void pinInit() {
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
  pinInit();
  radioInit();
  Serial.end();
}

void loop() {
  keys();
  leds();  
  sender();
}