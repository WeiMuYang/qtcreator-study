#include "simple_tcp_socket_client_demo.h"

#include <QTcpSocket>
#include <QDebug>
#include <QTime>

SimpleTcpSocketClient::SimpleTcpSocketClient(QObject *parent) : QObject(parent)
{
    // 1. 创建TCP套接字对象
    m_pTcpSocket = new QTcpSocket(this);
    // 2. 如果连接成功，调用SimpleTcpSocketClient::connected槽函数
    connect(m_pTcpSocket, &QTcpSocket::connected, this, &SimpleTcpSocketClient::connected);
    // 3. 如果监听到有数据，调用SimpleTcpSocketClient::readyRead槽函数
    connect(m_pTcpSocket, &QIODevice::readyRead, this,  &SimpleTcpSocketClient::readyRead);
    typedef void (QAbstractSocket::*QAbstractSocketErrorSignal)(QAbstractSocket::SocketError);
    // 4. 如果有错误，调用调用SimpleTcpSocketClient::error槽函数
    connect(m_pTcpSocket, static_cast<QAbstractSocketErrorSignal>(&QTcpSocket::error), this, &SimpleTcpSocketClient::error);
    // 5. 与服务器端建立连接
    m_pTcpSocket->connectToHost("192.168.1.7", 8888);
    // 6. 同步处理，等待数据可读，
    //    利用waitForReadyRead()函数阻塞进程，等待数据，函数默认参数为等待时长=30000ms，超时返回false
    m_pTcpSocket->waitForReadyRead();
}

void SimpleTcpSocketClient::readyRead()
{
    qDebug() << "SimpleTcpSocketClientDemo::readyRead " << m_pTcpSocket->readAll();
}

void SimpleTcpSocketClient::connected()
{
    qDebug() << "SimpleTcpSocketClientDemo::connected  successfully";
}

void SimpleTcpSocketClient::error(QAbstractSocket::SocketError socketError)
{
    qDebug() << "SimpleTcpSocketClientDemo::error " << socketError;
}

/**
 * @brief 客户端线程的操作：只是创建客户端的对象建立连接
 */
void ClientRunnable::run()
{
    //这样写会内存泄漏，如此写方便测试。
    SimpleTcpSocketClient* pSimpleTcpSocketClient = new SimpleTcpSocketClient;
}









