#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0,800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->setStyleSheet("#widget{  background-color: rgb(0, 0, 0);   border: 5px solid #00ff00;   };");
    MySleep(2.5);
    ui->widget->setStyleSheet("#widget{  background-color: rgb(0, 0, 0);   border: 5px solid #000000;   };");
    MySleep(0.5);
    ui->label_1->setStyleSheet("color: rgb(0, 255, 0);");
    ui->label_2->setStyleSheet("color: rgb(0, 255, 0);");
    ui->label_3->setStyleSheet("color: rgb(0, 255, 0);");
    ui->label_4->setStyleSheet("color: rgb(0, 255, 0);");
    MySleep(0.2);
    ui->label_1->setStyleSheet("color: rgb(0, 0, 0);");
    ui->label_2->setStyleSheet("color: rgb(0, 0, 0);");
    ui->label_3->setStyleSheet("color: rgb(0, 0, 0);");
    ui->label_4->setStyleSheet("color: rgb(0, 0, 0);");
    MySleep(0.2);
    ui->label_1->setStyleSheet("color: rgb(0, 255, 0);");
    ui->label_2->setStyleSheet("color: rgb(0, 255, 0);");
    ui->label_3->setStyleSheet("color: rgb(0, 255, 0);");
    ui->label_4->setStyleSheet("color: rgb(0, 255, 0);");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->widget->setStyleSheet("#widget{  background-color: rgb(0, 0, 0); border: 5px solid #000000; }");
    ui->label_1->setStyleSheet("color: rgb(0, 0, 0);");
    ui->label_2->setStyleSheet("color: rgb(0, 0, 0);");
    ui->label_3->setStyleSheet("color: rgb(0, 0, 0);");
    ui->label_4->setStyleSheet("color: rgb(0, 0, 0);");
}

void MainWindow::MySleep(double sec){ // 延迟sec秒
    int msec = sec * 1000;
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
