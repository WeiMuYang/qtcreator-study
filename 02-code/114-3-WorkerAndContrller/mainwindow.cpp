#include "mainwindow.h"
#include "ui_mainwindow.h"

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


MainWindow::~MainWindow()
{
    delete ui;
    delete m_pContrlThr;
}


void MainWindow::on_pushButton_clicked()
{
    // 1. 单击按钮即可发信号，除法doWork
    emit m_pContrlThr->operate(0);
}
