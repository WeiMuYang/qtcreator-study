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

        // 初始化自动生成的Proxy类com::test::hotel::registry
        com::test::hotel::registry myHotel("com.test.hotel",
                                           "/hotel/registry",
                                           QDBusConnection::sessionBus());

        // 调用checkIn
        QDBusPendingReply<int> reply = myHotel.checkIn(num_room);
        // qdbusxml2cpp生成的Proxy类是采用异步的方式来传递Message，
        // 所以在此需要调用waitForFinished来等到Message执行完成
        reply.waitForFinished();
        if (reply.isValid()) {
                num_room = reply.value();
                printf("Got %d %s\n", num_room, (num_room > 1) ? "rooms" : "room");
        } else {
                fprintf(stderr, "Check In fail!\n");
        }

        return 0;
}
