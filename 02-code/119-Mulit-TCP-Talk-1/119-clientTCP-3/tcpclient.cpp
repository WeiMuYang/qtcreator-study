#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QHostAddress>
#include <QMessageBox>

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);

    //将进入服务器的标志位置为false
    status = false;
    port = 8888;
    ui->lineEditServerPort->setText(QString::number(port));

    serverIP = new QHostAddress();

    //未连接内不能发送信息
    ui->pushButtonSend->setEnabled(false);
}

TcpClient::~TcpClient()
{
    delete ui;
}

//进入服务器
void TcpClient::on_pushButtonEnter_clicked()
{
    //首先判断这个用户是不是在服务器中
    if(status == false) {  //不在服务器中就和服务器进行连接
        QString ip = ui->lineEditServerIp->text();
        if(!serverIP->setAddress(ip)) {   //判断IP地址是否可以被正确解析
            QMessageBox::warning(this, "错误", "IP地址不正确");
            return;
        }
        if(ui->lineEditUserName->text() == "") {
            QMessageBox::warning(this, "错误", "用户名不能为空");
            return;
        }
        userName = ui->lineEditUserName->text();

        tcpsocket = new QTcpSocket(this);
        tcpsocket->connectToHost(*serverIP, port);

        //和服务器连接成功能会触发connected信号
        connect(tcpsocket, &QTcpSocket::connected, this, &TcpClient::slotconnectedsuccess);

        //接收到服务器的信息就会触发readyRead信号
        connect(tcpsocket, &QTcpSocket::readyRead, this, &TcpClient::slotreceive);

        //将进入服务器的标志位置为true；
        status = true;
    }
    else {   //已经进入了服务器
        //int length = 0;
        QString msg = userName + ":disconnected";
        tcpsocket->write(msg.toUtf8().data());
        tcpsocket->disconnectFromHost();
        status = false;
        //离开服务器就会触发disconnected信号
        connect(tcpsocket, &QTcpSocket::disconnected, this, &TcpClient::slotdisconnected);
    }
}

//用来处理连接成功的信号
void TcpClient::slotconnectedsuccess()
{
    ui->textEdit->append("连接成功");

    //进入服务器可以发送信息了
    ui->pushButtonSend->setEnabled(true);
    //将连接服务器的按钮改为离开服务器
    ui->pushButtonEnter->setText("离开服务器");

    QString msg = userName + ": connected";
    tcpsocket->write(msg.toUtf8().data());
}


void TcpClient::slotreceive()
{
    QByteArray array = tcpsocket->readAll();

    ui->textEdit->append(array.data());
}

void TcpClient::on_pushButtonSend_clicked()
{
    if(ui->lineEditSend->text() == "") {
        return;
    }

    //获取编辑区内容
    QString str = ui->lineEditSend->text();

    //加头信息
    qint64 textSize = str.size();

    //userName = userName + ": ";

    QString strHead = QString("%1##%2##%3").arg(userName + ": ").arg(textSize).arg(str);

    tcpsocket->write(strHead.toUtf8().data());

    ui->lineEditSend->clear();
}

void TcpClient::slotdisconnected()
{
    ui->pushButtonSend->setEnabled(false);
    ui->pushButtonEnter->setText("连接服务器");
}
