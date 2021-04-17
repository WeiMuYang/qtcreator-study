#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include    <QTcpServer>
#include    <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    // 1. 状态栏标签
    QLabel  *LabListen;//状态栏标签
    QLabel  *LabSocketState;//状态栏标签
    // 2. TCP服务器
    QTcpServer *tcpServer; //TCP服务器
    // 3. TCP套接字
    QTcpSocket *tcpSocket;//TCP通讯的Socket
    // 4. 获取本机IP
    QString getLocalIP();//获取本机IP地址

protected:
    // 5. 重写窗口关闭事件
    void    closeEvent(QCloseEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//自定义槽函数
    // 6. 建立新的连接
    void    onNewConnection();//QTcpServer的newConnection()信号
    //
    void    onSocketStateChange(QAbstractSocket::SocketState socketState);
    void    onClientConnected(); //Client Socket connected
    void    onClientDisconnected();//Client Socket disconnected
    void    onSocketReadyRead();//读取socket传入的数据
//UI生成的
    //
    void on_actStart_triggered();

    void on_actStop_triggered();

    void on_actClear_triggered();

    void on_btnSend_clicked();

//    void on_actHostInfo_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
