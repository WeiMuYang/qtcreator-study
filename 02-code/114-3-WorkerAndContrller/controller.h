#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
* Copyright (c)  2020 YWB. All rights reserved
* @projectName   114-3-WorkerAndContrller
* @file          controller.h
* @brief         用于对线程进行控制
* @author        Yang Weibin
* @date          2020-11-21 14:50:13
*/

#include <QObject>
#include <QThread>
#include <QDebug>
#include "worker.h"

// 用于进行线程控制
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
     ~Controller();

public slots:
    // 1. 接收执行完毕信号的槽函数
    void workEndDisplay();
    // 2. 接收执行结果的槽函数
    void handleResults(const int rslt) ;
signals:
    // 3. 发送启动doWork的信号
    void operate(const int);
private:
    // 4. 子线程指针，指向运行doWork函数的线程对象
    QThread* m_pthr_doWork;
    // 5. worker对象，包含doWork函数的实体
    Worker* m_worker_obj;
};

#endif // CONTROLLER_H
