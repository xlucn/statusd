Very basic and **personal** status daemon and client for dwm and tmux. If you are interested, you can modify to your needs (currently it's not designed for general use).

Feature:
- Support the click and color patches in my dwm build.
- Every block runs on their own thread, so no blocking.
- All written with pure python, without (so faster than) external shell scripts.
- Status updates instantaneously to actions (using the client script `statusc`).

Requirements:
- Linux. A lot of the status info depends on a Linux file system.
- Status text programs (optional):
  - dwm
  - tmux
- Notification daemon:
  - dunst
- Email:
  - pass for password
- Python modules:
  - python-xlib for dwm status bar
  - python-pyalsa for ALSA
  - python-mpd2 for Mpd
  - dbus-python for Dunst and showing notification

Current blocks/segments:
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

Look at the initialization code to see how it is setup.
