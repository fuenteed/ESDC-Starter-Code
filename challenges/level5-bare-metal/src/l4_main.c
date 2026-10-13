// Challenge Level 5 -- Bare-metal blinky (Nucleo-L476RG)
//
// No framework calls and no device header -- just raw register addresses
// from the reference manual. Every address and bit number you need is
// already #defined below; your job is to set, clear, and flip the right
// bits. The LED is on PA5.
//
// Note for this board specifically: L4 parts gate GPIO clocks through
// AHB2ENR, not AHB1ENR like the F4 boards in this same challenge.
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
//   1. Enable the clock for GPIOA: set bit LED_RCC_BIT in RCC_AHB2ENR.
//      This is the classic first bug on this exercise: forget it, and
//      every read/write to GPIOA below silently does nothing (no crash,
//      no error -- the peripheral just isn't clocked).
//   2. Make the LED pin a general-purpose output: in LED_MODER, clear the
//      2-bit field at LED_MODER_SHIFT (mask MODER_MASK), then OR in
//      MODER_OUTPUT at that same shift. That's two lines.
//      Clearing first really matters on L4: pins come out of reset as
//      "11" (analog mode), so just OR-ing in 01 leaves the field at 11
//      and the LED never lights.
//   3. CHECKPOINT -- upload now, before writing any loop: add one line
//      that flips bit LED_PIN in LED_ODR. This LED is active-high (lit
//      when the pin is 1) and ODR starts out as all 0s, so one flip
//      should turn it ON. LED on = steps 1 and 2 are right. LED off = the
//      bug is in steps 1-2, so fix it before moving on.
//   4. Put that flip inside a while (1) loop, with a call to delay()
//      after it.

#include <stdint.h>

// A register is just a 32-bit value at a fixed address. `volatile` tells
// the compiler every read/write really has to happen (hardware is on the
// other end), so it can't cache or skip them.
#define REG32(addr) (*(volatile uint32_t *)(addr))

// ---- RCC (clock control) --------------------------------------------
// RCC base 0x40021000, AHB2ENR is at offset 0x4C.
#define RCC_AHB2ENR REG32(0x4002104Cu)

// ---- GPIOA ----------------------------------------------------------
// GPIOA base 0x48000000. MODER is at offset 0x00, ODR at offset 0x14.
#define LED_MODER REG32(0x48000000u)
#define LED_ODR   REG32(0x48000014u)

// ---- MODER field values (2 bits per pin) ----------------------------
#define MODER_MASK   0x3u  // 2-bit field mask
#define MODER_OUTPUT 0x1u  // 01 = general-purpose output

// ---- LED wiring: user LED LD2 on PA5 (active-high) ------------------
#define LED_PIN         5u
#define LED_RCC_BIT     0u               // GPIOAEN is bit 0 of AHB2ENR
#define LED_MODER_SHIFT (LED_PIN * 2u)   // pin n's field starts at bit 2n

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
  // Step 1: Turn on the clock for GPIOA.
  //   Set bit LED_RCC_BIT in RCC_AHB2ENR (use |= and 1u << ...).


  // Step 2: Make the LED pin a general-purpose output.
  //   2a. Clear the 2-bit field in LED_MODER: shift MODER_MASK left by
  //       LED_MODER_SHIFT, invert it with ~, and &= it in.
  //   2b. Set the field to output: shift MODER_OUTPUT left by
  //       LED_MODER_SHIFT and |= it in.


  // Step 3: CHECKPOINT -- add one line here that flips bit LED_PIN in
  //   LED_ODR (use ^= and 1u << ...), then build and upload. The LED
  //   should be ON. LED off? The bug is in steps 1-2. Fix it before
  //   going on.


  while (1) {
    // Step 4: Flip bit LED_PIN in LED_ODR (use ^= and 1u << ...).


    // Step 5: Wait a bit so you can see the blink: delay(1000000);

  }
}
