Very basic and **personal** status daemon and client for dwm and tmux. If you are interested, you can modify to your needs.

Feature:
- Support the click and color patches in my dwm build.
- Every block runs on their own thread, so no blocking.
- All written with pure python, without (so faster than) external shell scripts.
- Responds (update status) instantaneously to actions.

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
