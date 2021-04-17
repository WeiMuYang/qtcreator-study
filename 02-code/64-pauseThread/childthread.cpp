#include "childthread.h"
#include <QDebug>


ChildThread::ChildThread(QString name) {
    m_Name = name;
}
void ChildThread::ThreadPause() {
    m_pauseTex.lock();      // 1. 给对象加锁
    qDebug() << "Pause!";
}
void ChildThread::ThreadContinue() {
    m_pauseTex.unlock();    // 2. 给对象解锁
    qDebug() << "Continue...";
}
void ChildThread::ThreadStop() {
    qDebug() << "Thread:" << m_Name << "Stop! ";
    this->terminate();
    this->wait();
    // 注意：
    // this->quit(); 和 exit(0); 不可用   --error
}

void ChildThread::ThreadStart() {
    qDebug() << "Thread:" << m_Name << "Start! ";
    start();
}

void ChildThread::run() {
    while(1){
        m_pauseTex.lock();      // 3. 给对象加锁
        qDebug() << "Runing..........";
        m_pauseTex.unlock();    // 4. 给对象解锁
        sleep(1);          // 暂停1秒
    }
}
