# ESDC Embedded Programming Group -- STM32 Blinky Workshop

Starter code for the Embedded Systems Design Club's first embedded
programming meeting. The goal of the meeting: install VS Code +
PlatformIO, open this project, pick your board's environment, and get an
LED blinking on real STM32 hardware.

Everything on this branch (`main`) is what you'll work with during the
meeting. Reference solutions for the challenge ladder live on a separate
`solutions` branch -- see the bottom of this file.

## What you'll do

1. **Before the meeting:** install the tools and do a first build (no
   board needed) -- see "Homework before the meeting" below.
2. **At the meeting:** upload the unchanged starter code to your board
   to prove the toolchain works end-to-end, then work through the
   [challenge ladder](challenges/) at your own pace.

## Homework before the meeting

Please do this *before* you show up -- the very first build downloads a
full compiler toolchain and can take 10-20 minutes depending on your
internet connection.

1. Install [VS Code](https://code.visualstudio.com/).
2. Install the [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode)
   from the VS Code Extensions marketplace.
3. Clone this repository and open the `blinky/` folder in VS Code
   (PlatformIO projects are opened folder-by-folder, not as a single
   multi-project workspace).
4. In the PlatformIO sidebar (the alien head icon), open **Project
   Tasks**, expand the environment that matches your board (see the
   [board table](#board-to-environment-table) below if you're not sure
   which), and click **Build**. You do **not** need your board plugged in
   for this -- Build only compiles the code, it doesn't need hardware.
5. Wait for it to finish. The first run will download a toolchain and
   framework files; this is normal, and can look like it's stuck --
   let it run.
6. Once you see `[SUCCESS]` in the terminal output, post a screenshot in
   **TODO: [GROUP CHAT NAME]** so we know who's ready to go.

If Build fails, don't worry about it -- bring your laptop and we'll
triage it in the first few minutes of the meeting (see
[FACILITATOR.md](FACILITATOR.md) for how that's run).

## Per-OS setup notes

**Windows**
- ST-LINK (Nucleo onboard, or an external ST-LINK dongle for Blue
  Pill/Black Pill) needs the **ST-LINK USB driver**. If Windows doesn't
  recognize your ST-LINK, install the driver from
  [ST's ST-LINK driver page](https://www.st.com/en/development-tools/stsw-link009.html).
- Black Pill **DFU mode** upload needs a **WinUSB/libusb driver**
  installed via [Zadig](https://zadig.akeo.ie/) *instead of* the vendor
  DFU driver -- see "Black Pill DFU mode" below. Do this only when the
  board is actually in DFU mode (see below), or you may not see the
  right device listed in Zadig.

**Linux**
- PlatformIO needs **udev rules** so your user account can access the
  ST-LINK/DFU USB devices without `sudo`. Run:
  ```
  curl -fsSL https://raw.githubusercontent.com/platformio/platformio-core/master/platformio/assets/system/99-platformio-udev.rules -o /tmp/99-platformio-udev.rules
  sudo cp /tmp/99-platformio-udev.rules /etc/udev/rules.d/
  sudo udevadm control --reload-rules && sudo udevadm trigger
  ```
  Then unplug/replug the board. You may also need to be in the
  `plugdev` group (`sudo usermod -aG plugdev $USER`, then log out/in).

**macOS**
- No special driver setup is normally needed for ST-LINK or DFU.

## Black Pill: entering DFU mode

Some of you will upload the Black Pill via its onboard USB port using
the STM32 ROM bootloader (DFU), instead of an ST-LINK dongle. To enter
DFU mode:

1. Hold down the **BOOT0** button/jumper.
2. While still holding BOOT0, press and release **NRST** (reset).
3. Release BOOT0.
4. The board is now in DFU mode until the next reset/power cycle.

On the F411 boards specifically, this can take a couple of tries to line
up the timing -- if `pio run -t upload` (DFU environments) reports "No
DFU capable USB device available", re-do the BOOT0/reset sequence and
try again before assuming something's wrong.

## Troubleshooting

- **"ST-LINK not detected" / can't find debugger** -- check the USB
  cable (see next point), check the driver (Windows: see above), and
  try a different USB port. On Nucleos, make sure you're plugged into
  the ST-LINK USB port, not a USB port on the target MCU side (Nucleo
  boards mostly only expose the ST-LINK port, but double-check).
- **Charge-only USB cable** -- probably the single most common failure.
  If the board shows no port/device at all and drivers otherwise look
  fine, swap the cable for one you know carries data (e.g. the one you
  use to sync a phone).
- **Blue Pill: "UNEXPECTED idcode" or similar OpenOCD ID mismatch** --
  this is the clone-chip issue mentioned above. The `bluepill`
  environment already works around it (see the comment in
  `blinky/platformio.ini`); if you still see this, make sure you
  actually selected the `bluepill` environment and not a plain/generic
  one.
- **"No DFU capable USB device available"** -- the board isn't in DFU
  mode (see above), or (Windows) Zadig hasn't been pointed at the DFU
  device yet.
- **Linux: permission denied opening the ST-LINK/DFU device** -- the
  udev rules above haven't been installed/reloaded yet, or your user
  isn't in the right group; unplug/replug after fixing either.
- **First build stuck "downloading"** -- normal on a slow connection,
  this is the one-time toolchain download; this is exactly why the
  homework asks you to do this before the meeting. Give it several
  minutes before assuming it's actually stuck.

## Board-to-environment table

| Board | Chip | LED pin | LED polarity | Upload method | Environment name(s) |
|---|---|---|---|---|---|
| Nucleo-L476RG | STM32L476RG | PA5 (LD2) | Active-high | Onboard ST-LINK | `nucleo_l476rg` |
| Nucleo-F446RE | STM32F446RE | PA5 (LD2) | Active-high | Onboard ST-LINK | `nucleo_f446re` |
| Blue Pill | STM32F103C8 (genuine or CKS32/CS32/APM32 clone) | PC13 | Active-low | External ST-LINK dongle (SWD) | `bluepill` |
| Black Pill | STM32F411CE (WeAct) | PC13 | Active-low | External ST-LINK dongle, or USB DFU bootloader | `blackpill_f411_stlink`, `blackpill_f411_dfu` |
| Black Pill | STM32F401CC (WeAct) | PC13 | Active-low | External ST-LINK dongle, or USB DFU bootloader | `blackpill_f401_stlink`, `blackpill_f401_dfu` |

The starter code toggles the LED instead of writing HIGH/LOW directly,
so the active-high/active-low difference above doesn't require any code
changes -- it's included here mainly so the challenge ladder's
register-level exercises (Levels 4-6) make sense.

## Reference solutions

Completed versions of every challenge live on the `solutions` branch,
which will be shared with everyone after the meeting. Once it's shared,
you can compare your own attempt against the reference with, e.g.:

```
git diff main solutions -- challenges/level1-heartbeat
```
