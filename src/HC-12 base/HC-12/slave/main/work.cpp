#include "main.h"

static bool idValid = false;
static uint8_t idNow = 0;
static uint8_t currentId = 0;

void checkID() {
  if (key.keyState1) {
    idNow = 1;
    if (idNow == RECIVER_ID) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
  }
  if (key.keyState2) {
    idNow = 2;
    if (idNow == RECIVER_ID) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
  }
  if (key.keyState3) {
    idNow = 3;
    if (idNow == RECIVER_ID) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
  }
  if (key.keyState4) {
    idNow = 4;
    if (idNow == RECIVER_ID) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
  }
  if (key.keyState5) {
    idNow = 5;
    if (idNow == RECIVER_ID) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
  }
  if (key.keyState6) {
    idNow = 6;
    if (idNow == RECIVER_ID) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
  }
  if (key.keyState7) {
    idNow = 7;
    if (idNow == RECIVER_ID) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
  }
  if (key.keyState8) {
    idNow = 8;
    if (idNow == RECIVER_ID) {
      idValid = true;
      currentId = incmsg.ID;
      led.powerLed = true;
      led.ledStateChange = true;
    }
  }
}

void work() {
  if (!idValid) {
    checkID();
  }

  if (idValid && currentId == incmsg.ID) {
    idValid=false;
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

    if (key.mode) {
      led.busy1Led = true;
      led.busy2Led = false;
      led.ledStateChange = true;
    } else {
      led.busy1Led = false;
      led.busy2Led = true;
      led.ledStateChange = true;
    }
  }
}