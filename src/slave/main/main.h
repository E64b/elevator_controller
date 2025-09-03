#pragma once
#pragma pack(push, 1)

/*LIBS*/
#include "lib/LoRa.h"
#include "setup.h"
#include <Arduino.h>
//#include <EEPROM.h>
#include <Print.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <math.h>

/*Leds outs
#define Output1
#define Output2
#define Output3
#define Output4
#define Output5
#define Output6
#define Output7
#define Output8
*/
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
void radio();
void sensor();
void debugMode();
void work();

extern KEY key;
extern LEDS led;
// extern PACKET outmsg;
extern MAIL incmsg;