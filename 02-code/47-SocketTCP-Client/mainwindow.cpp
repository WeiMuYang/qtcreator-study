#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>

/// 客户机端
/// 主动和服务器建立连接和通信

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  {
    ui->setupUi(this);

    // 1. 创建socket套接字
    m_ptcpSocket_correspond = new QTcpSocket(this);
    qDebug() << m_ptcpSocket_correspond;
    // 2. 第一次监听到时，建立连接
    connect(m_ptcpSocket_correspond, & QTcpSocket::connected, this, createConnect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 2. 建立连接，监听IP和端口号
void MainWindow::createConnect()
{
    ui->textEditReceive->setText("成功和服务器建立连接！");
    connect(m_ptcpSocket_correspond, &QTcpSocket::readyRead, this, tcpCommunicate);
}
// 3. 读取接收缓冲区内容
void MainWindow::tcpCommunicate()
{
    // 3.1 利用套接字读取缓冲区内容
    // readLine()：此函数从设备中读取一行ASCII字符，停止依据：①`\n` ② 最大长度③ 数据结束
    // QByteArray array = m_ptcpSocket_correspond->readLine();
    // readAll();：此函数从设备中读取ASCII字符，停止依据：① 最大长度 ②数据结束
    QByteArray array = m_ptcpSocket_correspond->readAll();
    //使用settext可以将以前的进行覆盖，使用append会在后面添加
    // 3.2 读取内容显示界面
    ui->textEditReceive->append(array);
}
// 4. 发送信息
void MainWindow::on_pbnSend_clicked()
{
    // 4.1 若未建立连接，直接返回，客户机用isOpen
    if(!m_ptcpSocket_correspond->isOpen()){
        ui->textEditReceive->append("连接未建立，发送失败！");
        return;
    }
    // 4.2 获取编辑区内容
    QString str = ui->textEditWrite->toPlainText();
    // 4.3 给对方发送数据，使用套接字是tcpSocket
    m_ptcpSocket_correspond->write(str.toUtf8().data());
}
// 5. 关闭连接
void MainWindow::on_pbnClose_clicked()
{
    // 5.1 若连接未建立，则不用关闭， 客户机用isOpen
    if(!m_ptcpSocket_correspond->isOpen())  {
        ui->textEditReceive->append("连接未建立，不用关闭！");
        return;
    }
    // 5.2 主动和客户端断开连接，
    m_ptcpSocket_correspond->disconnectFromHost();
    // m_ptcpSocket_correspond->close();
    ui->textEditReceive->append("已关闭连接！");

}
// 6. 连接按钮的单击事件
void MainWindow::on_pbnConnect_clicked()
{
    // 6.1 获取服务器IP和端口
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();
    // 6.2 如果涉及到再次拨号的话，需要先将之前的先挂断(很重要)
    //     然后建立新连接
    if(m_ptcpSocket_correspond->isOpen()) {
        ui->textEditReceive->append("已经挂断之前的连接！");
        m_ptcpSocket_correspond->disconnectFromHost();
        // m_ptcpSocket_correspond->close();
    }

    //6.3 主动和服务器建立连接
    m_ptcpSocket_correspond->connectToHost(QHostAddress(ip),port);

}
