#include "multithread_tcpsocket_server_demo.h"
#include <QTcpSocket>

MultiThreadTcpSocketServerDemo::MultiThreadTcpSocketServerDemo(QTcpServer *parent) : QTcpServer(parent)
{
    //1. 初始换原始数据
    m_oData << tr("You've been leading a dog's life. Stay off the furniture.")
            << tr("You've got to think about tomorrow.")
            << tr("You will be surprised by a loud noise.")
            << tr("You will feel hungry again in another hour.")
            << tr("You might have mail.")
            << tr("You cannot kill time without injuring eternity.")
            << tr("Computers are not intelligent. They only think they are.");
}


void MultiThreadTcpSocketServerDemo::incomingConnection(qintptr handle)
{
    // 1. 获取服务端数据
    QString sWriteData = m_oData.at(qrand() % m_oData.size());
    qDebug() << "MultiThreadTcpSocketServerDemo::incomingConnection" << handle;
    // 2. 将客户端的连续信息和发送的数据传给子线程
    ServerHandleThread* pThread = new ServerHandleThread(handle, sWriteData);
    // 3. 当线程结束时，自动释放
    connect(pThread, &ServerHandleThread::finished, pThread, &ServerHandleThread::deleteLater);
    // 4. 启动线程
    pThread->start();
}



ServerHandleThread::ServerHandleThread(qintptr handle, const QString& sWriteData)
        :m_nHandle(handle), m_sWriteData(sWriteData)   {
}

void ServerHandleThread::run()
{
    // 1. 建立与客户端通信的TCP套接字
    QTcpSocket oTcpSocket;
    if (!oTcpSocket.setSocketDescriptor(m_nHandle))  {
        qDebug() << "oTcpSocket.setSocketDescriptor error";
        return;
    }

    // 2. 读取客户端的数据地址
    qDebug() << "MultiThreadTcpSocketServerDemo::readDataFromClient" << &oTcpSocket;
    // 3. 打印要向客户端写的数据
    qDebug() << "MultiThreadTcpSocketServerDemo::writeDataToClient" << m_sWriteData;
    // 4. 写入客户端
    oTcpSocket.write(m_sWriteData.toUtf8());
    // 5. 断开连接
    oTcpSocket.disconnectFromHost();
    // 6. 等待断开
    oTcpSocket.waitForDisconnected();
}



