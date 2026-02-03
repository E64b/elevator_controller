#include "main.h"

void autoMode() {
  if (key.keyMode) {
    if (key.keyUp) {
      key.autoMode = true;
    } else if (key.keyStateChange || millis() - AUTO_MODE_TIMER >=
                    key.autoMode) {
      key.autoMode = false;
    }
    if (key.keyDown) {
      key.autoMode = true;
    } else if (key.keyStateChange || millis() - AUTO_MODE_TIMER >=
                    key.autoMode) {
      key.autoMode = false;
    }
  }
}