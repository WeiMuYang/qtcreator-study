#include "cthread.h"
#include <QDebug>
#include "changestatus.h"

CThread::CThread(QThread *parent) : QThread(parent)
{
    m_changeStatus = new ChangeStatus();
}

void CThread::thrStart()
{
    this->start();
    qDebug() << "thread start!";
}

void CThread::thrEnd()
{
    this->terminate();
    this->wait();
    qDebug() << "thread end!";
}

void CThread::thrPause()
{
    m_qmutex.lock();

}

void CThread::thrContinue()
{
    m_qmutex.unlock();
}

void CThread::setData(QLabel *label, int s)
{
    m_label = label;
    m_status = s;
}


void CThread::run()
{
    while(1){

        sleep(12);

        m_status ++ ;
        if(m_status == 3)
            m_status = 0;
        emit sendCgeStatus(m_status);


    }
}
