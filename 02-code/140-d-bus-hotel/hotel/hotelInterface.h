/*
 * This file was generated by qdbusxml2cpp version 0.7
 * Command line was: qdbusxml2cpp com.test.hotel.registry.xml -i hotel.h -p hotelInterface
 *
 * qdbusxml2cpp is Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef HOTELINTERFACE_H_1279869444
#define HOTELINTERFACE_H_1279869444

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>
#include "hotel.h"

/*
 * Proxy class for interface com.test.hotel.registry
 */
class ComTestHotelRegistryInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "com.test.hotel.registry"; }

public:
    ComTestHotelRegistryInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~ComTestHotelRegistryInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<int> checkIn()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("checkIn"), argumentList);
    }

    inline QDBusPendingReply<int> checkIn(int num_room)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(num_room);
        return asyncCallWithArgumentList(QLatin1String("checkIn"), argumentList);
    }

    inline QDBusPendingReply<int> checkOut()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("checkOut"), argumentList);
    }

    inline QDBusPendingReply<int> checkOut(int num_room)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(num_room);
        return asyncCallWithArgumentList(QLatin1String("checkOut"), argumentList);
    }

    inline QDBusPendingReply<int> query()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("query"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace com {
  namespace test {
    namespace hotel {
      typedef ::ComTestHotelRegistryInterface registry;
    }
  }
}
#endif