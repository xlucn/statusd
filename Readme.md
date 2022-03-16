Very basic and **personal** status daemon and client for dwm and tmux. If you are interested, you can modify to your needs (currently it's not designed for general use).

Feature:
- Support the click and color patches in my dwm build.
- Every block runs on their own thread, so no blocking.
- All written with pure python, without (so faster than) external shell scripts.
- Status updates instantaneously to actions (using the client script `statusc`).

Requirements:
- Status text programs:
  - dwm
  - tmux
- Python modules:
  - python-pyalsa
  - python-mpd2
  - python-xlib
  - dbus-python
- Notification daemon:
  - dunst
- Email unread count:
  - pass for password

Current blocks/segments:
- ALSA (Volume)
- Backlight (Screen brightness)
- Battery
- CPU
- Date
- Dunst (Notification)
- IMAP (Email)
- Memory
- Mpd (Music player daemon)
- Network

Look at the initialization code to see how it is setup.
