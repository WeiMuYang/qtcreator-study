#include "main_window.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 发送信息(发送的端口号：8000)
    m_pudpsocket_send = new QUdpSocket;
    QStringList sendList = QString(ui->sendIP->text()).split(":");
    m_str_sendIP = sendList[0];
    m_str_sendPort = sendList[1];


    // 接收信息(接收的端口号：9000)
    m_pudpsocket_receive = new QUdpSocket;
    QStringList receiveList = QString(ui->receiveIP->text()).split(":");
    m_str_receiveIP = receiveList[0];
    m_str_receivePort = receiveList[1];
    m_pudpsocket_receive->bind(QHostAddress(m_str_receiveIP), m_str_receivePort.toInt());

    connect(m_pudpsocket_receive, SIGNAL(readyRead()), this, SLOT(UDPreceive()));
    connect(ui->pbn_send, &QPushButton::clicked, this, UDPsend);
    connect(ui->receiveIP, &QLineEdit::textChanged, this,  changeReceiveIPPort );
    connect(ui->sendIP, &QLineEdit::textChanged, this,  changeSendIPPort );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeReceiveIPPort()
{
    QStringList receiveList = QString(ui->receiveIP->text()).split(":");
    m_str_receiveIP = receiveList[0];
    m_str_receivePort = receiveList[1];
    m_pudpsocket_receive->abort();
    m_pudpsocket_receive->bind(QHostAddress(m_str_receiveIP), m_str_receivePort.toInt());
}
void MainWindow::changeSendIPPort()
{

    QStringList sendList = QString(ui->sendIP->text()).split(":");
    m_str_sendIP = sendList[0];
    m_str_sendPort = sendList[1];
}

void MainWindow::UDPreceive()
{
    while(m_pudpsocket_receive->hasPendingDatagrams())
    {
        m_ByteArr_receive.resize(m_pudpsocket_receive->pendingDatagramSize());
        m_pudpsocket_receive->readDatagram(m_ByteArr_receive.data(), m_ByteArr_receive.size());
        qDebug() <<  m_ByteArr_receive.data();
    }
    QString str = QString(m_ByteArr_receive);
    ui->textEdit_receive->append(str);
}

void MainWindow::UDPsend()
{
    QString str = ui->textEdit_send->toPlainText();
    QByteArray ByteArr = str.toLatin1();
    m_pudpsocket_send->writeDatagram(ByteArr, (QHostAddress)(m_str_sendIP),  m_str_sendPort.toInt());
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit_receive->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_send->clear();
}
