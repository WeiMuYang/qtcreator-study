#include <QtCore>
#include <QtDBus>

#include "hotel.h"

int main(int argc, char *argv[])
{
        if (argc > 1) {
                fprintf(stderr, "Usage: %s\n", argv[0]);
                exit(1);
        }

        QDBusInterface iface( "com.test.hotel", "/hotel/registry", "com.test.hotel.registry", QDBusConnection::sessionBus());
        if (!iface.isValid()) {
                qDebug() << qPrintable(QDBusConnection::sessionBus().lastError().message());
                exit(1);
        }

        QDBusReply<int> reply = iface.call("query");
        if (reply.isValid()) {
                int remain_rooms = reply.value();
                printf("There %s %d %s to be left\n",
                       (remain_rooms > 1) ? "are" : "is",
                       remain_rooms,
                       (remain_rooms > 1) ? "rooms" : "room");
        } else {
                fprintf(stderr, "Query fail!\n");
        }

        return 0;
}
