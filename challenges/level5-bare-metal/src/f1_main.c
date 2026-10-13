// Challenge Level 5 -- Bare-metal blinky (Blue Pill, STM32F103C8)
//
// No framework calls and no device header -- just raw register addresses
// from the reference manual. Every address and bit number you need is
// already #defined below; your job is to set, clear, and flip the right
// bits. The LED is on PC13.
//
// Note for this board specifically: the F1 series has a different GPIO
// register layout than F4/L4 -- there's no MODER register. Instead, each
// pin's mode+speed lives in 4-bit fields inside CRL (pins 0-7) or CRH
// (pins 8-15). PC13 is in CRH. Each field is laid out as
// [CNF1 CNF0 MODE1 MODE0]:
//   MODE: 00 = input, 01 = output 10 MHz,
//         10 = output 2 MHz, 11 = output 50 MHz
//   CNF (when MODE is an output):
//         00 = push-pull, 01 = open-drain,
//         10/11 = alternate function (not needed here)
// The value you want (push-pull output, 2 MHz = 0010) is already defined
// below as CRH_OUTPUT_PP_2MHZ.
//
// Bit-twiddling cheat sheet (you'll need these):
//   REG |=  (1u << n);          set bit n, leave every other bit alone
//   REG &= ~(1u << n);          clear bit n, leave every other bit alone
//   REG ^=  (1u << n);          flip bit n
//   REG &= ~(0xFu << s);        clear a 4-bit-wide field starting at bit s
//   REG |=  (val << s);         put val into that field (after clearing it)
// Don't write a GPIO config register with plain `=` -- that overwrites
// the setting for every other pin on the port too.
//
// TODO, in main():
//   1. Enable the clock for GPIO port C: set bit LED_RCC_BIT in
//      RCC_APB2ENR.
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to GPIOC below silently does nothing (no crash,
//      no error -- the peripheral just isn't clocked).
//   2. Make PC13 a push-pull output: in LED_CRH, clear the 4-bit field
//      at LED_CRH_SHIFT (mask CRH_FIELD_MASK), then OR in
//      CRH_OUTPUT_PP_2MHZ at that same shift. That's two lines.
//      Always clear first -- every field resets to 0100 (floating input),
//      so skipping the clear leaves a stray CNF bit set and you get the
//      wrong mode.
//   3. CHECKPOINT -- upload now, before writing any loop. The LED should
//      already be ON: it's active-low (lit when the pin is 0), and ODR
//      starts out as all 0s, so it lights the moment the pin becomes an
//      output. LED on = steps 1 and 2 are right. LED off = the bug is in
//      steps 1-2, so fix it before moving on.
//   4. In a while (1) loop, flip bit LED_PIN of LED_ODR, with a call to
//      delay() after it.

#include <stdint.h>

// A register is just a 32-bit value at a fixed address. `volatile` tells
// the compiler every read/write really has to happen (hardware is on the
// other end), so it can't cache or skip them.
#define REG32(addr) (*(volatile uint32_t *)(addr))

// ---- RCC (clock control) --------------------------------------------
// RCC base 0x40021000, APB2ENR is at offset 0x18.
#define RCC_APB2ENR REG32(0x40021018u)

// ---- GPIOC ----------------------------------------------------------
// GPIOC base 0x40011000. CRH is at offset 0x04, ODR at offset 0x0C.
#define LED_CRH REG32(0x40011004u)
#define LED_ODR REG32(0x4001100Cu)

// ---- CRH field values (4 bits per pin) ------------------------------
#define CRH_FIELD_MASK     0xFu  // 4-bit field mask
#define CRH_OUTPUT_PP_2MHZ 0x2u  // CNF=00 (push-pull), MODE=10 (2 MHz)

// ---- LED wiring: PC13 (active-low) ----------------------------------
#define LED_PIN       13u
#define LED_RCC_BIT   4u                     // IOPCEN is bit 4 of APB2ENR
#define LED_CRH_SHIFT ((LED_PIN - 8u) * 4u)  // pin n's field starts at bit (n-8)*4

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
  // Step 1: Turn on the clock for GPIO port C.
  //   Set bit LED_RCC_BIT in RCC_APB2ENR (use |= and 1u << ...).


  // Step 2: Make PC13 a push-pull output.
  //   2a. Clear the 4-bit field in LED_CRH: shift CRH_FIELD_MASK left by
  //       LED_CRH_SHIFT, invert it with ~, and &= it in.
  //   2b. Set the field to output: shift CRH_OUTPUT_PP_2MHZ left by
  //       LED_CRH_SHIFT and |= it in.


  // Step 3: CHECKPOINT -- build and upload now. The LED should already
  //   be ON (it's active-low). LED off? The bug is in steps 1-2. Fix it
  //   before going on.

  while (1) {
    // Step 4: Flip bit LED_PIN in LED_ODR (use ^= and 1u << ...).


    // Step 5: Wait a bit so you can see the blink: delay(1000000);

  }
}
