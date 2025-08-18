/*DEFINES*/
/*Key ADC pin*/
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

/*LIBS*/

#include <Arduino.h>
#include <EEPROM.h>
#include <Print.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <math.h>

#include "setup.h"
#include <SPI.h>
#include <LoRa.h>