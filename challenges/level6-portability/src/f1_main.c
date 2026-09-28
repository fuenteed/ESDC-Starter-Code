// Challenge Level 6 -- Portability (target: Blue Pill, bare-metal)
//
// Port f4_main.c's blink to the Blue Pill. Same LED pin number (PC13),
// completely different GPIO register layout:
//
//   F4 (f4_main.c)         F1 (this file)
//   ----------------       ----------------
//   RCC->AHB1ENR           RCC->APB2ENR
//   RCC_AHB1ENR_GPIOCEN     RCC_APB2ENR_IOPCEN
//   GPIOC->MODER            GPIOC->CRH (pin 13 is in CRH, not CRL)
//   GPIOC->ODR / BSRR       GPIOC->ODR / BSRR (same names, same idea)
//
// The F1 reference manual (RM0008) section on GPIO explains the CRL/CRH
// 4-bit-per-pin MODE/CNF layout -- that's the section you want for step 2.
//
// TODO:
//   1. Enable GPIOC's clock via RCC->APB2ENR.
//   2. Configure pin 13 in GPIOC->CRH as a push-pull output, low speed.
//   3. Toggle the pin in a loop, same as the F4 version.

#include "stm32f1xx.h"

int main(void) {
  // TODO: port the logic from f4_main.c using the register map above.
  while (1) {
  }
}
