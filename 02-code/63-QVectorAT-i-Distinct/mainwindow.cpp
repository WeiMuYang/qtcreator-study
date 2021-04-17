#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector <int> intVec;
    for(int i = 0; i < 10; ++i)
        intVec.append(i + 1);



    qDebug() << "intVec.at(4) = " <<  intVec.at(4);
    qDebug() << "intVec[4] = " <<  intVec[4];
    // intVec.at(4) += 10;    // readonly  --error
    intVec[4] += 100;

    qDebug() << "intVec.at(4) = " <<  intVec.at(4);
    qDebug() << "intVec[4] = " <<  intVec[4];


    qDebug() << "length = " << intVec.length();
    intVec.insert(10,22);   // 最多可以在下标是length的位置插入
    qDebug() << "length = " << intVec.length();
    intVec.insert(11,22);   // 最多可以在下标是length的位置插入
    qDebug() << "length = " << intVec.length();
    // intVec.insert(15,22);   // insert: "index out of range" --error





}

MainWindow::~MainWindow()
{
    delete ui;
}
