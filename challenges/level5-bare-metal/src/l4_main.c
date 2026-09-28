// Challenge Level 5 -- Bare-metal blinky (Nucleo-L476RG)
//
// No framework calls at all -- just direct register access via the CMSIS
// device header. The LED is on PA5.
//
// Note for this board specifically: L4 parts gate GPIO clocks through
// AHB2ENR, not AHB1ENR like the F4 boards in this same challenge.
//
// TODO, in main():
//   1. Enable the clock for GPIOA:
//        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to GPIOA below silently does nothing (no crash,
//      no error -- the peripheral just isn't clocked).
//   2. Configure pin 5 as a general-purpose output on GPIOA using the
//      MODER register -- each pin gets 2 bits there, and "01" means
//      general-purpose output.
//   3. In an infinite loop, toggle the pin via GPIOA->ODR (or use
//      GPIOA->BSRR to set/reset it without a read-modify-write), with a
//      simple busy-wait loop in between toggles for a visible blink.

#include "stm32l4xx.h"

int main(void) {
  // TODO: replace this with the steps above.
  while (1) {
  }
}
