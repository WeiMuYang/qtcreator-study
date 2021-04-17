#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include    <QTcpSocket>
#include    <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    // 1. 用于创建tcp的socket套接字
    QTcpSocket *tcpClient;  //socket
    // 2. 状态栏标签
    QLabel *LabSocketState;  //状态栏显示标签
    // 3. 获取本机的以太网IP
    QString getLocalIP();//获取本机IP地址
protected:
    // 4. 重写关机事件
    void closeEvent(QCloseEvent *event);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//自定义槽函数
    // 5. 建立连接
    void    onConnected();
    // 6. 断开连接
    void    onDisconnected();
    //
    void    onSocketStateChange(QAbstractSocket::SocketState socketState);
    //
    void    onSocketReadyRead();//读取socket传入的数据
    // Socket状态变化的槽函数
    void on_actConnect_triggered();

    void on_actDisconnect_triggered();
    // 清空文本槽函数
    void on_actClear_triggered();

    // 发送信息槽函数
    void on_btnSend_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
