#include "do_thr.h"
#include "io_ctrl.h"

DOThr::DOThr(QThread *parent, InstantDoCtrl *p,int port,int b)
    : QThread(parent),m_pinstantDoCtrl(p),m_port(port),m_bit(b) {
    m_pauseTex.lock();
    m_errCode_ret = Success;

}

void DOThr::setData(InstantDoCtrl *p, int port, int b)
{
    m_pinstantDoCtrl = p;
    m_port = port;
    m_bit = b;
}

void DOThr::setType(int t)
{
    m_n_type = t;
}

void DOThr::run()
{
    while(1){
        m_pauseTex.lock();      // 3. 给对象加锁
        if(0 == m_n_type)
            dataOut(1, 0.5);
        else
            dataOut(1, 0);
        m_pauseTex.unlock();    // 4. 给对象解锁
        MySleep(0.5);           // 暂停1秒
    }
}

/**
 * @brief 以interval秒的间隔对p端口b位进行信号的输入
 * @param port：端口号    行号 ： 0 1
 * @param bit： 位置号    列号 ： 0 1 2 3 4 5 6 7
 * @param status： 灯的需要变的状态
 * @param interval： 间隔时间
 */
void DOThr::dataOut(uint8 status, double interval){

    if(0 == interval)
        m_errCode_ret = m_pinstantDoCtrl->WriteBit(m_port, (byte)m_bit, status);
    else{
        m_errCode_ret = m_pinstantDoCtrl->WriteBit(m_port, (byte)m_bit, 0);
        MySleep(interval);
        m_errCode_ret = m_pinstantDoCtrl->WriteBit(m_port, (byte)m_bit, 1);
        MySleep(interval);
    }
    CHK_RESULT(m_errCode_ret);
}

void DOThr::MySleep(double sec){
    int msec = sec * 1000;
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void DOThr::ThreadPause() {
    m_pauseTex.lock();      // 1. 给对象加锁
    // qDebug() << "Pause!";
}
void DOThr::ThreadContinue() {
    m_pauseTex.unlock();    // 2. 给对象解锁
    // qDebug() << "Continue...";
}
