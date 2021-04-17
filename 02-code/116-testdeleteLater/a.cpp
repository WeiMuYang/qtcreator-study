#include "a.h"
#include <QThread>
#include <QDebug>

A::A(QObject *parent) : QObject(parent)
{
    // 1. 当对象收到结束信号，调用释放空间的槽函数
    connect(this, SIGNAL(endsig()), this, SLOT(myDelete()));
}

void A::process()
{
    for(int i = 0; i < 5; ++i){
        qDebug() << i ;
        QThread::msleep(300);
    }
    // process执行结束发信号
    // (PS：同一个对象通过信号槽调用挺别扭，纯碎举例子而已)
    emit endsig();
}

void A::myDelete(){
    qDebug() << "process finished!";
    // 1. 对象自行销毁
    // this->deleteLater();
    // 2. 或将对象立即销毁均可，因此一定要保证对象是new出来的
    delete this;
}
