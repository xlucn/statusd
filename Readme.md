Status bar update daemon and client for dwm and tmux.

![](./screenshot.png)

**NOTE:** currently it's WIP. If you are interested, you can modify to your needs.

## Features

- Mouse click support (works with patches in my dwm build)
- Status text color (works with patches in my dwm build)
- Written with pure python, so fast enough
- One thread for each block, so no blocking

## Requirements

- Linux. A lot of the status info depends on a Linux file system, e.g., cpu and battery levels.
- Supported programs with status bars:
  - dwm
  - tmux
- Notification daemon:
  - dunst
- Python modules:
  - python-xlib: dwm status bar
  - python-libtmux: tmux status text setup
  - python-pyalsa: ALSA
  - python-mpd2: Mpd
  - dbus-python: Dunst and showing notification

## Segments

- `ALSA` (Volume)
- `AMDGPU`
- `Backlight` (Screen brightness)
- `Battery`
- `CPU`
- `Date`
- `Dunst` (Notification status)
- `IMAP` (Email count)
- `Memory`
- `Mpd` (Music player daemon)
- `Network` (Wifi status, strength, speed)

## Setup

Look at the `main` function in [statusd](./statusd) for my default setup.

Example:

```py
Status([
    Memory("mem: {perc:02.0f}", interval=5),
    CPU("cpu: {perc:02.0f}, {freq:0.1f}GHz"),
    ALSA("vol[{icon}]: {vol:02.0f}",
         icons='OX',
         interval=5,
         bg=3,
         fg=0,
         buttons={
             '1': Command('amixer -q sset Master toggle'),
             '4': Command('amixer -q sset Master 4%+'),
             '5': Command('amixer -q sset Master 4%-'),
         }),
    Date("date: {date}"),
], padding=1).start()
```
