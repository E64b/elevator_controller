/*Radio setup*/
#define TRANCIVER_ID 0x1 // Device ID HEX MAX 8
#define RADIO_TIMING 100 //Frequency of sending messages

#define CE_PIN 9
#define CSN_PIN 10
#define MOSI_PIN 11
#define MISO_PIN 12
#define SCK_PIN 13
#define POWER RF24_PA_MIN //(LOW, MIN, HIGH, MAX)
#define SPEED RF24_250KBPS
#define CHANNEL 76 // (0 - 127)
#define SIZE 3
#define CRC RF24_CRC_8

/*End radio setup*/

/*Keys setup*/
#define NUM_READ 3 //Averaging
#define KEY_PROTECTION 250 //Protection against shattering

#define KEY_1_VAL 0 //0-1023 base 0
#define KEY_2_VAL 92 //0-1023 base 92
#define KEY_3_VAL 167 //0-1023 base 170
#define KEY_4_VAL 231 //0-1023 base 235
#define KEY_5_VAL 287 //0-1023 base 291
#define KEY_6_VAL 344 //0-1023 base 340
#define KEY_7_VAL 384 //0-1023 base 382
#define KEY_8_VAL 419 //0-1023 base 420
#define KEY_9_VAL 451 //0-1023 base 453
#define KEY_10_VAL 483 //0-1023 base 483
#define KEY_11_VAL 511 //0-1023 base 510
#define KEY_12_VAL 536 //0-1023 base 534
#define KEY_RELISED 1023 //All key relised 1020 
#define TOLERANCE 15 //Measurement accuracy
/*End keys setup*/

/*Leds setup*/
#define FLASH_TIME 500 //led flash time
#define NUM_FLASH 5 //Number of flashes
#define LED_DURATION 50 //The refresh rate of the leds
/*End leds setup*/

/*Others*/
#define DELAY_TIME 100 // time for init ms