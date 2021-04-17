#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 1. 获取当前时间
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    qDebug() << current_date;
    QThread::msleep(2000);
    // 2. 获取现在时间
    QDateTime stopTime = QDateTime::currentDateTime();
    quint64 dt =  current_date_time.msecsTo(stopTime) ;
    qDebug() << dt;
    // 3. 修改当前时间
    current_date_time = current_date_time.addMSecs(dt);
    current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz ddd");
    qDebug() << current_date;

    qDebug()<<"QTime.currentTime ="<<dt<<"ms";


    // QString转QDateTime
    QDateTime time;
    QString strBuffer = "2018-06-06 14:05:00";
    time = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");
    time = time.addMSecs(555);

    QString strTime = time.toString("yyyy.MM.dd hh:mm:ss.zzz");
    qDebug() << strTime;



}

MainWindow::~MainWindow()
{
    delete ui;
}
