#include "server.h"
#include "tcp_client_socket.h"
#include <QHostAddress>
#include <QDebug>

Server::Server(int port, QTcpServer *parent) : QTcpServer(parent)
{
    listen(QHostAddress::Any, port);   //监听
}


void Server::incomingConnection(qintptr socketDescriptor)
{
    // 1. 只要有新连接就生成一个新的套接字
    TcpClientSocket *tcpclientsocket = new TcpClientSocket;
    // 2. 修改套接字的描述，作为在客户端套接字列表中的惟一索引
    tcpclientsocket->setSocketDescriptor(socketDescriptor);
    // 3. 将新创建的套接字加入到客户端套接字列表中
    tcpclientsocketlist.append(tcpclientsocket);
    // 4. 接收到tcpclientsocket发过来的更新界面的信号，并回复客户端
    connect(tcpclientsocket, &TcpClientSocket::clientSocketToServer, this, &Server::slotDataReply);
    // 5. 当客户端断开连接时，调用将客户端信息从客户端套接字列表删除的槽函数
    connect(tcpclientsocket, &TcpClientSocket::clientDisconnected, this, &Server::slotRemoveClientSocket);
}

/**
 * @brief               发送到客户端的槽函数
 * @param msg           收到客户端的信息
 * @param descriptor    客户端对应在客户列表中的描述：socketDescriptor
 */
void Server::slotDataReply(QString msg,int descriptor)
{
    // 1. 将这个信号发送给界面
    emit serverSigToMain(msg);
    // 2. 将收到的信息用 ## 分割
    QString userName = msg.section("##", 0, 0); // 取第一部分
    QString text = msg.section("##", 1, 1);     // 取第二部分

    // 3. 将收到的信号发送给每个客户端,从套接字列表中找到需要接收的套接字
    for(int i = 0; i < tcpclientsocketlist.count(); i++) {
        QTcpSocket *item = tcpclientsocketlist.at(i);
        if(item->socketDescriptor() == descriptor){
            QString sendInfo = userName + ", Server get your data!";
            item->write(sendInfo.toUtf8().data());
        }
    }
}

/**
 * @brief   用于删除客户端套接字列表中离开的客户端
 * @param descriptor    离开的客户端描述
 */
void Server::slotRemoveClientSocket(int descriptor)
{
    for(int i = 0; i < tcpclientsocketlist.count(); i++) {
        QTcpSocket *item = tcpclientsocketlist.at(i);
        //如果有客户端断开连接,将列表中的套接字删除
        if(item->socketDescriptor() == descriptor) {
            tcpclientsocketlist.removeAt(i);
            return;
        }
    }
    return;
}
