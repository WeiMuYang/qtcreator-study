#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Process();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Process()
{
    for(int i = 0; i < 6; ++i)
    {
        qDebug() << i + 1;
        m_thread.MySleep(1);
    }
}
