#!/usr/bin/env python3
from gi.repository import GLib
import dbus
import dbus.service
import dbus.mainloop.glib


class Notification(dbus.service.Object):
    @dbus.service.method("org.freedesktop.Notifications", 'susssasa{sv}i', 'u')
    def Notify(self, app_name, notification_id, app_icon,
               summary, body, actions, hints, expire_timeout=3000):
        print(app_name)
        print(notification_id)
        # print(app_icon)
        print(summary)
        print(body)
        # print(actions)
        # print(hints)
        print(expire_timeout)
        return notification_id

    @dbus.service.method("org.freedesktop.Notifications", '', 'as')
    def GetCapabilities(self):
        return ("body")

    @dbus.service.signal('org.freedesktop.Notifications', 'uu')
    def NotificationClosed(self, id_in, reason_in):
        pass

    @dbus.service.method("org.freedesktop.Notifications", 'u', '')
    def CloseNotification(self, id):
        pass

    @dbus.service.method("org.freedesktop.Notifications", '', 'ssss')
    def GetServerInformation(self):
        return ("statnot", "http://code.k2h.se", "0.0.2", "1")


if __name__ == '__main__':
    dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
    session_bus = dbus.SessionBus()
    name = dbus.service.BusName("org.freedesktop.Notifications", session_bus)
    nf = Notification(session_bus, '/org/freedesktop/Notifications')
    print(dir(nf))

    context = GLib.MainLoop().get_context()
    while True:
        context.iteration(True)
