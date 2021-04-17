#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // 扫描串口
    void serialPortScan();
    bool serialOpen( );

private slots:
    void on_pbnCheckPort_clicked();

    void on_pbnOpenPort_clicked();

    void on_pbnRecTxtClear_clicked();

    void on_pbnSendTxtClear_clicked();

    void on_pbnSend_clicked();

    void  SerialRecvMsgEvent();

private:
    Ui::MainWindow *ui;
    // 1. 串口对象
    QSerialPort* m_pserial_COMPort;
};

#endif // MAINWINDOW_H
