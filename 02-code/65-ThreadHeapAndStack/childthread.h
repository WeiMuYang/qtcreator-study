#ifndef CHILDTHREAD_H
#define CHILDTHREAD_H

#include <QThread>
#include <QString>


class ChildThread : public QThread
{
public:
    ChildThread();

    void threadStart();
    void threadStop();
    void setThread(QString name, int data,int numHeap,int numGlobal);
    void display();
    int m_childAttribData;  // 1. 普通属性成员(方便演示设置公有)
    int *m_childHeap;       // 2. 堆区(方便演示设置公有)

    void ChangeThreadAttrib(ChildThread *p, int n);
    void ChangeThreadHeap(ChildThread *p, int arr);
    void ChangeThreadGlobal( int g);
    void ChangeMainGlobal( int g);
protected:
    void run();

private:
    QString m_name;

};

#endif // CHILDTHREAD_H
