#include "childthread.h"
#include <QDebug>
#include "mainwindow.h"

int GlobalOfChild;          // 1. 全局区
extern int GlobalOfMain;

ChildThread::ChildThread()
{
    m_childAttribData = 0;
}

void ChildThread::threadStart()
{
    start();
    qDebug() << m_name << "start.";
}

void ChildThread::threadStop()
{
    qDebug() << m_name << "stop.";
    terminate();
    wait();
}

void ChildThread::setThread(QString name, int data,int numHeap,int numGlobal)
{
    m_name = name;
    m_childAttribData = data;
    m_childHeap = new int[5];
    for(int i = 0; i < 5 ;++i)
        m_childHeap[i] = numHeap * 10;

    GlobalOfChild = numGlobal;

}

void ChildThread::display()
{

    qDebug() << m_name << " " <<  m_childAttribData << " "
             << m_childHeap[0]  << " " << m_childHeap[1]  << " "
             << m_childHeap[2]  << " " << m_childHeap[3]  << " "
             << m_childHeap[4]   << " "<< GlobalOfChild ;

}

void ChildThread::ChangeThreadAttrib(ChildThread *p, int num)
{
    p->m_childAttribData = num;
}

void ChildThread::ChangeThreadGlobal(int g)
{
    GlobalOfChild = g;
}

void ChildThread::ChangeMainGlobal(int g)
{
    GlobalOfMain = g;
}

void ChildThread::ChangeThreadHeap(ChildThread *p, int a)
{
    for(int i = 0; i < 5; ++i)
        p->m_childHeap[i] = a;
}

void ChildThread::run()
{
    display();
}
