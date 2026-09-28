// Challenge Level 1 -- Heartbeat
//
// This starts out as a plain copy of the blinky sketch. Your job is to
// change the timing so the LED blinks in a "heartbeat" pattern instead
// of a steady on/off: e.g. thump-thump ... pause ... thump-thump ... pause.
//
// TODO: replace the single BLINK_INTERVAL_MS delay below with a short
// sequence of different on/off delays that reads as a heartbeat. You can
// add more calls to digitalWrite()/delay() in loop(), or build a small
// array of durations and step through it -- your choice.

#include <Arduino.h>

const unsigned long BLINK_INTERVAL_MS = 500;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(BLINK_INTERVAL_MS);
}
