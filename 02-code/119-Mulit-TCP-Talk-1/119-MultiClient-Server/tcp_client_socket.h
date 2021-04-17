#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <iostream>
#include <string>
using namespace std;

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QTcpSocket *parent = nullptr);

protected slots:
    void recvData();  //处理readyRead信号读取数据
    void slotClientDisconneceted();  //客户端断开触发disconnected,处理这个信号

signals:
    void clientSocketToServer(QString msg, int Descriptor);  //用来告诉tcpserver需要更新界面
    void clientDisconnected(int Descriptor);   //告诉server有客户端断开

private:
    int strSize;
};

#endif // TCPCLIENTSOCKET_H
