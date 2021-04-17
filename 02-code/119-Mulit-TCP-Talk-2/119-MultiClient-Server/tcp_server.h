#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

signals:

};

#endif // TCPSERVER_H
