Status bar update daemon and client for dwm and tmux.

**NOTE:** currently it's WIP. If you are interested, you can modify to your needs.

## Feature

- Click and color (modified patches in my dwm build).
  - Status responses to clicks or signals.
- Written with pure python, so fast enough.
- One thread for each block, so no blocking.

Supported programs with status bars:
- dwm
- tmux

## Segments

- ALSA (Volume)
- AMDGPU
- Backlight (Screen brightness)
- Battery
- CPU
- Date
- Dunst (Notification status)
- IMAP (Email count)
- Memory
- Mpd (Music player daemon)
- Network (Wifi status, strength, speed)

## Requirements

- Linux. A lot of the status info depends on a Linux file system, e.g., cpu and battery levels.
- Notification daemon:
  - dunst
- Python modules:
  - python-xlib: dwm status bar
  - python-libtmux: tmux status text setup
  - python-pyalsa: ALSA
  - python-mpd2: Mpd
  - dbus-python: Dunst and showing notification

## Setup

Example:

```py
Status([
    Memory("mem: {perc:02.0f}", interval=5),
    CPU("cpu: {perc:02.0f}, {freq:0.1f}GHz"),
    ALSA("vol[{icon}]: {vol:02.0f}", icons='OX', interval=5),
    Date("date: {date}"),
], padding=1).start()
```

Look at the `main` function in [statusd](./statusd) to see how it is setup.
