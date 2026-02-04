#pragma once

/*LIBS*/
#include "setup.h"
#include <Arduino.h>
#include <EEPROM.h>
#include <Print.h>
#include <SPI.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <math.h>

struct DataMemory {
  /*DON`T TOUCH*/
  bool testDataMem = false;
  /*DON`T TOUCH*/
  bool firstInit = false;
  /*DON`T TOUCH*/
};

#pragma pack(push, 1)

/*
typedef struct {
  uint8_t ID;
  uint8_t keyState = false;
  bool keyUp = false;
  bool keyDown = false;
  bool work = false;
  bool mode = false;
} PACKET;
*/

typedef struct {
  uint8_t SOF = DSOF;
  uint8_t ID;
  uint8_t firstByte = 0;
  uint8_t secondByte = 0;
} MAIL;

typedef struct {
  bool busy1Led = true;
  bool busy2Led = true;
  bool powerLed = true;
  bool ledStateChange = false;
} LEDS;

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
  bool work = false;
  bool mode = false;
} KEY;

typedef struct {
  bool error = false;
  uint32_t msgTime = 0;
} DATA;

#pragma pack(pop)

void leds();
void reciver();
// void sensor();
void work();
void protection();

extern KEY key;
extern LEDS led;
extern DataMemory dataMem;
extern DATA data;
// extern PACKET outmsg;
extern MAIL incmsg;
extern SoftwareSerial HC12;