#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
/////
/// 服务器端
/// 用于接收客户端连接和通信



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ptcpSocket_correspond = NULL;

    m_ptcpServer_monitor = new QTcpServer(this);
    // 1. 设置监听的主机IP和端口号
    m_ptcpServer_monitor->listen(QHostAddress::Any, 6666);

    // 2. 主机接收到新连接:每次新连接可用时，都会发出此信号。
    connect(m_ptcpServer_monitor, &QTcpServer::newConnection, this, createConnect);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// 1. 创建连接
void MainWindow::createConnect()
{
    // 1.1 取出连接建立后的套接字
    m_ptcpSocket_correspond = m_ptcpServer_monitor->nextPendingConnection();
    qDebug() << m_ptcpSocket_correspond;
    // 1.2 从套接字获取对方的IP和端口
    QString ip = m_ptcpSocket_correspond->peerAddress().toString();
    qint16 port = m_ptcpSocket_correspond->peerPort();
    QString temp = QString("[%1：%2]:成功连接").arg(ip).arg(port);
    ui->textEditReceive->setText(temp);
    // 1.3 通过套接字，进行监听新建立的连接
    connect(m_ptcpSocket_correspond, &QTcpSocket::readyRead, this, tcpCommunicate);
    // 1.4 若套接字断开连接，显示提示信息
    connect(m_ptcpSocket_correspond, &QTcpSocket::disconnected, this, ClientDisconnected);
}
// 2. 读取接收缓冲区内容
void MainWindow::tcpCommunicate()
{
    // 2.1 从通讯套接字中取出内容
    QByteArray array = m_ptcpSocket_correspond->readAll();
    // 2.2 使用settext可以将以前的进行覆盖，使用append会在后面添加
    ui->textEditReceive->append(array);
}
// 3. 发送按钮的单击事件
void MainWindow::on_pbnSend_clicked()
{
    // 3.1 若未建立连接，返回， 服务器用判空
    if(NULL == m_ptcpSocket_correspond)   {
        ui->textEditReceive->append("连接未建立，发送失败！");
        return;
    }
    // 3.2 获取编辑区内容
    QString str = ui->textEditWrite->toPlainText();
    // 3.3 给对方发送数据，使用套接字是tcpSocket
    m_ptcpSocket_correspond->write( str.toUtf8().data());
}
// 4. 关闭连接按钮单击事件
void MainWindow::on_pbnClose_clicked()
{
    // 4.1 若未建立连接，返回
    if(NULL == m_ptcpSocket_correspond)   {
        ui->textEditReceive->append("连接未建立，不用关闭！");
        return;
    }
    //4.2 主动和客户端断开连接
    // 4.2.1 发送完未发送信息，暂时关闭，保留之间的端口信息
    m_ptcpSocket_correspond->disconnectFromHost();
    // 4.2.2 关闭，重置Ip和端口
    // m_ptcpSocket_correspond->close();
    m_ptcpSocket_correspond = NULL;
}
// 5. 若连接断开，界面提示
void MainWindow::ClientDisconnected()
{
//    if(NULL == m_ptcpSocket_correspond)   {
//        ui->textEditReceive->append("已经挂断，不用再次挂断！");
//        return;
//    }
//    QString ip = m_ptcpSocket_correspond->peerAddress().toString();
//    qint16 port = m_ptcpSocket_correspond->peerPort();
//    QString temp = QString("[%1：%2]:已经成功挂断 **").arg(ip).arg(port);
//    //
        ui->textEditReceive->append("**连接已关闭**"  );
        m_ptcpSocket_correspond = NULL;
//    // 当线程结束时，该对象将被销毁。
//    m_ptcpSocket_correspond->deleteLater();
}
