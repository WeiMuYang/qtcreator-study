#include <QtCore>
#include <QtDBus>

#include "hotel.h"
#include "hotelInterface.h"

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

        com::test::hotel::registry myHotel("com.test.hotel", "/hotel/registry", QDBusConnection::sessionBus());

        QDBusPendingReply<int> reply = myHotel.checkOut(num_room);
        reply.waitForFinished();
        if (reply.isValid()) {
                num_room = reply.value();
                printf("Return %d %s\n", num_room, (num_room > 1) ? "rooms" : "room");
        } else {
                fprintf(stderr, "Check Out fail!\n");
        }

        return 0;
}
