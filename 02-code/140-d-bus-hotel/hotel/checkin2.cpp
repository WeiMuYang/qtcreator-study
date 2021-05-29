#include <QtCore>
#include <QtDBus>

#include "hotel.h"

int main(int argc, char *argv[])
{
        int num_room;

        if (argc > 2) {
                fprintf(stderr, "Usage: %s [num_room]\n", argv[0]);
                exit(1);
        }

        if (argc == 2) {
                num_room = QString(argv[1]).toInt();
        } else {
                num_room = 1;
        }

        // 创建QDBusInterface
        QDBusInterface iface( "com.test.hotel", "/hotel/registry",
                              "com.test.hotel.registry", QDBusConnection::sessionBus());
        if (!iface.isValid()) {
                qDebug() << qPrintable(QDBusConnection::sessionBus().lastError().message());
                exit(1);
        }

        // 呼叫远程的checkIn，参数为num_room
        QDBusReply<int> reply = iface.call("checkIn", num_room);
        if (reply.isValid()) {
                num_room = reply.value();
                printf("Got %d %s\n", num_room, (num_room > 1) ? "rooms" : "room");
        } else {
                fprintf(stderr, "Check In fail!\n");
        }

        return 0;
}
