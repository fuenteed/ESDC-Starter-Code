// Challenge Level 5 -- Bare-metal blinky (F4 family)
// Boards: Nucleo-F446RE, Black Pill F411CE, Black Pill F401CC
//
// No framework calls at all -- just direct register access via the CMSIS
// device header. LED_GPIO, LED_PIN_NUM, and LED_RCC_ENABLE_BIT are set
// per-board by platformio.ini, so this file is shared by all of them.
//
// TODO, in main():
//   1. Enable the clock for the LED's GPIO port:
//        RCC->AHB1ENR |= LED_RCC_ENABLE_BIT;
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to the GPIO registers below silently does
//      nothing (no crash, no error -- the peripheral just isn't clocked).
//   2. Configure LED_PIN_NUM as a general-purpose output on LED_GPIO
//      using the MODER register -- each pin gets 2 bits there, and
//      "01" means general-purpose output.
//   3. In an infinite loop, toggle the pin via LED_GPIO->ODR (or use
//      LED_GPIO->BSRR to set/reset it without a read-modify-write), with
//      a simple busy-wait loop in between toggles for a visible blink.

#include "stm32f4xx.h"

int main(void) {
  // TODO: replace this with the steps above.
  while (1) {
  }
}
