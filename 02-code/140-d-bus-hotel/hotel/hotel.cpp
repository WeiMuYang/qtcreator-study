#include <QtCore>
#include <QtDBus>
#include <QReadLocker>
#include <QWriteLocker>

#include "hotel.h"

int Hotel::checkIn(int num_room)
{
        QWriteLocker locker(&m_lock);

        if (m_rooms >= num_room) {
                m_rooms -= num_room;
        } else {
                num_room = m_rooms;
                m_rooms = 0;
        }

        return num_room;
}

int Hotel::checkOut(int num_room)
{
        QWriteLocker locker(&m_lock);

        m_rooms += num_room;

        if (m_rooms > MAX_ROOMS) {
                num_room -= (m_rooms - MAX_ROOMS);
                m_rooms = MAX_ROOMS;
        }

        return num_room;
}

int Hotel::query()
{
        QReadLocker locker(&m_lock);

        return m_rooms;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 用于建立到session bus的连接
    QDBusConnection bus = QDBusConnection::sessionBus();

    // 在session bus上注册名为"com.test.hotel"的service
    if (!bus.registerService("com.test.hotel")) {
            qDebug() << bus.lastError().message();
            exit(1);
    }

    Hotel my_hotel;

    // 注册名为"/hotel/registry"的object。
    // "QDBusConnection::ExportAllSlots "表示把类Hotel的所有Slot都导出为这个Object的method
    bus.registerObject("/hotel/registry", &my_hotel,
                       QDBusConnection::ExportAllSlots);

    return a.exec();
}
