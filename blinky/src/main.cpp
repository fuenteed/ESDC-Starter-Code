// ESDC Embedded Programming Group -- Starter Blinky
//
// Blinks the board's built-in LED. See the top-level README for what to
// do with this file (short version: pick your environment, Build, Upload).

#include <Arduino.h>

// How long the LED stays in each state, in milliseconds.
const unsigned long BLINK_INTERVAL_MS = 500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // We TOGGLE the pin (read it, then write the opposite) instead of
  // writing HIGH/LOW directly. Nucleo LEDs are active-high, but the
  // Blue Pill and Black Pill LEDs are active-low -- toggling makes this
  // same code blink correctly on every board, regardless of polarity.
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(BLINK_INTERVAL_MS);
}
