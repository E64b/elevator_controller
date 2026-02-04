#define RECIVER_ID 1 // Device ID

#define SENDER1_ID 1
#define SENDER2_ID 2

#define SOF 1

/*End radio setup*/
#define HC_TX_PIN 9
#define HC_RX_PIN 10
#define HC_SET_PIN 11
#define SIZE 4

/*DONT USE PINS D8, D9, D10, D11, D12, D13*/

/*Outputs*/
#define BUSY_1_LED 2 //Orange Led
#define BUSY_2_LED 3 //Blue led
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

#define LOSS_MSG_TIME 1000 //time for auto off if loss input msg

#define LED_DURATION 1000 // led flash time

#define RADIO_TIMING 10 //delay for recived msg