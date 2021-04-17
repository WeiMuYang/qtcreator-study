#ifndef SIMPLETCPSOCKETCLIENTDEMO_H
#define SIMPLETCPSOCKETCLIENTDEMO_H

#include <QObject>
#include <QAbstractSocket>
#include <QRunnable>
#include <QThreadPool>

class QTcpSocket;

/**
 * @brief TCP客户端的类
 */
class SimpleTcpSocketClient : public QObject
{
    Q_OBJECT
public:
    explicit SimpleTcpSocketClient(QObject *parent = nullptr);

public slots:
    void connected();
    void readyRead();
    void error(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket* m_pTcpSocket;

};

/**
 * @brief 客户端线程
 */
class ClientRunnable : public QRunnable
{
public:
    void run();
};


#endif // SIMPLETCPSOCKETCLIENTDEMO_H
