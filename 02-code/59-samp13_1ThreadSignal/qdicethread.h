#ifndef QDICETHREAD_H
#define QDICETHREAD_H

// 1. 添加线程函数库
#include  <QThread>

// 公有继承QThread，成为QThread的一个子类
class QDiceThread : public QThread
{
    Q_OBJECT
public:
    QDiceThread();
    // 定义掷骰子的成员函数
    void diceBegin();    // 掷一次骰子
    void dicePause();    // 暂停
    void stopThread();   // 结束线程

protected:
    // 2. 重写线程的中 run 函数
    void    run() Q_DECL_OVERRIDE;  // 线程任务
signals:
    // 3. 定义信号，发射：掷骰子的次数和最新的掷骰子结果发出去
    void    newValue(int seq,int diceValue);
private:
    int     m_seq;      // 掷骰子次数序号
    int     m_diceValue;// 骰子点数
    bool    m_Paused;   // 掷一次骰子
    bool    m_stop;     // 停止线程
};

#endif // QDICETHREAD_H
