#include "process_a.h"
#include <QThread>

ProcessA::ProcessA(QObject *parent) : QObject(parent)
{
    m_stop = 0;
}

void ProcessA::displayA()
{
    while (1) {
        qDebug() << "A";
        QThread::msleep(1000);
        if(m_stop == 1)       break;
    }
}
