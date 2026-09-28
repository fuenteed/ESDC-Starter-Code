# Level 2 -- Morse Code Name

Blink your first name in Morse code, then repeat.

`src/main.cpp` gives you working `dot()`, `dash()`, `letterSpace()`, and
`wordSpace()` helpers with standard Morse timing already handled. Look up
your name's letters (search "morse code chart") and call the helpers in
the right order inside `loop()`, in place of the placeholder single dot.

Example: "SOS" would be
`dot(); dot(); dot(); letterSpace(); dash(); dash(); dash(); letterSpace(); dot(); dot(); dot(); wordSpace();`

## Build it

Pick your board's environment (same names as the main blinky project) and
press Build, then Upload.
