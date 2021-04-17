#include <QCoreApplication>
#include "ctrl_screen.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CtrlScreen cp;
    cp.serialOpen();
    // cp.slotScreenCMD(kOpen);

    cp.slotScreenCMD(kClose);
    cp.slotScreenCMD(kOpen);

    return a.exec();  // 必须在a.exec()中才能使用串口  不能是return 0；
}
