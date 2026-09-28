// Challenge Level 2 -- Blink your name in Morse code
//
// The dot()/dash()/letterSpace()/wordSpace() helpers below already handle
// standard Morse timing for you (a dash is 3x as long as a dot, etc).
//
// TODO: call dot()/dash() in the pattern that spells YOUR name, with a
// letterSpace() between letters and a wordSpace() at the end before it
// repeats. Look up your name's letters at a Morse code chart (e.g. search
// "morse code chart") -- there isn't one built into this file on purpose.
//
// The placeholder loop() below just blinks a single dot repeatedly so the
// board does something out of the box -- replace it with your name.

#include <Arduino.h>

// One Morse "unit", in milliseconds. A dot is 1 unit on, a dash is 3.
const unsigned long UNIT_MS = 200;

void dot() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // on
  delay(UNIT_MS);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // off
  delay(UNIT_MS); // gap between symbols within a letter
}

void dash() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // on
  delay(UNIT_MS * 3);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // off
  delay(UNIT_MS); // gap between symbols within a letter
}

void letterSpace() {
  delay(UNIT_MS * 2); // total gap between letters is 3 units
}

void wordSpace() {
  delay(UNIT_MS * 6); // total gap between words is 7 units
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // TODO: replace this placeholder with your name.
  dot();
  wordSpace();
}
