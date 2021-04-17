#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "childthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    // 0. 默认构造函数
    explicit MainWindow(QWidget *parent = 0, QString name = "");
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event);    // 1. 用于关闭线程
private slots:
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    ChildThread m_childThread;
    int m_ClickTime;                        //  2. 单击次数
};

#endif // MAINWINDOW_H
