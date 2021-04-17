#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString name) :
    QMainWindow(parent), m_mythread(name),
    ui(new Ui::MainWindow)  {
    ui->setupUi(this);
    m_mythread.threadStart();
}

MainWindow::~MainWindow()  {
    delete ui;
}

void MainWindow::closeEvent(QEvent *event)
{
    if(m_mythread.isRunning())
        m_mythread.threadStop();
}

void MainWindow::on_pushButton1_clicked()  {
        // 主线程调用 display

        m_mythread.display("Main display!");
}
