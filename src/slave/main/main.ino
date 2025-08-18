#include "main.h"

VAL val;

void setup() {
  /*Other init*/
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  pinMode(LED_3_PIN, OUTPUT);
  pinMode(LED_4_PIN, OUTPUT);
  pinMode(LED_5_PIN, OUTPUT);
  pinMode(LED_6_PIN, OUTPUT);
  pinMode(LED_7_PIN, OUTPUT);
  pinMode(LED_8_PIN, OUTPUT);
  pinMode(KEY_PIN, INPUT);
 
  /*Stepper init*/
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
  pinMode(STEP, OUTPUT);

  /*PID init*/
  PIDreg.setDirection(NORMAL);
  PIDreg.setLimits(0, 255);
  PIDreg.setDt(10000);
  PIDreg.setpoint = DEFAULT_TARGET_TEMP;
  /*PID setup*/
  PIDreg.Kp = 1;
  PIDreg.Ki += 456;
  PIDreg.Kd = 46.7;

  val.displayRedraw = true;
  delay(5000);
  lcd.clear();
}

void loop() {
  enc.tick();
  start.tick();
  digitalWrite(EN, val.stepper);

  menu();
  display();
  tempSensor();
  protection();
  rPID();
  work();
}