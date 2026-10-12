// Challenge Level 5 -- Bare-metal blinky (F4 family)
// Boards: Nucleo-F446RE, Black Pill F411CE, Black Pill F401CC
//
// No framework calls at all -- just direct register access via the CMSIS
// device header. LED_GPIO, LED_PIN_NUM, and LED_RCC_ENABLE_BIT are set
// per-board by platformio.ini, so this file is shared by all of them.
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
//   1. Enable the clock for the LED's GPIO port:
//        RCC->AHB1ENR |= LED_RCC_ENABLE_BIT;
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to the GPIO registers below silently does
//      nothing (no crash, no error -- the peripheral just isn't clocked).
//   2. Configure LED_PIN_NUM as a general-purpose output on LED_GPIO
//      using the MODER register. Each pin gets 2 bits there (pin n is
//      bits 2n+1 and 2n), and "01" means general-purpose output. That's
//      two lines: clear the pin's 2-bit field, then set it to 01.
//      Always clear first -- skipping it happens to work on some pins
//      and silently fails on others, depending on their reset value.
//   3. CHECKPOINT -- upload now, before writing any loop:
//        - Black Pill: the LED should already be ON. Its LED is
//          active-low (lit when the pin is 0), and ODR starts out as all
//          0s, so it lights the moment the pin becomes an output.
//        - Nucleo-F446RE: the LED is active-high (lit when the pin is 1).
//          Add one line that flips the LED's bit in LED_GPIO->ODR, and
//          it should come ON.
//      LED on = steps 1 and 2 are right. LED off = the bug is in steps
//      1-2, so fix it before moving on.
//   4. Put a flip of the LED's ODR bit inside a while (1) loop, with a
//      call to delay() after it.

#include "stm32f4xx.h"

// Busy-wait delay, already written for you. delay(1000000) is roughly
// half a second here; tweak to taste. The `volatile` matters: without
// it, the compiler sees a loop that computes nothing useful and deletes
// it, and your LED toggles so fast it just looks stuck on. (Until you
// call it, the build shows a "defined but not used" warning -- that's
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
