// Challenge Level 5 -- Bare-metal blinky (Blue Pill, STM32F103C8)
//
// No framework calls at all -- just direct register access via the CMSIS
// device header. The LED is on PC13.
//
// Note for this board specifically: the F1 series has a different GPIO
// register layout than F4/L4 -- there's no MODER register. Instead, each
// pin's mode+speed lives in 4-bit fields inside CRL (pins 0-7) or CRH
// (pins 8-15). PC13 is in CRH.
//
// TODO, in main():
//   1. Enable the clock for GPIO port C:
//        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to GPIOC below silently does nothing (no crash,
//      no error -- the peripheral just isn't clocked).
//   2. Configure pin 13 as a general-purpose push-pull output at low
//      speed in GPIOC->CRH (look at the 4-bit field for pin 13's
//      MODE/CNF bits in the reference manual -- this is the main
//      difference from the F4/L4 files in this same challenge).
//   3. In an infinite loop, toggle the pin via GPIOC->ODR (or use
//      GPIOC->BSRR to set/reset it without a read-modify-write), with a
//      simple busy-wait loop in between toggles for a visible blink.

#include "stm32f1xx.h"

int main(void) {
  // TODO: replace this with the steps above.
  while (1) {
  }
}
