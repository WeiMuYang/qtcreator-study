#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::add
 * @param a
 * @param b
 * @return
 */

int MainWindow::add(int a,int b)
{
    return a+b;
}

