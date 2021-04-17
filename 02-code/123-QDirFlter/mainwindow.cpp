#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pFileFilter = new FileFilter;
    QString contidition  = "*UNIX-book*\\";
    QString path = "H:\\testfile\\01-UNIX-book\\03-Unix环境高级编程";
    m_pFileFilter->filter(path, contidition);



}

MainWindow::~MainWindow()
{
    delete ui;
}

