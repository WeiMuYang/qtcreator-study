#include "qdicethread.h"
#include <QTime>

QDiceThread::QDiceThread()
{
    m_seq = 0;
    m_paused = true;
    m_stop = false;
}

void QDiceThread::diceBegin()
{
//    mutex.lock();
    m_paused = false;
//    mutex.unlock();
}

void QDiceThread::diceEnd()
{   // 原则上，对于两个或两个以上线程可能会同时读或写的变量应该使用互斥量进行保护
    // 但是，若只有一条赋值语句的话，
//    mutex.lock();
    m_paused=true;   // 只有一行语句，是原子操作，不用进行保护和锁定
//    mutex.unlock();
}

void QDiceThread::stopThread()
{
//    mutex.lock();
    m_stop=true;
//    mutex.unlock();
}

// 1. 主线程通过调用该函数，获取子线程的成员变量的值
bool QDiceThread::readValue(int *seq, int *diceValue)
{
    // 试图锁定一个互斥量，若锁定成功返回true；
    // 若有其他线程已经锁定了这个互斥量，返回false
    if (mutex.tryLock()) {
        // 锁定成功，进if语句
        *seq = m_seq;
        *diceValue = m_diceValue;
        mutex.unlock();  // 读取值后解锁
        return true;
    }
    else
        return false;
}

void QDiceThread::run()
{
    m_stop=false;//启动线程时令m_stop=false
    m_seq=0;
    qsrand(QTime::currentTime().msec());//随机数初始化，qsrand是线程安全的

    while(!m_stop)//循环主体
    {
        if (!m_paused)  {
            // 通过mutex.lock();和mutex.unlock();对属性成员进行保护
            mutex.lock();
            m_diceValue=qrand(); //获取随机数
            m_diceValue=(m_diceValue % 6)+1;
            m_seq++;
            mutex.unlock();
        }
        msleep(500); //线程休眠100ms
    }
}

