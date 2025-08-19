#pragma once

/*LIBS*/
#include "lib/LoRa.h"
#include "setup.h"
#include <Arduino.h>
#include <EEPROM.h>
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

typedef struct {
  uint8_t ID;
  uint8_t keyState = false;
  bool keyUp = false;
  bool keyDown = false;
  bool work = false;
  bool mode = false;
} PACKET;

typedef struct {
  uint8_t ID = SENDER_ID;
  uint8_t keyState = false;
  bool keyUp = false;
  bool keyDown = false;
  bool work = false;
  bool mode = false;
} MAIL;

typedef struct {
  uint8_t ID = SENDER_ID;
  uint8_t keyState = false;
  bool keyUp = false;
  bool keyDown = false;
  bool work = false;
  bool mode = false;
} LEDS;

#pragma pack(pop)

void leds();
void radio();
void sensor();

extern LEDS led;
extern PACKET outmsg;
extern MAIL incmsg;