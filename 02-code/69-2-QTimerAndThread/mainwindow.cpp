#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pthread = new CThread();
    m_pTimer = new QTimer();
    m_pTimer->moveToThread(m_pthread);  // 更改此对象及其子对象的线程相关性。如果对象有父对象，则无法移动该对象。事件处理将在targetThread中继续。
    m_pTimer->setInterval(1000);
    m_pthread->start();
    connect(m_pthread, SIGNAL(started()), m_pTimer, SLOT(start()));
    connect(m_pTimer, SIGNAL(timeout()), m_pthread ,SLOT(display()), Qt::DirectConnection);



}

MainWindow::~MainWindow()
{
    delete ui;
}
