#ifndef SIMPLETCPSOCKETSERVERDEMO_H
#define SIMPLETCPSOCKETSERVERDEMO_H

#include <QObject>

//
//tcp服务端-单线程处理客户端连接
#include <QAbstractSocket>


class QTcpServer;
class SimpleTcpSocketServer : public QObject
{
    Q_OBJECT

public:
    SimpleTcpSocketServer(QObject *parent = 0);

public slots:
    void sendData();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QStringList m_oData;
    QTcpServer *m_pTcpServer;
};


#endif // SIMPLETCPSOCKETSERVERDEMO_H
