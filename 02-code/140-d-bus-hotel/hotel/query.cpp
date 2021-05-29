#include <QtCore>
#include <QtDBus>

#include "hotel.h"

int main(int argc, char *argv[])
{
        if (argc > 1) {
                fprintf(stderr, "Usage: %s\n", argv[0]);
                exit(1);
        }

        QDBusMessage m = QDBusMessage::createMethodCall("com.test.hotel",
                                                      "/hotel/registry",
                                                      "com.test.hotel.registry",
                                                      "query");

        QDBusMessage response = QDBusConnection::sessionBus().call(m);
        if (response.type() == QDBusMessage::ReplyMessage) {
                int remain_rooms = response.arguments().takeFirst().toInt();
                printf("There %s %d %s to be left\n",
                       (remain_rooms > 1) ? "are" : "is",
                       remain_rooms,
                       (remain_rooms > 1) ? "rooms" : "room");
        } else {
                fprintf(stderr, "Query fail!\n");
        }

        return 0;
}
