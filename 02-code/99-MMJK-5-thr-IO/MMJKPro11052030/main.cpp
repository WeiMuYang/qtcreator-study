#include "mainwindow.h"
#include <QApplication>
#include "io_ctrl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    IOCtrl ioCtrl;


    w.show();

    return a.exec();
}
