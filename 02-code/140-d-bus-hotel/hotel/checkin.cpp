#include <QtCore>
#include <QtDBus>

#include "hotel.h"

int main(int argc, char *argv[])
{
        if (argc > 2) {
                fprintf(stderr, "Usage: %s [num_room]\n", argv[0]);
                exit(1);
        }

        // 用来构造一个在D-Bus上传递的Message
        QDBusMessage m = QDBusMessage::createMethodCall("com.test.hotel",
                                                      "/hotel/registry",
                                                      "com.test.hotel.registry",
                                                      "checkIn");

        if (argc == 2) {
                // 给QDBusMessage增加一个参数;
                // 这是一种比较友好的写法，也可以用setArguments来实现
                m << QString(argv[1]).toInt();
        }

        // 发送Message
        QDBusMessage response = QDBusConnection::sessionBus().call(m);
        // 判断Method是否被正确返回
        if (response.type() == QDBusMessage::ReplyMessage) {
                // QDBusMessage的arguments不仅可以用来存储发送的参数，也用来存储返回值;
                // 这里取得checkIn的返回值
                int num_room = response.arguments().takeFirst().toInt();
                printf("Got %d %s\n", num_room, (num_room > 1) ? "rooms" : "room");
        } else {
                fprintf(stderr, "Check In fail!\n");
        }

        return 0;
}
