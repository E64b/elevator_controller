#include "main.h"

void protection() {
  if (millis() - data.msgTime >= LOSS_MSG_TIME) {
    key.keyUp = false;
    key.keyDown = false;
    key.work = false;
  }
  data.error = true;
}