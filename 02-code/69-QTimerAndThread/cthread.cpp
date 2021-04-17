#include "cthread.h"
#include <QDebug>
#include <QTime>

CThread::CThread(QObject *parent) : QThread(parent) // 1. 带有信号槽的子线程，替换QObject
{
    // m_pTimer = new QTimer();   // 2.  不可放在构造函数中创建
}

void CThread::display()
{
    qDebug() << QString::fromLocal8Bit("Current Thread ID:") << QThread::currentThread() << QTime::currentTime().toString();
}

void CThread::run()
{
    m_pTimer = new QTimer();   // 3. 在子线程中创建
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(display()));
    m_pTimer->start(1000);
    this->exec();   // 不可省略
}
