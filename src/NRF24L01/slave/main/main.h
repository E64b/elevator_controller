#pragma once
#pragma pack(push, 1)

/*LIBS*/
#include "setup.h"
#include "lib/RF24.h"
#include "lib/nRF24L01.h"
#include <Arduino.h>
#include <EEPROM.h>
#include <Print.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <math.h>


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

#pragma pack(pop)

void leds();
void reciver();
void sensor();
void work();

extern KEY key;
extern LEDS led;
//extern PACKET outmsg;
extern MAIL incmsg;
extern RF24 radio;