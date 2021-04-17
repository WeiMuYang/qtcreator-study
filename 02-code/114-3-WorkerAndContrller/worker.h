#ifndef WORKER_H
#define WORKER_H
/**
* Copyright (c)  2020 YWB. All rights reserved
* @projectName   114-3-WorkerAndContrller
* @file          worker.h
* @brief         为线程提供要执行的函数doWork
* @author        Yang Weibin
* @date          2020-11-21 14:00:06
*/

#include <QObject>
#include <QDebug>
#include <QThread>
/**
 * @brief Worker类一定要继承自QObject，才能移到QThread
 */
class Worker : public QObject
{
    Q_OBJECT
public:
    // 1. 继承QObject
    explicit Worker(QObject *parent = nullptr);
    ~Worker();
public slots:
    // 2. 线程要执行的槽函数，执行完成后可以发结束信号
    void doWork(int parameter)  ;

signals:
    // 3. 发送包含执行的结果的信号
    void resultSend(const int result);
    // 4. 发送执行结束的信号
    void endThrSend();
};

#endif // WORKER_H
