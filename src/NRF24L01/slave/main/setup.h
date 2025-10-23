#define RECIVER_ID 0x1 // Device ID HEX Device ID HEX MAX 8

#define CE_PIN 9
#define CSN_PIN 10
#define MOSI_PIN 11
#define MISO_PIN 12
#define SCK_PIN 13
#define POWER RF24_PA_MAX //(LOW, MIN, HIGH, MAX)
#define SPEED RF24_250KBPS
#define CHANNEL 76 // (0 - 127)
#define SIZE 3
#define CRC RF24_CRC_8

/*End radio setup*/

#define SENDER1_ID 0x1
#define SENDER2_ID 0x2

/*DONT USE PINS D9, D10, D11, D12, D13*/

/*Outputs*/
#define BUSY_1_LED 2 //Orange Led
#define BUSY_2_LED 3 //Red led
#define POWER_LED 4 //Green Led

#define UP_OUTPUT 5 //Output For Relay UP
#define DOWN_OUTPUT 6 //Output For Relay Down
#define POWER_RELAY 7 //Output For Relay 380V power

/*rotation angle sensor*/
/*
#define SENSOR_PIN_1 X //0-1023
#define SENSOR_PIN_1 X //0-1023
#define SENSOR_PIN_1 X //0-1023

#define SENSOR_MAX_POS X //0-1023
#define SENSOR_MIN_POS X //0-1023

#define SENSOR_PIN_1 X //0-1023
#define SENSOR_PIN_1 X //0-1023
#define SENSOR_PIN_1 X //0-1023
*/

#define DELAY_TIME 1000 //time for init ms

#define LED_DURATION 500 // led flash time

#define POWER_DELAY 1000 // Delay for init power relay

#define RADIO_TIMING 10 //delay for recived msg