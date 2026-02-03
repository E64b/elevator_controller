#include "main.h"

static bool idValid = false;
static uint8_t currentId = 0;
static uint32_t autoBlinkTimer = 0;

void checkID() {
  switch (RECIVER_ID) {
  case 1:
    if (key.keyState1) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
    break;
  case 2:
    if (key.keyState2) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
    break;
  case 3:
    if (key.keyState3) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
    break;
  case 4:
    if (key.keyState4) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
    break;
  case 5:
    if (key.keyState5) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
    break;
  case 6:
    if (key.keyState6) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
    break;
  case 7:
    if (key.keyState7) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
    break;
  case 8:
    if (key.keyState8) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
    break;
  }
}

void work() {
  if (!idValid) {
    checkID();
  }

  if (idValid && currentId == incmsg.ID) {

    idValid = false;

    if (key.keyUp && !key.keyDown) {
      digitalWrite(UP_OUTPUT, HIGH);
     
    } else {
      digitalWrite(UP_OUTPUT, LOW);
    }

    if (key.keyDown && !key.keyUp) {
      digitalWrite(DOWN_OUTPUT, HIGH);
      
    } else {
      digitalWrite(DOWN_OUTPUT, LOW);
    }

    if (key.work) {
      led.powerLed = true;
      digitalWrite(POWER_RELAY, HIGH);
      led.ledStateChange = true;
    } else {
      led.powerLed = false;
      digitalWrite(POWER_RELAY, LOW);
      led.ledStateChange = true;
    }

    if (key.mode && millis() - autoBlinkTimer >= LED_DURATION) {
      autoBlinkTimer = millis();
      led.ledStateChange = true;
      if (incmsg.ID == SENDER1_ID) {
        if (!led.busy1Led) {
          led.busy1Led = true;
          led.busy2Led = false;
        } else {
          led.busy1Led = false;
          led.busy2Led = false;
        }
      } else if (incmsg.ID == SENDER2_ID) {
        if (!led.busy2Led) {
          led.busy1Led = false;
          led.busy2Led = true;
        } else {
          led.busy1Led = false;
          led.busy2Led = false;
        }
      }
    }
    if (!key.mode) {
      led.ledStateChange = true;
      if (incmsg.ID == SENDER1_ID) {
        led.busy1Led = true;
        led.busy2Led = false;
      }
      if (incmsg.ID == SENDER2_ID) {
        led.busy1Led = false;
        led.busy2Led = true;
      }
    }
  }
}