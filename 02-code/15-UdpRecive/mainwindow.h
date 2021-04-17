#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// 1. 添加UDP套接字函数库，若显示黄色下划线，编译一下即可
#include <QUdpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // 4. 获取本机的IP地址
    QString getHostIpAddress();

public slots:
// 3. 监听到发来信息后，调用receive()
    void receive();

private:
    Ui::MainWindow *ui;
// 2. 建立套接字对象，用于调用库函数
    QUdpSocket *uSocket;
};

#endif // MAINWINDOW_H
