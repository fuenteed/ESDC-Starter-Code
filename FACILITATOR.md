# Facilitator Notes

Run of show for the first ESDC embedded programming meeting.

## Run of show

- **0:00-0:05 -- Demo.** Show a board blinking, briefly explain what
  PlatformIO is and why we're not using the Arduino IDE or STM32CubeIDE
  for this (consistent per-board environments, one repo, no per-person
  toolchain drift).
- **0:05-0:15 -- Triage.** Quick show of hands: who built successfully at
  home, who didn't try, who tried and hit an error. Get broken laptops
  fixed or queued up now, while the room is still calm -- see the
  **ten-minute rule** below.
- **0:15-0:25 -- Prove the toolchain.** Everyone uploads the **unchanged**
  starter blinky to their board before touching any code. This is
  deliberate: it isolates "my toolchain/board/cable doesn't work" from
  "my code doesn't work," which is a much easier thing to debug once
  people start editing.
- **0:25-0:45 -- Modifications + challenge ladder.** Once the unchanged
  blink is confirmed working, people move into the
  [challenge ladder](challenges/) at their own pace. Point beginners at
  the Nucleo-based Levels 1-3; point experienced folks at Levels 4-6.
- **0:45-0:55 -- Wrap-up.** Regroup, see who got where, mention that
  reference solutions will be shared on the `solutions` branch after the
  meeting, collect feedback on what to run next time.

Adjust timings to the room -- this is a rough 55-minute skeleton, not a
strict schedule.

## The ten-minute rule

If someone's setup is still broken after about ten minutes of
troubleshooting, stop. Hand them a **known-working laptop** (yours, or a
volunteer's) to flash their board and keep them moving with the group,
and come back to their actual laptop/toolchain issue later -- during the
challenge ladder portion, or after the meeting. Don't let one stuck
laptop stall the people around it, and don't let a facilitator disappear
into a 30-minute dependency-hell rabbit hole while the rest of the room
waits.

## Branch workflow (read this before touching either branch)

- `main` is what attendees see: starter code, challenge starters with
  `TODO`s, READMEs, this file, and CI.
- `solutions` is `main`, plus the challenge folders' `TODO`s filled in
  with working reference code. Nothing else should differ between the
  two branches.
- **Every change is made on `main` first.** Once it's committed there,
  merge `main` into `solutions` to bring the change across.
- **Never merge `solutions` into `main`.** `solutions` contains challenge
  answers; merging it into `main` would leak them into what attendees
  see before/during the meeting.
- In practice: fix a typo, add a board, tweak CI -- all of that happens
  on `main`, then `git checkout solutions && git merge main`. The only
  thing that ever originates directly on `solutions` is filling in a
  challenge's `TODO`s.

## Logistics reminders

- Confirm every attendee actually has the right cable/programmer for
  their board *before* the meeting if at all possible (Blue Pill and
  Black Pill both need an external ST-LINK dongle unless they're doing
  Black Pill DFU, in which case they need a USB-C data cable instead).
- CI builds every environment in every project on both branches, so if
  it's green before the meeting, the starter code and the reference
  solutions are both known-good going in. It does **not** verify that an
  upload actually works against real hardware -- that still needs to be
  checked by hand (see the top-level README's manual-testing note).
