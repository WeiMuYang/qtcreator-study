#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 1. 只是创建服务器即可
    SimpleTcpSocketServer* pSimpleTcpSocketServer = new SimpleTcpSocketServer;
}

MainWindow::~MainWindow()
{
    delete ui;
}


