# Level 1 -- Heartbeat

Starting point: a plain blink, one LED toggle every 500 ms.

**Your task:** change the timing so the LED blinks like a heartbeat --
two quick pulses, then a longer pause, repeating -- instead of a steady
on/off. There's no single right answer; get something that reads as a
heartbeat to a human watching it.

Open `src/main.cpp` and look for the `TODO` comment.

## Ideas

- Use several different `delay()` values in a row instead of one constant.
- Try a small array of on/off durations and loop through it with an index.

## Build it

Pick your board's environment (same names as the main blinky project) and
press Build, then Upload.
