#include "process_a.h"
#include <QThread>

ProcessA::ProcessA(QObject *parent) : QObject(parent)
{
    m_stop = 0;
}

void ProcessA::displayA()
{
    while (!m_stop) {

        qDebug() << m_str_name;
        QThread::msleep(1000);

    }
}
