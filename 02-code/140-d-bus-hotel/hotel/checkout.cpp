#include <QtCore>
#include <QtDBus>

#include "hotel.h"

int main(int argc, char *argv[])
{
        if (argc > 2) {
                fprintf(stderr, "Usage: %s [num_room]\n", argv[0]);
                exit(1);
        }

        QDBusMessage m = QDBusMessage::createMethodCall("com.test.hotel",
                                                      "/hotel/registry",
                                                      "com.test.hotel.registry",
                                                      "checkOut");

        if (argc == 2) {
                m << QString(argv[1]).toInt();
        }

        QDBusMessage response = QDBusConnection::sessionBus().call(m);
        if (response.type() == QDBusMessage::ReplyMessage) {
                int num_room = response.arguments().takeFirst().toInt();
                printf("Return %d %s\n", num_room, (num_room > 1) ? "rooms" : "room");
        } else {
                fprintf(stderr, "Check Out fail!\n");
        }

        return 0;
}
