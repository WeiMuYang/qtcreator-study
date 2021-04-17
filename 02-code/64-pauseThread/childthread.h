#ifndef CHILDTHREAD_H
#define CHILDTHREAD_H

#include <QThread>
#include <QMutex>
#include <QString>


class ChildThread : public QThread
{
public:
    ChildThread(QString name = "");  // 默认构造函数

    void ThreadPause();     // 1. 暂停线程
    void ThreadContinue();  // 2. 继续线程
    void ThreadStop();      // 3. 停止线程
    void ThreadStart();     // 4. 启动线程

protected:
    void run();             // 5. 线程执行内容

private:
    QMutex m_pauseTex;      // 6. 提供线程之间的访问序列化
    QString m_Name;         // 7. 线程的名字
};

#endif // CHILDTHREAD_H
