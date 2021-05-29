#include <QtCore>
#include <QtDBus>

#include "hotelInterface.h"

int main(int argc, char *argv[])
{
        if (argc > 1) {
                fprintf(stderr, "Usage: %s\n", argv[0]);
                exit(1);
        }

        com::test::hotel::registry myHotel("com.test.hotel", "/hotel/registry", QDBusConnection::sessionBus());

        QDBusPendingReply<int> reply = myHotel.query();
        reply.waitForFinished();
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
