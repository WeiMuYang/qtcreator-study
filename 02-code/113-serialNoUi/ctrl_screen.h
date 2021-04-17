#ifndef CTRLSCREEN_H
#define CTRLSCREEN_H

#include <QObject>
#include <QSerialPort>        // 提供访问串口的功能
#include <QSerialPortInfo>    // 提供系统中存在的串口的信息


typedef enum {
    kClose = 0, kOpen = 1, kPwdTxt = 2, kOSTxt = 3, kAllElemTxt = 4, test = 5
} ScreenCMD;


class CtrlScreen : public QObject
{
    Q_OBJECT
public:
    explicit CtrlScreen(QObject *parent = 0);
    void serialPortScan();      // 扫描串口
signals:

public slots:
    bool serialOpen();
    void serialRecvMsgEvent();
    void slotSendCMDtoScreen(QString str);
    void slotScreenCMD(ScreenCMD cmd, QString txt = "");

private:
    QSerialPort* m_pSerial_COMPort;  // 1. 串口对象
    QString m_str_serialName;        // 2. 串口名
    QSerialPort::BaudRate m_baudRate;// 3. 波特率
    QSerialPort::DataBits m_dataBit; // 4. 数据位数
    QSerialPort::Parity m_parity;    // 5. 奇偶校验
    QSerialPort::StopBits m_stopBits;// 6. 停止位
    QSerialPort::FlowControl m_flowContrl;// 7. 流控制
    qint64 m_qn64_bufferSize;        // 8. 缓冲区大小
};

#endif // CTRLSCREEN_H
