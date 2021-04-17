#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_thread.start();   // --error
    // QObject::startTimer: Timers cannot be started from another thread
    // 刚开始只有主线程一个，CThread的实例是在主线程中创建的，定时器在CThread的构造函数中，所以也是在主线程中创建的。
    // 当调用CThread的start()方法时，这时有两个线程。定时器的start()方法是在另一个线程中，也就是CThread中调用的。
    // 创建和调用并不是在同一线程中，所以出现了错误。


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_thread.terminate();
    m_thread.wait();
}
