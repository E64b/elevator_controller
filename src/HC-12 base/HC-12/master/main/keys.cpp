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
			key.keyUp = false;
			key.keyDown = false;
			key.keyStateChange = true;
		}
		else if (KEY_1_VAL <= keyValue && KEY_1_VAL + TOLERANCE >= keyValue) {
			if (key.keyState1 == true) {
				key.keyState1 = false;
				key.keyStateChange = true;
			}
			else {
				key.keyState1 = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_2_VAL - TOLERANCE <= keyValue &&
			KEY_2_VAL + TOLERANCE >= keyValue) {
			if (key.keyState2 == true) {
				key.keyState2 = false;
				key.keyStateChange = true;
			}
			else {
				key.keyState2 = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_3_VAL - TOLERANCE <= keyValue &&
			KEY_3_VAL + TOLERANCE >= keyValue) {
			if (key.keyState3 == true) {
				key.keyState3 = false;
				key.keyStateChange = true;
			}
			else {
				key.keyState3 = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_4_VAL - TOLERANCE <= keyValue &&
			KEY_4_VAL + TOLERANCE >= keyValue) {
			if (key.keyState4 == true) {
				key.keyState4 = false;
				key.keyStateChange = true;
			}
			else {
				key.keyState4 = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_5_VAL - TOLERANCE <= keyValue &&
			KEY_5_VAL + TOLERANCE >= keyValue) {
			if (key.keyState5 == true) {
				key.keyState5 = false;
				key.keyStateChange = true;
			}
			else {
				key.keyState5 = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_6_VAL - TOLERANCE <= keyValue &&
			KEY_6_VAL + TOLERANCE >= keyValue) {
			if (key.keyState6 == true) {
				key.keyState6 = false;
				key.keyStateChange = true;
			}
			else {
				key.keyState6 = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_7_VAL - TOLERANCE <= keyValue &&
			KEY_7_VAL + TOLERANCE >= keyValue) {
			if (key.keyState7 == true) {
				key.keyState7 = false;
				key.keyStateChange = true;
			}
			else {
				key.keyState7 = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_8_VAL - TOLERANCE <= keyValue &&
			KEY_8_VAL + TOLERANCE >= keyValue) {
			if (key.keyState8 == true) {
				key.keyState8 = false;
				key.keyStateChange = true;
			}
			else {
				key.keyState8 = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_9_VAL - TOLERANCE <= keyValue &&
			KEY_9_VAL + TOLERANCE >= keyValue) {
			if (key.keyUp == false) {
				key.keyUp = true;
			}
		}
		else if (KEY_10_VAL - TOLERANCE <= keyValue &&
			KEY_10_VAL + TOLERANCE >= keyValue) {
			if (key.keyWork == false) {
				key.keyWork = true;
				key.keyStateChange = true;
			}
			else {
				key.keyWork = false;
				key.keyStateChange = true;
			}
		}
		else if (KEY_11_VAL - TOLERANCE <= keyValue &&
			KEY_11_VAL + TOLERANCE >= keyValue) {
			if (key.keyDown == false) {
				key.keyDown = true;
				key.keyStateChange = true;
			}
		}
		else if (KEY_12_VAL - TOLERANCE <= keyValue &&
			KEY_12_VAL + TOLERANCE >= keyValue) {
			if (key.keyMode == false) {
				key.keyMode = true;
			}
			else {
				key.keyMode = false;
				key.keyStateChange = true;
			}
		}
	}
}