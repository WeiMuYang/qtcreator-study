#include "widget.h"
#include <QApplication>
#include "showmsg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;   // 1. 主窗体对象，内部会发SendMsg信号
    ShowMsg s;  // 2. 接收端对象，有槽函数RecvMsg接收信号

    // 3. 建立关联

     QObject::connect(&w, SIGNAL(SendMsg(QString)), &s, SLOT(RecvMsg(QString)));

    w.show();

    return a.exec();
}
