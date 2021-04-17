#include "qdicethread.h"
#include <QTime>

QDiceThread::QDiceThread()
{
    m_seq = 0; //掷骰子次数序号
    m_Paused = true; //掷一次骰子
    m_stop = false; //停止线程
}

void QDiceThread::diceBegin()
{
    // 开始掷骰子
    m_Paused = false;
}

void QDiceThread::dicePause()
{
    // 暂停掷骰子
    m_Paused=true;
}

void QDiceThread::stopThread()
{
    // 停止线程
    m_stop=true;
}


// 1. 重写run函数，线程中执行的内容就是，run函数中的内容
void QDiceThread::run()
{
    // 线程任务
    m_stop = false; //启动线程时令m_stop=false
    m_seq = 0; //掷骰子次数
    qsrand(QTime::currentTime().msec());//随机数初始化，qsrand是线程安全的

    // 线程启动后，进入while不停循环
    while(!m_stop)//循环主体
    {
        // 若不暂停掷骰子
        if (!m_Paused)
        {
            // 生成1~6的随机数
            m_diceValue = qrand(); //获取随机数
            m_diceValue = (m_diceValue % 6)+1;
            // 掷骰子的次数增一
            m_seq++;
            // 将掷骰子的次数和最新的掷骰子结果发出去
            emit newValue(m_seq,m_diceValue);  //发射信号
        }
        msleep(500); //线程休眠500ms
    }

//  在  m_stop==true时结束线程任务
    quit();//相当于  exit(0),退出线程的事件循环
}

