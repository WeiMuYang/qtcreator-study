#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(0, "test1"); // 调用构造函数
    w.show();

    return a.exec();
}
