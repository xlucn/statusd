Very basic and **personal** status daemon and client for dwm and tmux. If you are interested, you can modify to your needs (currently it's not designed for general use).

Feature:
- Support the click and color patches in my dwm build.
- Every block runs on their own thread, so no blocking.
- All written with pure python, without (so faster than) external shell scripts.
- Responds (update status) instantaneously to actions.

Requirements:
- Status text programs:
  - dwm
  - tmux
- Python modules:
  - python-pyalsa
  - python-mpd2
  - python-xlib
- Notification daemon:
  - dunst
- Email unread count:
  - pass for password

Current blocks/segments:
- ALSA
- Backlight
- Battery
- CPU
- Date
- Dunst
- IMAP
- Memory
- Mpd
- Network

Look at the initialization code to see how it is setup.
