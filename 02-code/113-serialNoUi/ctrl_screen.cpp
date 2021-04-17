#include "ctrl_screen.h"
#include <QDebug>
#include <QEventLoop>
#include <QTimer>

/**
 * @file        ctrl_screen.cpp
 * @brief       用于串口通信
 * @authors     YangWeiBin
 * @copyright   Gmagii
 * @version     v0.0.1
 * @date        2020-11-25 13:38:58
 */


CtrlScreen::CtrlScreen(QObject *parent) : QObject(parent) {
    m_pSerial_COMPort = new QSerialPort;    // 获取对象
    serialPortScan();                       // 端口名
    m_baudRate = QSerialPort::Baud9600;     // 波特率
    m_dataBit = QSerialPort::Data8;         // 数据位数
    m_parity = QSerialPort::NoParity;       // 奇偶校验
    m_stopBits = QSerialPort::OneStop;      // 停止位
    m_flowContrl = QSerialPort::NoFlowControl;//流控制
    m_qn64_bufferSize = 2048;               // 缓冲区大小
}


/**
 * @brief 扫描串口
 */
void CtrlScreen::serialPortScan() {
    if(m_pSerial_COMPort != NULL)   {
        qDebug() << tr("扫描存在的串口");
        foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            QSerialPort ser;
            ser.setPort(info);
            if(ser.open(QIODevice::ReadWrite))   {//  判断端口是否能打开
                qDebug() << tr("Scan Port:") + ser.portName();
                m_str_serialName = ser.portName();
                ser.close();
            }
        }
    } else {
        /* 串口没有初始化成功，先不处理异常 */
        qDebug() << tr("CtrlScreen::serialPortScan  Serial Port Init Error!");
        exit(1);
    }
}


/**
 * @brief           打开串口,
 * @return          打开成功：true   打开失败：false
 */
bool CtrlScreen::serialOpen() {
    m_pSerial_COMPort->setPortName(m_str_serialName);
    m_pSerial_COMPort->setBaudRate(m_baudRate);
    m_pSerial_COMPort->setDataBits(m_dataBit);
    m_pSerial_COMPort->setParity(m_parity);
    m_pSerial_COMPort->setStopBits(m_stopBits);
    m_pSerial_COMPort->setFlowControl(m_flowContrl);
    m_pSerial_COMPort->setReadBufferSize(m_qn64_bufferSize);
    /* 打开串口 */
    if(m_pSerial_COMPort->open(QIODevice::ReadWrite))
    {
        // 这种方式在信号前不要加类名::  容易出错
        connect(m_pSerial_COMPort, SIGNAL(readyRead()), this, SLOT(serialRecvMsgEvent()));
        return true;
    }else{
        qDebug() << tr("serialOpen : Serial Port Init Error!");
        return false;
    }
}

/**
 * @brief 读取接收到的数据
 */
void CtrlScreen::serialRecvMsgEvent() {
    /* 如果本次数据帧接受错误，那么先不接受 */
    if(m_pSerial_COMPort->bytesAvailable() >= 0) {
        QByteArray buffer = m_pSerial_COMPort->readAll();
        if(!buffer.isEmpty())
            qDebug() << buffer.toHex();
        else
            qDebug()<< "CtrlScreen::serialRecvMsgEvent Data ERROR!";
    }else
        qDebug()<<"CtrlScreen::serialRecvMsgEvent ERROR:" + QString::number(m_pSerial_COMPort->bytesAvailable());
}



/**
 * @brief       屏幕命令类型和修改的文本
 * @param cmd   命令类型
 * @param txt   文本
 */
void CtrlScreen::slotScreenCMD(ScreenCMD cmd, QString txt) {
    QString str;
    switch (cmd) {
    case kClose:
        str = "page 0";
        slotSendCMDtoScreen(str);
        break;
    case kOpen:
    {
        str =  "page page0";
        slotSendCMDtoScreen(str);
        QEventLoop eventloop;
        QTimer::singleShot(500, &eventloop, SLOT(quit()));
        eventloop.exec();
        str = "page page1";
        slotSendCMDtoScreen(str);
        str = "fill 20,20,380,5,GREEN";
        slotSendCMDtoScreen(str);
        str = "fill 20,20,5,190,GREEN";
        slotSendCMDtoScreen(str);
        str = "fill 20,207,380,5,GREEN";
        slotSendCMDtoScreen(str);
        str = "fill 395,20,5,190,GREEN";
        slotSendCMDtoScreen(str);

        QEventLoop eventloop1;
        QTimer::singleShot(500, &eventloop1, SLOT(quit()));
        eventloop1.exec();

        str = "page page2";
        slotSendCMDtoScreen(str);
        str = "pwdTxt.txt = \"00000000h\"";
        slotSendCMDtoScreen(str);
        str = "osTxt.txt = \"03C00000h\"";
        slotSendCMDtoScreen(str);
        str = "allEleTxt.txt = \"00000100h\"";
        slotSendCMDtoScreen(str);

        QEventLoop eventloop2;
        QTimer::singleShot(200, &eventloop2, SLOT(quit()));
        eventloop2.exec();
        str = "page page0";
        slotSendCMDtoScreen(str);
        QEventLoop eventloop3;
        QTimer::singleShot(200, &eventloop3, SLOT(quit()));
        eventloop3.exec();

        str = "page page2";
        slotSendCMDtoScreen(str);
        str = "pwdTxt.txt = \"00000000h\"";
        slotSendCMDtoScreen(str);
        str = "osTxt.txt = \"03C00000h\"";
        slotSendCMDtoScreen(str);
        str = "allEleTxt.txt = \"00000100h\"";
        slotSendCMDtoScreen(str);
    }
        break;
    case kPwdTxt:
        str = "pwdTxt.txt = \"" + txt + "\"";
        slotSendCMDtoScreen(str);
        break;
    case kOSTxt:
        str = "osTxt.txt = \"" + txt + "\"";
        slotSendCMDtoScreen(str);
        break;
    case kAllElemTxt:
        str = "allEleTxt.txt = \"" + txt + "\"";
        slotSendCMDtoScreen(str);
        break;
    case test:
        str = "fill 20,20,380,5,GREEN";
        slotSendCMDtoScreen(str);
        break;
    default:
        qDebug() << "CtrlScreen::slotScreenCMD CMD ERROR!" ;
        return ;
        break;
    }

}


/**
 * @brief       向串口屏发送命令
 * @param str   要发送的命令
 */
void CtrlScreen::slotSendCMDtoScreen(QString str)
{
    if(m_pSerial_COMPort->isOpen()) {
        QByteArray sendData;
        unsigned char arr[3] = {0xff ,0xff ,0xff};
        QByteArray dataEnd((char*)arr, 3);
        sendData.push_back(str.toUtf8());
        sendData.push_back(dataEnd);
        m_pSerial_COMPort->write(sendData);
    }
}








