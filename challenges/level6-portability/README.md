# Level 6 -- Portability

Port the Level 5 bare-metal blink from an F4 board to the F103 Blue Pill.

`src/f4_main.c` is a complete, working bare-metal blink for the Black
Pill F411CE -- read it first. `src/f1_main.c` is your porting target for
the Blue Pill; it has a register-map comparison table and `TODO` steps at
the top.

The short version of why this isn't just a copy-paste: the F1 series
doesn't have the MODER/OTYPER-style GPIO registers the F4/L4 parts use.
Pin configuration lives in 4-bit fields inside `CRL`/`CRH` instead, and
the clock-enable bit is in a different RCC register entirely
(`APB2ENR`, not `AHB1ENR`). `ODR`/`BSRR` (actually toggling the pin) work
the same way on both.

Reference manuals, if you want the full register tables:
- F4: RM0383 / RM0390 (pick the one matching your exact chip) -- GPIO chapter.
- F1: RM0008 -- GPIO chapter, specifically the CRL/CRH description.

## Build it

Two environments here: `blackpill_f411_stlink` (the reference, already
working) and `bluepill` (your target). Build/Upload each independently.
