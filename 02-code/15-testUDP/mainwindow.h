#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// 1. 添加UDP的头文件
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
    // 2. 发送UDP数据报的函数
    void SendUDPData();

private slots:
    // 3. 添加按钮的单击事件，也可以不通过按钮触发，那就定义一个普通的
    void on_pushButtonwrite_clicked();
private:
    Ui::MainWindow *ui;

    // 4. 定义一个UDP套接字的对象指针
    QUdpSocket *udpsocket;
};

#endif // MAINWINDOW_H
