#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QObject>
#include <QList>
#include "tcp_client_socket.h"


class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(int port = 0,QTcpServer *parent = nullptr);
    // 1. 用来存放连接的用户
    QList<TcpClientSocket*> tcpclientsocketlist;

protected:
    // 2. 只要新的连接出现，自动调用这个函数
    virtual void incomingConnection(qintptr socketDescriptor);  //只要出现一个新的连接,就会自动调用这个函数

protected slots:
    // 3. 回复客户端的槽函数
    void slotDataReply(QString msg, int Descriptor);    //用来处理tcpclient发过来的信号
    // 4. 删除客户端的槽函数
    void slotRemoveClientSocket(int Descriptor);

signals:
    void serverSigToMain(QString);    //发送信号给界面, 让界面更新信息

};

#endif // SERVER_H
