#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>   // 通信套接字

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void createConnect();
    void tcpCommunicate();

private slots:
    void on_pbnSend_clicked();

    void on_pbnClose_clicked();

    void on_pbnConnect_clicked();

private:
    Ui::MainWindow *ui;

    QTcpSocket* m_ptcpSocket_correspond;// 定义通信套接字对象指针
};

#endif // MAINWINDOW_H
