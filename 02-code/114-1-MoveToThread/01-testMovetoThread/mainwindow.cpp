#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ThreadA = new QThread;
    m_ThreadB = new QThread;

    connect(m_ThreadA, SIGNAL(started()),&m_pA, SLOT( displayA()));
    connect(m_ThreadB, SIGNAL(started()),&m_pB, SLOT( displayB()));
    m_pA.moveToThread(m_ThreadA);
    // m_ThreadA->start();
    m_pB.moveToThread(m_ThreadB);
    // m_ThreadB->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbnThr01_clicked()
{
    m_ThreadA->start();
}

void MainWindow::on_pbnThr02_clicked()
{
    m_ThreadB->start();
}

void MainWindow::on_pbnThr01_2_clicked()
{
    m_pA.setStop(1);
    m_ThreadA->quit();
    m_ThreadA->wait();
}

void MainWindow::on_pbnThr02_2_clicked()
{
    m_pB.setStop(1);
    m_ThreadB->terminate();
//    m_ThreadB->quit();
//    m_ThreadB->wait();
}
