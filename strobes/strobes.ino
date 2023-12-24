// K'Tinga Lighting - ATTiny85 Pinout

/*
 * Strobe lights
 */

int seedPIN = 1;  //Not connected
int strobeLED1 = 3;
int strobeLED2 = 4;
unsigned long strobeStart;
unsigned long strobeEnd;
long strobeOn = 0.05 * 1000;
long strobeOff = 0.55 * 1000;
int strobeValue = HIGH;

void setup() {
    strobeStart = millis();
    strobeEnd = strobeStart + strobeOn;
    pinMode(strobeLED1, OUTPUT);
    pinMode(strobeLED2, OUTPUT);
}

void loop() {

  unsigned long now = millis();
   
   // Blink the Strobe Lights
  if ( now < strobeEnd ) {
    digitalWrite(strobeLED1, strobeValue);   
    digitalWrite(strobeLED2, strobeValue);   
  } else {
    strobeStart = millis();
    if ( strobeValue == HIGH ) {
      strobeEnd = strobeStart + strobeOff;
      strobeValue = LOW;
    } else {
      strobeValue = HIGH;
      strobeEnd = strobeStart + strobeOn;
    }
  }
}
