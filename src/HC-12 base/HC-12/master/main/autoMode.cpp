#include "main.h"

void autoMode() {
  if (key.keyMode) {
    if (key.keyUp) {
      data.autoMode = true;
    } else if (data.keyStateChange ||
               millis() - AUTO_MODE_TIMER >= data.autoTimer) {
      data.autoMode = false;
    }
    if (key.keyDown) {
      data.autoMode = true;
    } else if (data.keyStateChange ||
               millis() - AUTO_MODE_TIMER >= data.autoTimer) {
      data.autoMode = false;
    }
  }
}