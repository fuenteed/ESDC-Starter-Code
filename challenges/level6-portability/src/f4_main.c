// Challenge Level 6 -- Portability (reference: Black Pill F411CE, bare-metal)
//
// This is a complete, working bare-metal blink for the Black Pill's LED
// on PC13 -- this is the code you're porting to the Blue Pill in
// f1_main.c. You shouldn't need to change anything in this file.

#include "stm32f4xx.h"

static void delay(volatile uint32_t count) {
  while (count--) {
  }
}

int main(void) {
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

  // PC13: clear then set the 2-bit mode field to "01" (general-purpose output).
  GPIOC->MODER &= ~(0x3u << (13 * 2));
  GPIOC->MODER |= (0x1u << (13 * 2));

  while (1) {
    GPIOC->ODR ^= (1u << 13);
    delay(1000000);
  }
}
