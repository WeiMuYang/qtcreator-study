#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#define CLINET_COUNT 2000  //客户端的数量
void testSimpleTcpSocketClientDemo();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    testSimpleTcpSocketClientDemo();
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief 同步线程池的方式模拟多个客户端与服务器端交互： QThreadPool + QRunnable
 */
void testSimpleTcpSocketClientDemo()
{
    QTime oTime;
    oTime.start();

    for (int nIndex = 0; nIndex < CLINET_COUNT; ++nIndex) {
        ClientRunnable* pRunnable = new ClientRunnable; // 该线程只完成一件事，就是
        // 1. QRunnable 的autoDelete默认是true，
        //    QRunnable 的子类run函数执行完，线程池会自动帮你删除该对象。
        pRunnable->setAutoDelete(false);
        // 2. 每个Qt应用程序都有一个全局的QThreadPool对象，可通过方法globalInstance()获得
        //    在全局的QThreadPool对象中运行pRunnable
        QThreadPool::globalInstance()->start(pRunnable);
    }
    // 3. 等待所有毫秒退出（以毫秒为单位），然后从线程池中删除所有线程。
    //    如果删除了所有线程，则返回true；否则，返回false。 否则返回false。
    //    如果毫秒为-1（默认值），则忽略超时（等待最后一个线程退出）。
    QThreadPool::globalInstance()->waitForDone(30 * 1000); // 30s
    qDebug() << "connect count: " << CLINET_COUNT << "total time: " << (double)oTime.elapsed() / double(1000) << "s";
}



