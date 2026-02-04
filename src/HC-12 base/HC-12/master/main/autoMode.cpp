#include "main.h"
//|| millis() - AUTO_MODE_TIMER >= data.autoTimer)
void autoMode() {
  if (key.keyMode) {
    if (data.autoMode && data.keyIsPress) {
      data.autoMode = false;
      key.keyUp=false;
      key.keyDown = false;
    } else if (key.keyUp && !data.autoMode) {
      data.autoMode = true;
      data.keyIsPress = false;
    } else if (key.keyDown && !data.autoMode) {
      data.autoMode = true;
      data.keyIsPress = false;
    }
    /*if (data.keyStateChange ||
               millis() - AUTO_MODE_TIMER >= data.autoTimer) {
      data.autoMode = false;
    }*/
  }
}