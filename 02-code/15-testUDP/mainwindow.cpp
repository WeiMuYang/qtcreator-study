#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 1. 创建一个UdpSocket的对象，否则会有空指针报错
    udpsocket = new QUdpSocket();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 发送数据报的函数
void MainWindow::SendUDPData(){

    // 1. 获取对方的端口号和ip
    QString ip = ui->lineEditip->text();
    // 2. 获取对方的端口号，注意类型是：quint16
    quint16 port = ui->lineEditport->text().toInt();

    // 3. 获取文本框的内容，也就是要发送的内容
    QString str = ui->textEdit->toPlainText();

    // 4. 将要发送的数据转换成QByteArray 类型
    QByteArray sendByteArray = str.toUtf8();
    // 5. 将信息发送给指定的ip
    // 将sendByteArray数据报发送到端口端口的主机地址。返回成功时发送的字节数；否则返回-1。
    udpsocket->writeDatagram(sendByteArray, (QHostAddress)ip, port);
}

void MainWindow::on_pushButtonwrite_clicked()
{
    SendUDPData();
}
