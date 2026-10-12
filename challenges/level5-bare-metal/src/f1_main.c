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
// Bit-twiddling cheat sheet (you'll need these):
//   REG |=  (1u << n);          set bit n, leave every other bit alone
//   REG &= ~(1u << n);          clear bit n, leave every other bit alone
//   REG ^=  (1u << n);          flip bit n
//   REG &= ~(0xFu << (k * 4));  clear a 4-bit-wide field k
// Don't write a GPIO config register with plain `=` -- that overwrites
// the setting for every other pin on the port too.
//
// TODO, in main():
//   1. Enable the clock for GPIO port C:
//        RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to GPIOC below silently does nothing (no crash,
//      no error -- the peripheral just isn't clocked).
//   2. Configure pin 13 as a general-purpose push-pull output at low
//      speed in GPIOC->CRH. This is the main difference from the F4/L4
//      files in this same challenge.
//        - In CRH, pin n's field is 4 bits wide and starts at bit
//          (n - 8) * 4. Bits 3:0 of a field are pin 8, bits 7:4 are
//          pin 9, and so on.
//        - Each field is laid out as [CNF1 CNF0 MODE1 MODE0]:
//            MODE: 00 = input, 01 = output 10 MHz,
//                  10 = output 2 MHz, 11 = output 50 MHz
//            CNF (when MODE is an output):
//                  00 = push-pull, 01 = open-drain,
//                  10/11 = alternate function (not needed here)
//      Work out the 4-bit value you want, then it's two lines: clear the
//      pin's field, then OR in that value. Always clear first -- every
//      field resets to 0100 (floating input), so skipping the clear
//      leaves a stray CNF bit set and you get the wrong mode.
//   3. CHECKPOINT -- upload now, before writing any loop. The LED should
//      already be ON: it's active-low (lit when the pin is 0), and ODR
//      starts out as all 0s, so it lights the moment the pin becomes an
//      output. LED on = steps 1 and 2 are right. LED off = the bug is in
//      steps 1-2, so fix it before moving on.
//   4. In a while (1) loop, flip bit 13 of GPIOC->ODR, with a call to
//      delay() after it.

#include "stm32f1xx.h"

// Busy-wait delay, already written for you. delay(1000000) is roughly
// one second here; tweak to taste. The `volatile` matters: without it,
// the compiler sees a loop that computes nothing useful and deletes it,
// and your LED toggles so fast it just looks stuck on. (Until you call
// it, the build shows a "defined but not used" warning -- that's
// expected.)
static void delay(volatile uint32_t count) {
  while (count--) {
  }
}

int main(void) {
  // TODO: replace this with the steps above.
  while (1) {
  }
}
