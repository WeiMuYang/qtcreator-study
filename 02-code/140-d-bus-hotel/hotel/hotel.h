#ifndef HOTEL_H
#define HOTEL_H

#include <QObject>
#include <QReadWriteLock>

#define MAX_ROOMS       10

class Hotel : public QObject
{
    Q_OBJECT
    // 定义Interface名称为"com.test.hotel.registry"
    Q_CLASSINFO("D-Bus Interface", "com.test.hotel.registry")

public:
    Hotel() { m_rooms = MAX_ROOMS; }

public slots:
    // Check in，参数为房间数，返回成功拿到的房间数
    int checkIn(int num_room);
    // Check out，参数为房间数，返回成功退回的房间数
    int checkOut(int num_room);
    // Query，用于查询目前还剩下的房间数
    int query();

private:
    int m_rooms;
    QReadWriteLock m_lock;
};

#endif // HOTEL_H
