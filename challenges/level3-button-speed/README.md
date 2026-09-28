# Level 3 -- Button Speed

Use your board's user button to speed up the blink while it's held down.

**Not available for Blue Pill:** the Blue Pill only has a reset button, no
general-purpose user button, so there's no environment for it in this
challenge. Blue Pill folks: pair up with someone on a Nucleo or Black
Pill, or wire an external button to a spare GPIO pin if you want to try
this on your own board (not covered here).

`USER_BTN` is already defined for you by the board core, and `setup()`
already configures it as `INPUT_PULLUP` (pressed = LOW, released = HIGH).

Open `src/main.cpp` and look for the `TODO` comment.

## Build it

Pick your board's environment and press Build, then Upload.
