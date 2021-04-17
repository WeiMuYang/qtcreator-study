#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QByteArray>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QByteArray arr1;
    arr1.append(0x20);
    arr1.append('\x00'); // ERROR arr1.append(0x00);
    arr1.append('\x00');
    arr1.append('\xdb'); // ERROR arr1.append(0xdb);
    arr1[0] = 0x22;
    // ERROR   arr1.at(0) = 0x22;

    if(arr1.at(1) == 0x00)
        qDebug() << arr1.toHex();

    if(arr1.at(3) == '\xdb')   // ERROR if(arr1.at(3) == 0xdb)  警告：而且无法进行正确判断
        qDebug() << arr1.toHex();


}

MainWindow::~MainWindow()
{
    delete ui;
}
