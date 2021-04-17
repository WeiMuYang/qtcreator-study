#include "tcp_client_socket.h"
#include <QDebug>

TcpClientSocket::TcpClientSocket(QTcpSocket *parent) : QTcpSocket(parent)
{
    // 1. 收到客户端发过来的数据:readyRead信号，调用recvData槽函数
    connect(this, &TcpClientSocket::readyRead, this, &TcpClientSocket::recvData);
    // 2. 收到客户端断开连接的:disconnected信号，调用slotclientdisconneceted槽函数
    connect(this, &TcpClientSocket::disconnected, this, &TcpClientSocket::slotClientDisconneceted);
}

/**
 * @brief 接收到数据并进行数据验证，然后将 数据信息和发数据的客户端 以信号的形式发出去
 */
void TcpClientSocket::recvData()
{
    // 1. 获取收到的信息
    QByteArray array = readAll();
    // 2. 利用##将信息隔开，取第一部分为用户名
    QString userName = QString(array).section("##", 0, 0);
    // 3. 获取发送数据长度 strSize
    strSize = QString(array).section("##", 1, 1).toInt();
    // 4. 获取正文内容
    QString strText = QString(array).section("##", 2, 2).toLatin1().data();
    // 5. 验证是否丢帧(这个是提前约定的验证规则)
    if(strSize != strText.size()) {
        qDebug() << "读取出错";
        return;
    }

    if(strText.size() == 0) {
        QString msg = userName;
        emit clientSocketToServer(msg, this->socketDescriptor());
    } else {
        QString msg = userName + "##" + strText.toLatin1();;
        emit clientSocketToServer(msg, this->socketDescriptor());
    }

}

/**
 * @brief 收到断开连接的信号，将断开的客户端的描述以信号形式发出去
 */
void TcpClientSocket::slotClientDisconneceted()
{
    emit clientDisconnected(this->socketDescriptor());
}
