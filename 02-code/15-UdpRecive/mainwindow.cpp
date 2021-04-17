#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
// 1. 该文件用于获取本机的IP
#include <QNetworkInterface>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 2. 创建UdpSocket对象，不创建的话，会因为空指针报错
    uSocket = new QUdpSocket();

    qDebug() << getHostIpAddress();

    // 3. 绑定自己的IP地址和给定的端口号
    uSocket->bind(QHostAddress(getHostIpAddress()), 8000);

    // 4. 通过信号槽机制时刻监听，是否有发来的信息，若有的话，调用receive()
    connect(uSocket, SIGNAL(readyRead()), this, SLOT(receive()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::receive()
{
    QByteArray ba;
    // 5. 如果至少有一个数据报等待读取，则返回true；否则返回false。
    while(uSocket->hasPendingDatagrams())
    {
        // 6. 设置数组的大小，并初始化每个字节的数据字节
        ba.resize(uSocket->pendingDatagramSize());
        // 7. 在ba.data()中存储接收到的不大于ba.size()字节的数据报。
        uSocket->readDatagram(ba.data(), ba.size());
        qDebug() <<  ba.data() ;
        // 8. 将接收到的数据包，显示在标签中
        ui->textEdit->setText(ba.data());
    }
}


// 获取本机的IP地址
QString MainWindow::getHostIpAddress()
{
    QString strIpAddress;
    // 1. 获取IP地址列表
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // 2. 获取第一个本主机的IP地址
    int nListSize = ipAddressesList.size();
    for (int i = 0; i < nListSize; ++i)
    {
        // 3. toIPv4Address() 是获取IPv4 ，toIPv6Address() 是获取IPv6
           if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
               ipAddressesList.at(i).toIPv4Address()) {
               strIpAddress = ipAddressesList.at(i).toString();
               // 4. break去掉是获取局域网的IP，不去掉是获取互联网的IP
               // break;
           }
     }
     // 4. 如果没有找到，则以本地IP地址为IP
     if (strIpAddress.isEmpty())
        strIpAddress = QHostAddress(QHostAddress::LocalHost).toString();
     
     return strIpAddress;
}

