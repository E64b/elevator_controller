#pragma once
#pragma pack(push, 1)

/*LIBS*/
#include "setup.h"
#include <Arduino.h>
// #include <EEPROM.h>
#include <Print.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <math.h>

/*key ADC input*/
#define KEY_PIN A0

/*Leds outs*/
#define LED_1_PIN 1
#define LED_2_PIN 0
#define LED_3_PIN 3
#define LED_4_PIN 4
#define LED_5_PIN 5
#define LED_6_PIN 6
#define LED_7_PIN 7
#define LED_8_PIN 8

typedef struct {
  bool keyState1 = false;
  bool keyState2 = false;
  bool keyState3 = false;
  bool keyState4 = false;
  bool keyState5 = false;
  bool keyState6 = false;
  bool keyState7 = false;
  bool keyState8 = false;
  bool keyUp = false;
  bool keyDown = false;
  bool keyWork = false;
  bool keyMode = false;

  bool keyStateChange = false;
  bool workState = false;
} KEY;

typedef struct {
  uint8_t SOF = 252;
  uint8_t ID = TRANCIVER_ID;
  uint8_t firstByte = 0;
  uint8_t secondByte = 0;
} PACKET;

/*
typedef struct {
  uint8_t ID = SENDER_ID;
  uint8_t keyState = 0;
  bool keyUp = false;
  bool keyDown = false;
  bool work = false;
  bool mode = false;
} MAIL;
*/

#pragma pack(pop)

void leds();
void keys();
void sender();

extern KEY key;
extern PACKET outmsg;
// extern MAIL incmsg;
extern SoftwareSerial HC12;