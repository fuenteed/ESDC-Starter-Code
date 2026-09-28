# Level 4 -- STM32Cube HAL Rewrite

Rewrite blinky from scratch using ST's STM32Cube HAL library directly --
no Arduino framework this time.

`src/main.c` currently just spins forever and does nothing. `LED_PORT`,
`LED_PIN`, and `LED_CLK_ENABLE` are already defined for your board by
`platformio.ini`, so the same file works for everyone -- follow the
numbered `TODO` steps in the file to fill in `main()`.

This is the same LED, same pin, same board as blinky -- just talking to
the hardware through HAL calls (`HAL_GPIO_Init`, `HAL_GPIO_TogglePin`,
`HAL_Delay`, ...) instead of Arduino's `pinMode`/`digitalWrite`/`delay`.

## Build it

Pick your board's environment and press Build, then Upload.
