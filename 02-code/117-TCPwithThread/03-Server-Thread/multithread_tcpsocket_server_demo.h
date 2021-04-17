#ifndef MULTITHREADTCPSOCKETSERVERDEMO_H
#define MULTITHREADTCPSOCKETSERVERDEMO_H

/**
* Copyright (c)  2020 YWB. All rights reserved
* @projectName   03-Server-Thread
* @file          multithread_tcpsocket_server_demo.h
* @brief         服务器端-多线程处理客户端连接
* @author        Yang Weibin
* @date          2020-11-22 17:13:30
*/

#include <QObject>
#include <QTcpServer>
#include <QThread>

class MultiThreadTcpSocketServerDemo : public QTcpServer
{
    Q_OBJECT
public:
    explicit MultiThreadTcpSocketServerDemo(QTcpServer *parent = nullptr);

    // This virtual function is called by QTcpServer when a new connection is available.
    // 当新连接可用时，此虚拟函数由QTcpServer调用。
    // The socketDescriptor argument is the native socket descriptor for the accepted connection.
    // socketDescriptor参数是接受的连接的本机套接字描述符。可以根据handle获取连接信息
    virtual void incomingConnection(qintptr handle);
signals:

private:
    QStringList m_oData;
};


// 处理线程类
class ServerHandleThread : public QThread
{
    Q_OBJECT

public:
    ServerHandleThread(qintptr handle, const QString& sWriteData);

    virtual void run();
private:
    qintptr m_nHandle;
    QString m_sWriteData;
};


#endif // MULTITHREADTCPSOCKETSERVERDEMO_H
