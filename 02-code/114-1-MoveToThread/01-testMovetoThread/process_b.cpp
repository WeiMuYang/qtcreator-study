#include "process_b.h"
#include <QThread>

ProcessB::ProcessB(QObject *parent) : QObject(parent)
{
    m_stop = 0;
}

void ProcessB::displayB()
{
    while (1) {
        qDebug() << "B";
        QThread::msleep(1000);
        if(m_stop == 1)
            break;
    }
}
