#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "multithread_tcpsocket_server_demo.h"

void testMultiThreadTcpSocketServerDemo();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    testMultiThreadTcpSocketServerDemo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void testMultiThreadTcpSocketServerDemo()
{
    //1. 建立服务器端套接字
    MultiThreadTcpSocketServerDemo* m_pTcpServer = new MultiThreadTcpSocketServerDemo();
    //2. 启动服务端
    if (!m_pTcpServer->listen(QHostAddress::Any, 8888))
    {
        qDebug() << "m_pTcpServer->listen() error";
    }
}
