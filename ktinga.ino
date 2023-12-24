// K'Tinga Lighting - ATTiny85 Pinout

/*
 * Button-activated torpedo
 * Using https://github.com/jgillick/arduino-LEDFader
 */

#include <ButtonDebounce.h>
#include <LEDFader.h>

// Button on pin 2, torpedo LED on pin 0
ButtonDebounce button(2, 250);
LEDFader torpedo; 

int max_fade = 100;
bool launch = false;

void setup() {
}

void loop() {
 
  button.update();

  // Make sure that multiple button presses don't mess us up
  if (button.state() == LOW) { // pressed
    if (!launch) {
      torpedo = LEDFader(0);
      launch = true;
      torpedo.fade(max_fade, 2000);  // Ramp up
    }
  }

  if (launch) {
    torpedo.update();
    if (torpedo.get_value() == max_fade) {
      torpedo.set_value(255); //Flash
      delay(250);
      torpedo.set_value(0);
      launch = false;
    }
  }
}
