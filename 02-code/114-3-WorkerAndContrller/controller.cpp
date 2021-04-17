#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent) {
    // 1. 创建对象
    m_pthr_doWork = new QThread;
    // m_pthr_doWork->setParent(this);   // 线程最好不用指定父类对象，否则可能内出错
    m_worker_obj = new Worker;
    // 2. 将包含dowork的函数对象，移动到子线程
    m_worker_obj->moveToThread(m_pthr_doWork);

    // 3. 线程结束后，退出线程并销毁线程
    connect(m_pthr_doWork, SIGNAL(finished()), m_pthr_doWork, SLOT(deleteLater()));
    // 4. 收到操作信号，线程运行worker的doWork槽函数
    connect(this, SIGNAL(operate(const int)), m_worker_obj, SLOT(doWork(int )));
    // 5. 收到worker的结果信号后，将结果发送给handleResults槽函数
    connect(m_worker_obj, SIGNAL(resultSend(const int)), this, SLOT(handleResults(const int)));
    // 6. 收到worker的结束信号后，执行任务结束显示槽函数workEndDisplay
    connect(m_worker_obj, SIGNAL(endThrSend()), this, SLOT(workEndDisplay()));
    // 7. 启动线程
    m_pthr_doWork->start();
}

Controller::~Controller()
{

  //   delete m_pthr_doWork;   // 不起作用
}


/**
 * @brief 线程结束后，退出线程并销毁线程
 */
void Controller::workEndDisplay()
{
    qDebug() << "workEndDisplay: Thread run finished and work end;";
    // * 注意：加上下面的两条语句，线程只能执行一次，然后就结束
    m_pthr_doWork->quit();
    m_pthr_doWork->wait();
    delete m_pthr_doWork;
}

/**
 * @brief 获取线程中函数执行的结果，并显示当前的线程ID
 * @param rslt： 接收发送的结果信号
 */
void Controller::handleResults(const int rslt)   //处理线程执行的结果
{
    qDebug()<<"Controller::handleResults thread ID:"<< QThread::currentThreadId()<<'\n';
    qDebug()<<"the last result is:"<<rslt;
}

