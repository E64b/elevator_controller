#define RECIVER_ID 0x1 // Device ID HEX Device ID HEX MAX 8
#define LORA_FREQ 868E6 // FREQ LoRa module
#define SIGNAL_BANDWIDTH  125E3 //7.8E3, 10.4E3, 15.6E3, 20.8E3, 31.25E3, 41.7E3, 62.5E3, 125E3,250E3, and 500E3
#define SPREADING_FACTOR 10 // 6-12
#define TX_POWER 20

#define SENDER1_ID 0x1
#define SENDER2_ID 0x2

/*DONT USE PINS 
D2, D9, D10, D11, D12, D13*/

/*Outputs*/
#define BUSY_1_LED 3 //Orange Led
#define BUSY_2_LED 4 //Red led
#define POWER_LED 5 //Green Led

#define UP_OUTPUT 6 //Output For Relay UP
#define DOWN_OUTPUT 7 //Output For Relay Down
#define POWER_RELAY 8 //Output For Relay 380V power

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

#define RADIO_TIMING 0 //delay for recived msg