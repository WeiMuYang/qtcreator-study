#include "cthread.h"
#include <QDebug>
#include <QTime>

CThread::CThread(QThread *parent) : QThread(parent)
{

}

void CThread::display()
{
    qDebug() << QString::fromLocal8Bit("Current Thread ID:") << QThread::currentThread() << QTime::currentTime().toString();
}

void CThread::run()
{
    // display();
    sleep(10);
}
