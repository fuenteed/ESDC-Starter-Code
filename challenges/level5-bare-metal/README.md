# Level 5 -- Bare-metal Blinky

Rewrite blinky again, this time with no framework at all -- just the
peripheral registers, straight from the reference manual.

There are three starter files in `src/`, one per register-layout family
(`f4_main.c`, `l4_main.c`, `f1_main.c`); `platformio.ini` builds the right
one for whichever environment you pick, so you only need to look at the
file that matches your board.

Each file has numbered `TODO` steps: enable the GPIO port's clock, put
the LED pin into output mode, then toggle it in a loop.

**Hint:** if you build and upload and the LED just... doesn't light up,
with no error anywhere -- look very closely at the very first step.
There's a classic bug this exercise loves to hide.

## Build it

Pick your board's environment and press Build, then Upload.
