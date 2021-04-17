#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
        qDebug() << "\t "<< driver;
    qDebug() << "End";
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setPort(3306);
    db.setHostName("localhost");//mysql在本地，赶写这个那可
    db.setDatabaseName("mysql");//mysql这个database在数据中自带了一个，之后
    db.setUserName("root");//这个user name和password要和上文中设置的一置
    db.setPassword("123");
    if(!db.open()){
        qDebug()<<db.lastError();
    }
    else{
        qDebug() << "\nConnected " << "OK";
    }

}



















MainWindow::~MainWindow()
{
    delete ui;
}
