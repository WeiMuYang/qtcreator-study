#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QTime>
#include <QMessageBox>
#include <QTimeEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1.
//    QProcess::execute("date 031210252014"); // 0312 表示baidu3月12日，1025表示当前时分
//    QProcess::execute("hwclock -h"); // 同步系zhi统时间
//    QProcess::execute("sync"); // 保存配置

    // 2.
   // qt-读取和修改系统时间

   QTime ct = QTime::currentTime();
   // 修改系统时间
   QTimeEdit timeEditor;
   system("pkexec ls /");

   // change the system time
       QDateTime dt = QDateTime::currentDateTime();
       dt.setTime(timeEditor.time());
       time_t tt = (time_t)dt.toTime_t();
       int r = stime(&tt);
       if (r)
       {
           if (errno == EPERM)

               QMessageBox::warning(this, "Error", "You don't have permission to change system time.");

       }

}

MainWindow::~MainWindow()
{
    delete ui;
}

