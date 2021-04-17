#include "useserial.h"

UseSerial::UseSerial(QObject *parent) : QObject(parent)
{
    m_pserial_COMPort = new QSerialPort;
}

/**
 * @brief 扫描串口
 */
void UseSerial::serialPortScan() {
    if(m_pserial_COMPort != NULL)   {
        qDebug() << tr("扫描存在的串口");
        foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
            QSerialPort ser;
            ser.setPort(info);
            /* 判断端口是否能打开 */
            if(ser.open(QIODevice::ReadWrite))   {
                qDebug() << tr("Open Port:")+ser.portName()+tr("\r\n");
                ser.close();
            }
        }
    } else  {
        /* 串口没有初始化成功，先不处理异常 */
        qDebug() << tr("serialPortScan : Serial Port Init Error!");
    }
}

/**
 * @brief           打开串口,
 * @param portName  串口的名字
 * @return          打开成功：true   打开失败：false
 */
bool UseSerial::serialOpen(QString portName)
{
    /* 设置串口名称 */
    m_pserial_COMPort->setPortName(ui->comboBox->currentText());
    /* 设置波特率 */
    m_pserial_COMPort->setBaudRate(QSerialPort::Baud9600);
    /* 设置数据位数 */
    m_pserial_COMPort->setDataBits(QSerialPort::Data8);
    /* 设置奇偶校验 */
    m_pserial_COMPort->setParity(QSerialPort::NoParity);
    /* 设置停止位*/
    m_pserial_COMPort->setStopBits(QSerialPort::OneStop);
    /* 设置流控制 */
    m_pserial_COMPort->setFlowControl(QSerialPort::NoFlowControl);

    m_pserial_COMPort->setReadBufferSize(1024);
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
