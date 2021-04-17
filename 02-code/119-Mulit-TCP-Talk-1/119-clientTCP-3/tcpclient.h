#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

#include <QWidget>
#include <QTcpSocket>
#include <iostream>
#include <string>
using namespace std;


namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();

private slots:
    void on_pushButtonEnter_clicked();
    void slotconnectedsuccess();  //处理连接成功的信号
    void slotreceive();   //接收服务器传过来的信息
    void on_pushButtonSend_clicked();
    void slotdisconnected();  //处理离开聊天室的信号


private:
    Ui::TcpClient *ui;
    bool status;     //用来判断是否进入了服务器
    size_t strSize;
    int port;
    QHostAddress *serverIP;
    QString userName;
    QTcpSocket *tcpsocket;
};

#endif // TCPCLIENT_H
