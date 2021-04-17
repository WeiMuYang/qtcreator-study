#include "dataproc.h"

DataProc::DataProc(QObject *parent) :
    QObject(parent)
{
    count = 0;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_data_proc()));

    timer->start(100);
}

void DataProc::slot_data_proc()
{
    qDebug("the Child Thread : %d", QThread::currentThreadId());
    QString str;

    str.sprintf("Counter : %d", count ++);
    emit valueChanged(str);
}

void DataProc::slot_init_value()
{
    qDebug("the slot of Child Thread is running in thread : %d", QThread::currentThreadId());
    count = 0;
}
