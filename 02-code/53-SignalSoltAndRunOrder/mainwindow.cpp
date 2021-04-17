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
    connect(this, SIGNAL(signal2()), this, SLOT(Process2Clicked()),Qt::QueuedConnection);
    connect(this, SIGNAL(signal3()), this, SLOT(Process3Clicked()),Qt::DirectConnection);
    connect(this, SIGNAL(signal4()), this, SLOT(Process4Clicked()),Qt::QueuedConnection);
    connect(this, SIGNAL(signal1()), this, SLOT(Process1Clicked()),Qt::DirectConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Process1Clicked()
{
    qDebug() << "Process1 clicked";
    emit signal2();
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process1";
        QThread::sleep(1);
    }
}

void MainWindow::Process2Clicked()
{
    qDebug() << "Process2 clicked";
    emit signal3();
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process2";
        QThread::sleep(1);
    }
}

void MainWindow::Process3Clicked()
{
    qDebug() << "Process3 clicked";
    emit signal4();
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process3";
        QThread::sleep(1);
    }
}

void MainWindow::Process4Clicked()
{
    qDebug() << "Process4 clicked";
    emit signal1();
    for(int i = 1; i < 5; ++i){
        qDebug() << "Process4";
        QThread::sleep(1);
    }
}

