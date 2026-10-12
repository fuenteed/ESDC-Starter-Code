// Challenge Level 5 -- Bare-metal blinky (Nucleo-L476RG)
//
// No framework calls at all -- just direct register access via the CMSIS
// device header. The LED is on PA5.
//
// Note for this board specifically: L4 parts gate GPIO clocks through
// AHB2ENR, not AHB1ENR like the F4 boards in this same challenge.
//
// Bit-twiddling cheat sheet (you'll need these):
//   REG |=  (1u << n);          set bit n, leave every other bit alone
//   REG &= ~(1u << n);          clear bit n, leave every other bit alone
//   REG ^=  (1u << n);          flip bit n
//   REG &= ~(0x3u << (n * 2));  clear a 2-bit-wide field n
// Don't write a GPIO config register with plain `=` -- that overwrites
// the setting for every other pin on the port too, including PA13/PA14,
// the pins your ST-LINK uses to talk to the chip.
//
// TODO, in main():
//   1. Enable the clock for GPIOA:
//        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to GPIOA below silently does nothing (no crash,
//      no error -- the peripheral just isn't clocked).
//   2. Configure pin 5 as a general-purpose output on GPIOA using the
//      MODER register. Each pin gets 2 bits there (pin n is bits 2n+1
//      and 2n), and "01" means general-purpose output. That's two lines:
//      clear the pin's 2-bit field, then set it to 01.
//      Clearing first really matters on L4: pins come out of reset as
//      "11" (analog mode), so just OR-ing in 01 leaves the field at 11
//      and the LED never lights.
//   3. CHECKPOINT -- upload now, before writing any loop: add one line
//      that flips bit 5 of GPIOA->ODR. This LED is active-high (lit when
//      the pin is 1) and ODR starts out as all 0s, so one flip should
//      turn it ON. LED on = steps 1 and 2 are right. LED off = the bug
//      is in steps 1-2, so fix it before moving on.
//   4. Put that flip inside a while (1) loop, with a call to delay()
//      after it.

#include "stm32l4xx.h"

// Busy-wait delay, already written for you. This chip starts up on a
// slow 4 MHz clock, so delay(1000000) is a fairly lazy blink -- shrink
// it if you like. The `volatile` matters: without it, the compiler sees
// a loop that computes nothing useful and deletes it, and your LED
// toggles so fast it just looks stuck on. (Until you call it, the build
// shows a "defined but not used" warning -- that's expected.)
static void delay(volatile uint32_t count) {
  while (count--) {
  }
}

int main(void) {
  // TODO: replace this with the steps above.
  while (1) {
  }
}
