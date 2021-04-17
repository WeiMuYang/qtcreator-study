#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ThreadA = new QThread;
    m_ThreadB = new QThread;
    m_pA1.setName("A1");
    m_pA2.setName("A2");

    connect(m_ThreadA, SIGNAL(started()),&m_pA1, SLOT( displayA()));
    connect(m_ThreadB, SIGNAL(started()),&m_pA2, SLOT( displayA()));

    m_pA1.moveToThread(m_ThreadA);
    m_pA2.moveToThread(m_ThreadB);
    // m_ThreadA->start();

    // m_ThreadB->start();

    connect(ui->pbnThrAEnd, SIGNAL(clicked()),this, SLOT(pbnThrAEndclicked()) );
    connect(ui->pbnThrBEnd, SIGNAL(clicked()),this, SLOT(pbnThrBEndclicked()) );
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

void MainWindow::pbnThrAEndclicked(){
    m_pA1.setStop(1);

    m_ThreadA->quit();
    m_ThreadA->wait();

}
void MainWindow::pbnThrBEndclicked(){
    m_pA2.setStop(1);

    m_ThreadB->quit();
    m_ThreadB->wait();
}

