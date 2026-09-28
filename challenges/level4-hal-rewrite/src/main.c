// Challenge Level 4 -- Rewrite blinky using STM32Cube HAL
//
// No Arduino framework here. This is the same blink, but built directly
// on ST's HAL library. LED_PORT, LED_PIN, and LED_CLK_ENABLE are supplied
// per-board by platformio.ini, so this file doesn't need to change
// between boards.
//
// TODO, in main():
//   1. Call HAL_Init().
//   2. Call LED_CLK_ENABLE() to turn on the clock for the LED's GPIO port.
//   3. Fill in a GPIO_InitTypeDef (Pin = LED_PIN, Mode = GPIO_MODE_OUTPUT_PP,
//      Pull = GPIO_NOPULL, Speed = GPIO_SPEED_FREQ_LOW) and pass it to
//      HAL_GPIO_Init(LED_PORT, &init).
//   4. In an infinite loop, call HAL_GPIO_TogglePin(LED_PORT, LED_PIN) and
//      HAL_Delay(500).
//
// The right top-level HAL header is picked automatically below based on
// which family define the platform sets for your board.

#if defined(STM32F1)
  #include "stm32f1xx_hal.h"
#elif defined(STM32F4)
  #include "stm32f4xx_hal.h"
#elif defined(STM32L4)
  #include "stm32l4xx_hal.h"
#endif

int main(void) {
  // TODO: replace this with the steps above.
  while (1) {
  }
}
