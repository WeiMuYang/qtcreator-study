#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Process1Clicked()),Qt::DirectConnection);
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(Process2Clicked()),Qt::QueuedConnection);
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(Process3Clicked()),Qt::DirectConnection);
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(Process4Clicked()),Qt::DirectConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Process1Clicked()
{
    qDebug() << "Process1 clicked";
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process1";
        QThread::sleep(1);
    }
}

void MainWindow::Process2Clicked()
{
    qDebug() << "Process2 clicked";
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process2";
        QThread::sleep(1);
    }
}

void MainWindow::Process3Clicked()
{
    qDebug() << "Process3 clicked";
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process3";
        QThread::sleep(1);
    }
}

void MainWindow::Process4Clicked()
{
    qDebug() << "Process4 clicked";
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process4";
        QThread::sleep(1);
    }
}





//void MainWindow::on_pushButton_clicked()
//{
//    qDebug() << "Process1 clicked";
//    for(int i = 1; i < 5; ++i){
//        qDebug() << "Process1";
//        QThread::sleep(1);
//    }
//}

//void MainWindow::on_pushButton_2_clicked()
//{
//    qDebug() << "Process2 clicked";
//    for(int i = 1; i < 5; ++i){
//        qDebug() << "Process2";
//        QThread::sleep(1);
//    }
//}

//void MainWindow::on_pushButton_3_clicked()
//{
//    qDebug() << "Process3 clicked";
//    for(int i = 1; i < 5; ++i){
//        qDebug() << "Process3";
//        QThread::sleep(1);
//    }
//}

//void MainWindow::on_pushButton_4_clicked()
//{
//    qDebug() << "Process4 clicked";
//    for(int i = 1; i < 5; ++i){
//        qDebug() << "Process4";
//        QThread::sleep(1);
//    }
//}
