// Challenge Level 5 -- Bare-metal blinky (F4 family)
// Boards: Nucleo-F446RE, Black Pill F411CE, Black Pill F401CC
//
// No framework calls and no device header -- just raw register addresses
// from the reference manual. Every address and bit number you need is
// already #defined below; your job is to set, clear, and flip the right
// bits.
//
// Bit-twiddling cheat sheet (you'll need these):
//   REG |=  (1u << n);          set bit n, leave every other bit alone
//   REG &= ~(1u << n);          clear bit n, leave every other bit alone
//   REG ^=  (1u << n);          flip bit n
//   REG &= ~(0x3u << s);        clear a 2-bit-wide field starting at bit s
//   REG |=  (0x1u << s);        put 01 into that field (after clearing it)
// Don't write a GPIO config register with plain `=` -- that overwrites
// the setting for every other pin on the port too, including PA13/PA14,
// the pins your ST-LINK uses to talk to the chip.
//
// TODO, in main():
//   1. Enable the clock for the LED's GPIO port: set bit LED_RCC_BIT in
//      RCC_AHB1ENR.
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to the GPIO registers below silently does
//      nothing (no crash, no error -- the peripheral just isn't clocked).
//   2. Make the LED pin a general-purpose output: in LED_MODER, clear the
//      2-bit field at LED_MODER_SHIFT (mask MODER_MASK), then OR in
//      MODER_OUTPUT at that same shift. That's two lines.
//      Always clear first -- skipping it happens to work on some pins
//      and silently fails on others, depending on their reset value.
//   3. CHECKPOINT -- upload now, before writing any loop:
//        - Black Pill: the LED should already be ON. Its LED is
//          active-low (lit when the pin is 0), and ODR starts out as all
//          0s, so it lights the moment the pin becomes an output.
//        - Nucleo-F446RE: the LED is active-high (lit when the pin is 1).
//          Add one line that flips bit LED_PIN in LED_ODR, and it should
//          come ON.
//      LED on = steps 1 and 2 are right. LED off = the bug is in steps
//      1-2, so fix it before moving on.
//   4. Put a flip of bit LED_PIN in LED_ODR inside a while (1) loop, with
//      a call to delay() after it.

#include <stdint.h>

// A register is just a 32-bit value at a fixed address. `volatile` tells
// the compiler every read/write really has to happen (hardware is on the
// other end), so it can't cache or skip them.
#define REG32(addr) (*(volatile uint32_t *)(addr))

// ---- RCC (clock control) --------------------------------------------
// RCC base 0x40023800, AHB1ENR is at offset 0x30.
#define RCC_AHB1ENR REG32(0x40023830u)

// ---- MODER field values (2 bits per pin) ----------------------------
#define MODER_MASK   0x3u  // 2-bit field mask
#define MODER_OUTPUT 0x1u  // 01 = general-purpose output

// ---- Per-board LED wiring -------------------------------------------
// GPIO port registers: MODER is at offset 0x00, ODR at offset 0x14.
#if defined(STM32F446xx)
// Nucleo-F446RE: user LED LD2 on PA5 (active-high).
// GPIOA base 0x40020000. GPIOAEN is bit 0 of AHB1ENR.
#define LED_MODER   REG32(0x40020000u)
#define LED_ODR     REG32(0x40020014u)
#define LED_PIN     5u
#define LED_RCC_BIT 0u
#else
// Black Pill F411CE / F401CC: LED on PC13 (active-low).
// GPIOC base 0x40020800. GPIOCEN is bit 2 of AHB1ENR.
#define LED_MODER   REG32(0x40020800u)
#define LED_ODR     REG32(0x40020814u)
#define LED_PIN     13u
#define LED_RCC_BIT 2u
#endif

// Where the LED pin's 2-bit field starts inside MODER (pin n -> bit 2n).
#define LED_MODER_SHIFT (LED_PIN * 2u)

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
  // Step 1: Turn on the clock for the LED's GPIO port.
  //   Set bit LED_RCC_BIT in RCC_AHB1ENR (use |= and 1u << ...).


  // Step 2: Make the LED pin a general-purpose output.
  //   2a. Clear the 2-bit field in LED_MODER: shift MODER_MASK left by
  //       LED_MODER_SHIFT, invert it with ~, and &= it in.
  //   2b. Set the field to output: shift MODER_OUTPUT left by
  //       LED_MODER_SHIFT and |= it in.


  // Step 3: CHECKPOINT -- build and upload now.
  //   Black Pill: the LED should already be ON (active-low).
  //   Nucleo-F446RE: first add one line here that flips bit LED_PIN in
  //   LED_ODR (use ^= and 1u << ...), then upload -- the LED should be ON.
  //   LED off? The bug is in steps 1-2. Fix it before going on.


  while (1) {
    // Step 4: Flip bit LED_PIN in LED_ODR (use ^= and 1u << ...).


    // Step 5: Wait a bit so you can see the blink: delay(1000000);

  }
}
