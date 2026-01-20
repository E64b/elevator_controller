#include "main.h"

static bool idValid = false;

static uint8_t idNow = 0;

void checkID() {
  if (key.keyState1) {
    idNow = 1;
    if (idNow == RECIVER_ID) {
      idValid = true;
    }
  }
  if (key.keyState2) {
    idNow = 2;
    if (idNow == RECIVER_ID) {
      idValid = true;
    }
  }
  if (key.keyState3) {
    idNow = 3;
    if (idNow == RECIVER_ID) {
      idValid = true;
    }
  }
  if (key.keyState4) {
    idNow = 4;
    if (idNow == RECIVER_ID) {
      idValid = true;
    }
  }
  if (key.keyState5) {
    idNow = 5;
    if (idNow == RECIVER_ID) {
      idValid = true;
    }
  }
  if (key.keyState6) {
    idNow = 6;
    if (idNow == RECIVER_ID) {
      idValid = true;
    }
  }
  if (key.keyState7) {
    idNow = 7;
    if (idNow == RECIVER_ID) {
      idValid = true;
    }
  }
  if (key.keyState8) {
    idNow = 8;
    if (idNow == RECIVER_ID) {
      idValid = true;
    }
  }
}

void work() {
  if (!idValid) {
    checkID();
  }

  if (idValid) {
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
    } else {
      led.powerLed = false;
      digitalWrite(POWER_RELAY, LOW);
    }
  }
}