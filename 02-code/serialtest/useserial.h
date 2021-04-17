#ifndef USESERIAL_H
#define USESERIAL_H

#include <QObject>
#include <QSerialPort>        // 提供访问串口的功能
#include <QSerialPortInfo>    // 提供系统中存在的串口的信息


class UseSerial : public QObject
{
    Q_OBJECT
public:
    explicit UseSerial(QObject *parent = 0);
    // 扫描串口
    void serialPortScan();
    bool serialOpen(QString portName);

signals:

public slots:

private:
    // 1. 串口对象
    QSerialPort* m_pserial_COMPort;
};

#endif // USESERIAL_H
