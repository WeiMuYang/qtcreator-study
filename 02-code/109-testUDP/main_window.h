#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void readData();

private slots:
    void UDPreceive();
    void UDPsend();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void changeReceiveIPPort();
    void changeSendIPPort();

private:
    Ui::MainWindow *ui;
    QUdpSocket *m_pudpsocket_send;
    QUdpSocket *m_pudpsocket_receive;
    QByteArray m_ByteArr_receive;
    QString m_str_sendIP;
    QString m_str_sendPort;
    QString m_str_receiveIP;
    QString m_str_receivePort;
};

#endif // MAINWINDOW_H
