#include "simple_tcp_socket_server_demo.h"
#include <assert.h>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>

SimpleTcpSocketServer::SimpleTcpSocketServer(QObject *parent) : QObject(parent)
{

    //0. 服务器数据初始换原始数据
    m_oData << tr("You've been leading a dog's life. Stay off the furniture.")
            << tr("You've got to think about tomorrow.")
            << tr("You will be surprised by a loud noise.")
            << tr("You will feel hungry again in another hour.")
            << tr("You might have mail.")
            << tr("You cannot kill time without injuring eternity.")
            << tr("Computers are not intelligent. They only think they are.");

    // 1. 创建TCP对象
    m_pTcpServer = new QTcpServer(this);
    // 2. 如果有新的连接调用SimpleTcpSocketServer::sendData槽函数
    connect(m_pTcpServer, &QTcpServer::newConnection, this, &SimpleTcpSocketServer::sendData);
    // 3. 如果连接有错误，直接打印连接
    connect(m_pTcpServer, &QTcpServer::acceptError, this, &SimpleTcpSocketServer::displayError);
    // 4. 启动服务端，监听电脑的IP和端口
    if (!m_pTcpServer->listen(QHostAddress::Any, 8888))  {
        qDebug() << "m_pTcpServer->listen() error";
        assert(false);
    }
}

void SimpleTcpSocketServer::sendData()  {
    // 1. 获取服务端数据：随机发一个字符串
    QString sWriteData = m_oData.at(qrand() % m_oData.size());
    // 2. 获取与客户端通信的socket
    QTcpSocket* pClientConnection = m_pTcpServer->nextPendingConnection();
    // 3. 从客户端读数据
    QString sReadData = pClientConnection->readAll();
    qDebug() << "SimpleTcpSocketServerDemo::readDataFromClient " << pClientConnection;
    // 4. 与客户端写数据
    qDebug() << "SimpleTcpSocketServerDemo::writeDataToClient " << sWriteData;
    pClientConnection->write(sWriteData.toUtf8());
    // 	//与客户端断开连接
    // 	connect(pClientConnection, &QTcpSocket::disconnected, this, &SimpleTcpSocketServerDemo::deleteLater);
    // 	pClientConnection->disconnectFromHost();
}

void SimpleTcpSocketServer::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "SimpleTcpSocketServerDemo::displayError " << socketError;
}
