#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pserial_COMPort = new QSerialPort;
    serialPortScan();
}



/**
 * @brief 扫描串口
 */
void MainWindow::serialPortScan() {
    if(m_pserial_COMPort != NULL)   {
        qDebug() << tr("扫描存在的串口");
        foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            QSerialPort ser;
            ser.setPort(info);
            /* 判断端口是否能打开 */
            if(ser.open(QIODevice::ReadWrite))   {
                qDebug() << tr("Open Port:")+ser.portName()+tr("\r\n");
                ui->cbbNum->addItem(ser.portName());
                ser.close();
            }
        }
    } else {
        /* 串口没有初始化成功，先不处理异常 */
        qDebug() << tr("serialPortScan : Serial Port Init Error!");
        exit(1);
    }
}

/**
 * @brief           打开串口,
 * @param portName  串口的名字
 * @return          打开成功：true   打开失败：false
 */
bool MainWindow::serialOpen()
{
    /* 设置串口名称 */
    m_pserial_COMPort->setPortName(ui->cbbNum->currentText());
    /* 设置波特率 */
    m_pserial_COMPort->setBaudRate(ui->cbbBaudRate->currentText().toInt());
    /* 设置数据位数 */
    m_pserial_COMPort->setDataBits(QSerialPort::Data8);
    /* 设置奇偶校验 */ // TODO BUG
    m_pserial_COMPort->setParity(QSerialPort::NoParity);
    /* 设置停止位*/    // TODO BUG
    m_pserial_COMPort->setStopBits(QSerialPort::OneStop);
    /* 设置流控制 */   // TODO BUG
    m_pserial_COMPort->setFlowControl(QSerialPort::NoFlowControl);

    m_pserial_COMPort->setReadBufferSize(ui->LEditBufferSize->text().toInt());
    /* 打开串口 */
    if(m_pserial_COMPort->open(QIODevice::ReadWrite)==true)
    {

        QObject::connect(m_pserial_COMPort, &QSerialPort::readyRead, this, SerialRecvMsgEvent);
        return true;
    }else{
        qDebug() << tr("serialOpen : Serial Port Init Error!");
        return false;
    }
}


void MainWindow::SerialRecvMsgEvent()
{
    /* 如果本次数据帧接受错误，那么先不接受 */
    if(m_pserial_COMPort->bytesAvailable() >= 0)
    {
        // buf.remove(0,buf.length());
        QByteArray buffer = m_pserial_COMPort->readAll();
        if(!buffer.isEmpty())
        {
            /* 把接受到的数据显示到界面上 */
            ui->txtRec->append(buffer);

        }else
        {
            qDebug()<<"接受数据出错";
        }
    }else
    {
        qDebug()<<"接受数据出错" + QString::number(m_pserial_COMPort->bytesAvailable());
    }
    qDebug()<<tr("yes\r\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pbnCheckPort_clicked()
{
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QSerialPort ser;
        ser.setPort(info);
        /* 判断端口是否能打开 */
        if(ser.open(QIODevice::ReadWrite))   {
            qDebug() << tr("Open Port:")+ser.portName()+tr("\r\n");
            ui->cbbNum->addItem(ser.portName());
            ser.close();
        }
    }
}

void MainWindow::on_pbnOpenPort_clicked()
{
    serialOpen();
}

void MainWindow::on_pbnRecTxtClear_clicked()
{
    ui->txtRec->clear();
}

void MainWindow::on_pbnSendTxtClear_clicked()
{
    ui->txtSend->clear();
}

void MainWindow::on_pbnSend_clicked()
{
    if(m_pserial_COMPort->isOpen())
    {
        QByteArray sendData;
        unsigned char arr[3] = {0xff ,0xff ,0xff};
        QByteArray dataEnd((char*)arr, 3);
        sendData.push_back(ui->txtSend->toPlainText().toUtf8());
        sendData.push_back(dataEnd);

        m_pserial_COMPort->write(sendData);
    }
}
