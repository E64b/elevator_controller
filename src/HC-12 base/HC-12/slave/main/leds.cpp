#include "main.h"

void leds() {
    if (led.ledStateChange){
    led.ledStateChange = false;
    digitalWrite(BUSY_1_LED, led.busy1Led);
    digitalWrite(BUSY_2_LED, led.busy2Led);
    digitalWrite(POWER_LED, led.powerLed);
  }
}