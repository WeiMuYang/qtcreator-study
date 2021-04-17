#include "mythread.h"
#include <QDebug>


MyThread::MyThread(QString name)
    :m_name(name)
{
}

void MyThread::threadStart()
{
    qDebug()<< m_name << "start.";
    start();
}

void MyThread::threadStop()
{
    qDebug()<< m_name << "stop.";
    terminate();
    wait();
}

void MyThread::display(QString s)
{
      if(m_mutex.tryLock()){   // tryLock
    // m_mutex.lock();
        for (int i = 0; i < 10; ++i){
            qDebug() << s;
            sleep(1);
        }
         m_mutex.unlock();
       }
}

void MyThread::run()
{
    // 1. 子线程调用display
    display("Thread display!");
}
