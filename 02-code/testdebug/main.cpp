#include "mainwindow.h"
#include <QApplication>
#include <QPoint>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPoint poxy;
    poxy.setX(8);
    poxy.setX(9);
    qDebug() << poxy  ;



    return a.exec();
}
