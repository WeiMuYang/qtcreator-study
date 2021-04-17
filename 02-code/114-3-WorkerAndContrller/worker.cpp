#include "worker.h"

/**
 * @brief 构造函数
 * @param parent:
 */
Worker::Worker(QObject *parent) : QObject(parent)
{
    qDebug() << "Worker()" << "thread:" << QThread::currentThreadId();
}

Worker::~Worker()
{
    qDebug() << "~Worker()" << "thread:" << QThread::currentThreadId();
}

/**
 * @brief 线程要执行的函数
 * @param parameter：     从信号中传递的参数，只执行自增
 */
void Worker::doWork(int parameter)                        //doWork定义了线程要执行的操作
{
    qDebug()<<"do work thread ID:"<< QThread::currentThreadId();
    for(int i = 0;i != 5; ++i)   {
        ++parameter;
        QThread::msleep(500);
        qDebug()<< parameter;
    }

    emit resultSend(parameter);    // 发送工作的结果
    emit endThrSend();             // 发送结束信号
}
