#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QMutex>

class MyThread: public QThread
{
public:
    MyThread(QString name = "");

    void threadStart();
    void threadStop();
    // 1. 打印函数
    void display(QString s);
protected:
    void run();

private:
    QString m_name;
    QMutex m_mutex;
};

#endif // MYTHREAD_H
