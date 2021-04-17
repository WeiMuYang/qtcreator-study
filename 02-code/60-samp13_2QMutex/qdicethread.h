#ifndef QDICETHREAD_H
#define QDICETHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>

class QDiceThread : public QThread
{
    Q_OBJECT
public:
    QDiceThread();
    // 定义掷骰子的成员函数
    void diceBegin();   //掷一次骰子
    void diceEnd();     // 暂停
    void stopThread();  // 结束线程
    // 1. 主线程用来读数据的成员函数(新增)
    bool readValue(int *seq, int *diceValue); //用于主线程读取数据的函数
protected:
    // 2. 重写线程中的run函数
    void run() Q_DECL_OVERRIDE;
// signals: 因为不用信号槽实现子线程和主线程数据通信，所以不用定义信号
//    // 定义信号，发射：掷骰子的次数和最新的掷骰子中间结果发出去 (去掉)
//    void newValue(int seq,int diceValue)*/;

private:
    // 3. 定义互斥信号量，用于进程同步
    QMutex mutex; //互斥量
    int m_seq;
    int m_diceValue;
    bool m_paused;
    bool m_stop; //停止线程
};

#endif // QDICETHREAD_H
