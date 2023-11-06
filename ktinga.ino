// K'Tinga Lighting - ATTiny85 Pinout

/*
 * Strobe lights
 * Flickering engine lights (0..255)
 */

int seedPIN = 2;  //Not connected
int strobeLED1 = 3;
int strobeLED2 = 4;
unsigned long strobeStart;
unsigned long strobeEnd;
long strobeOn = 0.15 * 1000;
long strobeOff = 2.15 * 1000;
int strobeValue = HIGH;

int engineLED1 = 0;
int engineLED2 = 1;
int baseEngineLevel = 100;
int maxEngineLevel = 255; 
int engineDelay = 1 * 1000;
unsigned long engineStart;
unsigned long engineEnd;

void setup() {
    randomSeed(analogRead(seedPIN));  // Picks up random cosmic rays to seed random()
    strobeStart = millis();
    strobeEnd = strobeStart + strobeOn;
    engineStart = millis();
    engineEnd = engineStart + engineDelay;
    pinMode(strobeLED1, OUTPUT);
    pinMode(strobeLED2, OUTPUT);
    pinMode(engineLED1, OUTPUT);
    pinMode(engineLED2, OUTPUT);
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

  // Flicker the engines
  if (now > engineEnd ) {
    int val = random(baseEngineLevel, maxEngineLevel);
    analogWrite(engineLED1, val);
    analogWrite(engineLED2, val);
    engineEnd = now + random(engineDelay*.7, engineDelay);
  } 

  
}
