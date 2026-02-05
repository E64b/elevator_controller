#include "main.h"

static uint32_t keysProtection = 500;
static uint32_t ADCInterrups;
static uint16_t keyValue;

uint16_t MiddleArif(uint16_t newVal) {
  static byte idx = 0;
  static uint16_t valArray[NUM_READ];
  valArray[idx] = newVal;
  if (++idx >= NUM_READ)
    idx = 0;
  uint16_t average = 0;
  for (int i = 0; i < NUM_READ; i++) {
    average += valArray[i];
  }
  return (uint16_t)average / NUM_READ;
}

void keys() {
  if (millis() - ADCInterrups > 1) {
    ADCInterrups = millis();
    keyValue = MiddleArif(analogRead(KEY_PIN));
  }

  if (millis() - keysProtection > KEY_PROTECTION) {
    keysProtection = millis();

    if (KEY_RELISED - TOLERANCE <= keyValue &&
        KEY_RELISED + TOLERANCE >= keyValue) {
      data.keyIsPress = false;
      if (!data.autoMode) {
        key.keyUp = false;
        key.keyDown = false;
      }

    } else if (KEY_1_VAL <= keyValue && KEY_1_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyState1) {
          key.keyState1 = false;
          data.keyStateChange = true;
        } else {
          key.keyState1 = true;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_2_VAL - TOLERANCE <= keyValue &&
               KEY_2_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyState2) {
          key.keyState2 = false;
          data.keyStateChange = true;
        } else {
          key.keyState2 = true;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_3_VAL - TOLERANCE <= keyValue &&
               KEY_3_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyState3) {
          key.keyState3 = false;
          data.keyStateChange = true;
        } else {
          key.keyState3 = true;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_4_VAL - TOLERANCE <= keyValue &&
               KEY_4_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyState4) {
          key.keyState4 = false;
          data.keyStateChange = true;
        } else {
          key.keyState4 = true;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_5_VAL - TOLERANCE <= keyValue &&
               KEY_5_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyState5) {
          key.keyState5 = false;
          data.keyStateChange = true;
        } else {
          key.keyState5 = true;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_6_VAL - TOLERANCE <= keyValue &&
               KEY_6_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyState6) {
          key.keyState6 = false;
          data.keyStateChange = true;
        } else {
          key.keyState6 = true;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_7_VAL - TOLERANCE <= keyValue &&
               KEY_7_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyState7) {
          key.keyState7 = false;
          data.keyStateChange = true;
        } else {
          key.keyState7 = true;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_8_VAL - TOLERANCE <= keyValue &&
               KEY_8_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyState8 == true) {
          key.keyState8 = false;
          data.keyStateChange = true;
        } else {
          key.keyState8 = true;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_9_VAL - TOLERANCE <= keyValue &&
               KEY_9_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyUp == false) {
          key.keyUp = true;
          data.keyStateChange = true;
          data.autoTimer = millis();
        }
      }
    } else if (KEY_10_VAL - TOLERANCE <= keyValue &&
               KEY_10_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyWork == false) {
          key.keyWork = true;
          data.keyStateChange = true;
        } else {
          key.keyWork = false;
          data.keyStateChange = true;
        }
      }
    } else if (KEY_11_VAL - TOLERANCE <= keyValue &&
               KEY_11_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyDown == false) {
          key.keyDown = true;
          data.keyStateChange = true;
          data.autoTimer = millis();
        }
      }
    } else if (KEY_12_VAL - TOLERANCE <= keyValue &&
               KEY_12_VAL + TOLERANCE >= keyValue) {
      data.keyIsPress = true;
      if (!data.autoMode) {
        if (key.keyMode == false) {
          key.keyMode = true;
          data.keyStateChange = true;
        } else {
          key.keyDown = false;
          key.keyUp = false;
          key.keyMode = false;
          data.keyStateChange = true;
        }
      }
    }
  }
}