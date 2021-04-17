#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QTime>

class MyThread: public QThread
{
public:
    MyThread();
    void MySleep(double sec);

protected:
    void run();

private:


};

#endif // MYTHREAD_H
