#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QHostAddress>
#include <QMessageBox>

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);

    // 1. 将进入服务器的标志位置为false
    isConnectServer = false;
    // 2. 服务器的端口号
    m_n_port = 8888;
    ui->lineEditServerPort->setText(QString::number(m_n_port));
    // 3. 用于解析服务器的IP地址
    m_pHostAdd_serverIP = new QHostAddress();
    // 4. 未连接内不能发送信息
    ui->pushButtonSend->setEnabled(false);
}

TcpClient::~TcpClient()
{
    delete ui;
}

/**
 * @brief 进入或者离开的按钮单击事件，
 */
void TcpClient::on_pushButtonEnter_clicked()
{
    // 1. 首先判断这个用户是不是在服务器中
    if(isConnectServer == false) {  // 如果不在服务器中就和服务器进行连接
        QString ip = ui->lineEditServerIp->text();
        if(!m_pHostAdd_serverIP->setAddress(ip)) {   //判断IP地址是否可以被正确解析
            QMessageBox::warning(this, "错误", "IP地址不正确");
            return;
        }
        if(ui->lineEditUserName->text() == "") {
            QMessageBox::warning(this, "错误", "用户名不能为空");
            return;
        }
        m_str_userName = ui->lineEditUserName->text();
        m_tcpSocket = new QTcpSocket(this);
        // 2. 连接服务器
        m_tcpSocket->connectToHost(*m_pHostAdd_serverIP, m_n_port);
        // 3. 和服务器连接成功能会触发connected信号
        connect(m_tcpSocket, &QTcpSocket::connected, this, &TcpClient::slotconnectedsuccess);
        // 4. 接收到服务器的信息就会触发readyRead信号
        connect(m_tcpSocket, &QTcpSocket::readyRead, this, &TcpClient::slotreceive);
        // 5. 如果TCP连接状态发生改变，调用 onSocketStateChange
        connect(m_tcpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
                this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
        // 6. 将进入服务器的标志位置为true；
        isConnectServer = true;
    }else {   //如果已经进入了服务器
        QString msg = m_str_userName + ":disconnected";
        // 1. 发送断开连接的信息
        m_tcpSocket->write(msg.toUtf8().data());
        // 2. 断开连接
        m_tcpSocket->disconnectFromHost();
        isConnectServer = false;
        // 3. 离开服务器就会触发disconnected信号
        connect(m_tcpSocket, &QTcpSocket::disconnected, this, &TcpClient::slotdisconnected);
    }
}

//用来处理连接成功的信号
void TcpClient::slotconnectedsuccess()
{
    ui->textEdit->append("连接成功");
    // 进入服务器可以发送信息了
    ui->pushButtonSend->setEnabled(true);
    // 将连接服务器的按钮改为离开服务器
    ui->pushButtonEnter->setText("离开服务器");

    QString msg = m_str_userName + ": connected";
    m_tcpSocket->write(msg.toUtf8().data());
}

/**
 * @brief 收到服务器信息的槽函数
 */
void TcpClient::slotreceive()
{
    QByteArray array = m_tcpSocket->readAll();

    ui->textEdit->append(array.data());
}

/**
 * @brief TcpClient::on_pushButtonSend_clicked
 */
void TcpClient::on_pushButtonSend_clicked()
{
    if(ui->lineEditSend->text() == "")
        return;
    // 1. 获取编辑区内容
    QString str = ui->lineEditSend->text();
    // 2. 加头信息,用于校验
    qint64 textSize = str.size();
    // 3. 数据包 = 用户名 + 信息长度 + 信息内容
    QString strHead = QString("%1##%2##%3").arg(m_str_userName + ": ").arg(textSize).arg(str);
    // 4. 数据包发送
    m_tcpSocket->write(strHead.toUtf8().data());
    ui->lineEditSend->clear();
}
/**
 * @brief TcpClient::slotdisconnected
 */
void TcpClient::slotdisconnected()
{
    ui->pushButtonSend->setEnabled(false);
    ui->pushButtonEnter->setText("连接服务器");
}

///  Socket状态发生变化，状态栏的标签也发生变化
void TcpClient::onSocketStateChange(QAbstractSocket::SocketState socketState)
{//stateChange()信号槽函数
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        qDebug() << "scoket Status: Unconnected";
        break;
    case QAbstractSocket::HostLookupState:
        qDebug() << "scoket Status: HostLookup";
        break;
        // 3. Socket已开始建立连接。
    case QAbstractSocket::ConnectingState:
        qDebug() << "scoket Status: Connecting";
        break;
        // 4. Socket已经建立连接。
    case QAbstractSocket::ConnectedState:
        qDebug() <<"scoket Status: Connected";
        break;
        // 5. Socket绑定到地址和端口。
    case QAbstractSocket::BoundState:
        qDebug() <<"scoket Status: Bound IP and Port";
        break;
        // 6. Socket即将关闭（数据可能仍在等待写入）。
    case QAbstractSocket::ClosingState:
        qDebug() <<"scoket Status: Closing";
        break;
    }
}
