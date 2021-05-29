#include <QtCore>
#include <QtDBus>
#include <QReadLocker>
#include <QWriteLocker>

#include "hotel.h"
#include "hotelAdaptor.h"

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

    QDBusConnection bus = QDBusConnection::sessionBus();

    Hotel myHotel;
    // RegistryAdaptor是qdbusxml2cpp生成的Adaptor类
    RegistryAdaptor myAdaptor(&myHotel);

    if (!bus.registerService("com.test.hotel")) {
            qDebug() << bus.lastError().message();
            exit(1);
    }

    bus.registerObject("/hotel/registry", &myHotel);

    return a.exec();
}
