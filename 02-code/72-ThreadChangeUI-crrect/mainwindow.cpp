#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "changestatus.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_clickNum = 0;
    // 1. 创建线程
    m_thrChangeMovie = new CThread();
    m_thrChangeMovie->setData(ui->label, m_clickNum);
    // 2. 创建修改灯的函数
    m_changeS = new ChangeStatus();
    m_changeS->ChangeLightBulb(ui->label, m_clickNum);

    // 3. 启动子线程
    m_thrChangeMovie->thrStart();
    m_thrChangeMovie->thrPause();
    connect(m_thrChangeMovie, SIGNAL(sendCgeStatus(int  )), this, SLOT(receiveStatus(int  )),Qt::DirectConnection);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_clickNum ++;

    if(m_clickNum >= 3)
        m_clickNum = 0;

    m_thrChangeMovie->setData(ui->label , m_clickNum);

    m_thrChangeMovie->thrContinue();

    QThread::sleep(1);


}

void MainWindow::receiveStatus(int s)
{
    m_changeS->ChangeLightBulb(ui->label, s);
    m_thrChangeMovie->thrPause();
}
