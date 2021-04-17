#include "mythread.h"
#include <QCoreApplication>
#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
{
    for(int i = 0; i < 5; ++i){
        qDebug() << "runing ";
        MySleep(1);
    }
}


void MyThread::MySleep(double sec)  {
    int msec = sec * 1000;
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
