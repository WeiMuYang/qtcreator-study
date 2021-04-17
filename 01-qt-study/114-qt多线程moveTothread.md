# qt多线程中MoveToThread的用法   

## 1 多线程MoveToThread简介      
- 定义一个继承于QObject的worker类，在worker类中定义一个槽slot函数doWork()，这个函数中定义线程需要做的工作；    
- 在要使用线程的controller类中，新建一个QThread的对象和woker类对象，使用moveToThread()方法将worker对象的事件循环全部交由QThread对象处理；   
- 建立相关的信号函数和槽函数进行连接，然后发出信号触发QThread的槽函数，使其执行工作。  

## 2 Worker类     
```C++
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
/// work.cpp
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

```

## 3 Controller类   
```C++
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

/// Controller.cpp
Controller::Controller(QObject *parent) : QObject(parent) {
    // 1. 创建对象
    m_pthr_doWork = new QThread;
    // m_pthr_doWork->setParent(this);   // 线程最好不用指定父类对象，否则可能内出错
    m_worker_obj = new Worker;
    // 2. 将包含dowork的函数对象，移动到子线程
    m_worker_obj->moveToThread(m_pthr_doWork);

    // 3. 线程结束后，退出线程并销毁线程
    connect(m_pthr_doWork, SIGNAL(finished()), m_pthr_doWork, SLOT(deleteLater()));
    // 4. 收到操作信号，线程运行worker的doWork槽函数
    connect(this, SIGNAL(operate(const int)), m_worker_obj, SLOT(doWork(int )));
    // 5. 收到worker的结果信号后，将结果发送给handleResults槽函数
    connect(m_worker_obj, SIGNAL(resultSend(const int)), this, SLOT(handleResults(const int)));
    // 6. 收到worker的结束信号后，执行任务结束显示槽函数workEndDisplay
    connect(m_worker_obj, SIGNAL(endThrSend()), this, SLOT(workEndDisplay()));
    // 7. 启动线程
    m_pthr_doWork->start();
}

Controller::~Controller()
{
  //   delete m_pthr_doWork;   // 不起作用
}

/**
 * @brief 线程结束后，退出线程并销毁线程
 */
void Controller::workEndDisplay()
{
    qDebug() << "workEndDisplay: Thread run finished and work end;";
    // * 注意：加上下面的两条语句，线程只能执行一次，然后就结束
    m_pthr_doWork->quit();
    m_pthr_doWork->wait();
   //  m_pthr_doWork->deleteLater();
}

/**
 * @brief 获取线程中函数执行的结果，并显示当前的线程ID
 * @param rslt： 接收发送的结果信号
 */
void Controller::handleResults(const int rslt)   //处理线程执行的结果
{
    qDebug()<<"Controller::handleResults thread ID:"<< QThread::currentThreadId()<<'\n';
    qDebug()<<"the last result is:"<<rslt;
}
```
## 4 MainWindow类   

```C++
/**
* Copyright (c)  2020 YWB. All rights reserved
* @projectName   114-3-WorkerAndContrller
* @file          mainwindow.cpp
* @brief         主要完成最外层调用，发信号运行doWork
* @author        Yang Weibin
* @date          2020-11-21 19:08:11
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_pContrlThr = new Controller;
    qDebug() << "main thread:" << QThread::currentThreadId();
}

MainWindow::~MainWindow() {
    delete ui;
    delete m_pContrlThr;
}
void MainWindow::on_pushButton_clicked() {
    // 1. 单击按钮即可发信号，除法doWork
    emit m_pContrlThr->operate(0);
}
```

## 4 注意事项   
1. `QThread::finished()`信号有时候不好用，线程结束事件循环后，才能触发，一般仅仅用于调用`deleteLater`的槽函数   
2. 结束(销毁)一个线程一般是先`quit`再`wait`    
3. work类和thread类不能用`setParent`指定是同一个父类，而且他们必须是继承QObject    
4. **子线程好像不能在自己的线程中进行自行销毁**   


## 5 参考资料   
1. https://blog.csdn.net/huaweijian0324/article/details/80570083   
2. https://blog.csdn.net/zyhse/article/details/106313994?utm_medium=distribute.pc_relevant_download.none-task-blog-baidujs-1.nonecase&depth_1-utm_source=distribute.pc_relevant_download.none-task-blog-baidujs-1.nonecase   
3. https://blog.csdn.net/qq_38410730/article/details/80783902    