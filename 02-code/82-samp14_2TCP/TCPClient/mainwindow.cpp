#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>
#include <QHostInfo>

/////  客户机
///   获取本主机的IPv4的IP地址
QString MainWindow::getLocalIP()
{
    // 1. 获取本地主机的名字
    QString hostName = QHostInfo::localHostName();//本地主机名
    // 2. 根据主机名获取主机信息
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QString   localIP="";
    // 3. 获取主机的IP列表
    QList<QHostAddress> addList=hostInfo.addresses();//

    if (!addList.isEmpty())
        for (int i=0;i<addList.count();i++)
        {
            // 4. 通过循环获取主机的IP地址
            QHostAddress aHost=addList.at(i);
            if (QAbstractSocket::IPv4Protocol==aHost.protocol())
            {
                localIP=aHost.toString();
                // break;   // 注释掉break，即可得到局域网的IP地址，
                // 不注释话获取的互联网IP地址
            }
        }
    return localIP;
}
///  重写窗口关闭事件
void MainWindow::closeEvent(QCloseEvent *event)
{
    // 1. 如果连接还存在，则断开连接
    if (tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
    // 2. 事件的接收者，还需要这个事件
    event->accept();
}
///  构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 1. 创建Socket套接字
    tcpClient=new QTcpSocket(this); //创建socket变量
    // 2. 初始化状态栏标签
    LabSocketState=new QLabel("Socket状态：");//状态栏标签
    LabSocketState->setMinimumWidth(250);
    ui->statusBar->addWidget(LabSocketState);
    // 3. 获取本主机的IP
    QString localIP=getLocalIP();//本机IP
    this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);
    ui->comboServer->addItem(localIP);
    // 4. 如果建立了TCP连接，调用onConnected
    connect(tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    // 5. 如果断开了TCP连接，调用onDisconnected
    connect(tcpClient,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    // 6. 如果TCP连接状态发生改变，调用 onSocketStateChange
    connect(tcpClient,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    // 7. 如果TCP监听到数据时，调用onSocketReadyRead
    connect(tcpClient,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
///  建立连接后显示连接的信息
void MainWindow::onConnected()
{ //connected()信号槽函数
    ui->plainTextEdit->appendPlainText("**已连接到服务器");
    // 1. 如果套接字处于ConnectedState，则返回已连接对等方的地址；
    // 否则返回QHostAddress:：Null。
    ui->plainTextEdit->appendPlainText("**peer address:"+
                                       tcpClient->peerAddress().toString());
    ui->plainTextEdit->appendPlainText("**peer port:"+
                                       QString::number(tcpClient->peerPort()));
    // 2. 修改工具栏的效果
    ui->actConnect->setEnabled(false);
    ui->actDisconnect->setEnabled(true);
}
///  断开连接后显示断开的信息
void MainWindow::onDisconnected()
{//disConnected()信号槽函数
    // 1. 修改文本框
    ui->plainTextEdit->appendPlainText("**已断开与服务器的连接");
    // 2. 修改工具栏的效果
    ui->actConnect->setEnabled(true);
    ui->actDisconnect->setEnabled(false);
}
///  读取接收到的数据
void MainWindow::onSocketReadyRead()
{//readyRead()信号槽函数
    // 1. 如果可以从套接字读取一行数据；
    //   将接收到数据显示到文本框
    while(tcpClient->canReadLine())
        ui->plainTextEdit->appendPlainText("[in] "+tcpClient->readLine());
}
///  Socket状态发生变化，状态栏的标签也发生变化
void MainWindow::onSocketStateChange(QAbstractSocket::SocketState socketState)
{//stateChange()信号槽函数
    switch(socketState)
    {
    // 1. Socket未连接。
    case QAbstractSocket::UnconnectedState:
        LabSocketState->setText("scoket状态：未连接");
        break;
    // 2. Socket正在执行主机名查找。
    case QAbstractSocket::HostLookupState:
        LabSocketState->setText("scoket状态：正在执行主机名查找");
        break;
    // 3. Socket已开始建立连接。
    case QAbstractSocket::ConnectingState:
        LabSocketState->setText("scoket状态：开始建立连接");
        break;
    // 4. Socket已经建立连接。
    case QAbstractSocket::ConnectedState:
        LabSocketState->setText("scoket状态：已经建立连接");
        break;
    // 5. Socket绑定到地址和端口。
    case QAbstractSocket::BoundState:
        LabSocketState->setText("scoket状态：绑定到地址和端口");
        break;
    // 6. Socket即将关闭（数据可能仍在等待写入）。
    case QAbstractSocket::ClosingState:
        LabSocketState->setText("scoket状态：即将关闭");
        break;
    // 7. 仅供内部使用。
    case QAbstractSocket::ListeningState:
        LabSocketState->setText("scoket状态：仅供内部使用");
    }
}
///  菜单栏actConnect动作触发
void MainWindow::on_actConnect_triggered()
{//连接到服务器
    // 1. 获取服务器的IP
    QString addr=ui->comboServer->currentText();
    // 2. 获取服务器的端口号
    quint16 port=ui->spinPort->value();
    // 3. 与服务器建立连接
    tcpClient->connectToHost(addr,port);
    //    tcpClient->connectToHost(QHostAddress::LocalHost,port);
}
///  菜单栏actDisconnect动作触发
void MainWindow::on_actDisconnect_triggered()
{//断开与服务器的连接
    // 1. 尝试关闭插座。如果有挂起的数据等待写入，
    // Socket将进入ClosingState并等待所有数据都已写入。
    if (tcpClient->state()==QAbstractSocket::ConnectedState)
        tcpClient->disconnectFromHost();
}
///  菜单栏actClear动作触发
void MainWindow::on_actClear_triggered()
{
    // 1. 清空文本
    ui->plainTextEdit->clear();
}
///  发送按钮单击事件
void MainWindow::on_btnSend_clicked()
{//发送数据
    // 1. 从输入框获取要发送的信息
    QString msg=ui->editMsg->text();
    // 2. 将发送信息显示在文本框
    ui->plainTextEdit->appendPlainText("[out] "+msg);
    // 3. 清空输入框
    ui->editMsg->clear();
    // 4. 输入框获得焦点
    ui->editMsg->setFocus();
    // 5. 将发送信息转成字节数组
    QByteArray  str=msg.toUtf8();
    str.append('\n');
    // 6. 将字节数据发送
    tcpClient->write(str);
}
