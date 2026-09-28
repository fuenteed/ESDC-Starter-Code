// Challenge Level 3 -- Button Speed
//
// USER_BTN is defined by the STM32duino core for boards that have a
// dedicated user button (Nucleo's blue "B1" button, Black Pill's "K1").
// It's wired active-LOW: digitalRead(USER_BTN) reads LOW while pressed,
// HIGH while released. That's why we use INPUT_PULLUP below.
//
// Right now the LED blinks at a single fixed speed and ignores the
// button entirely.
//
// TODO: read USER_BTN in loop() and use a shorter BLINK_INTERVAL_MS while
// it's held down, going back to the normal speed when it's released.

#include <Arduino.h>

const unsigned long BLINK_INTERVAL_MS = 500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(USER_BTN, INPUT_PULLUP);
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(BLINK_INTERVAL_MS);
}
