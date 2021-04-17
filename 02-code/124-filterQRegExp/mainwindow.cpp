#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString pattern = "(.)*others";
    QRegExp rx(pattern);
     bool  match  =  rx.exactMatch( "adfkljklf/others/sadfdsd" );
    if(match)
        qDebug() << "ok";



}

MainWindow::~MainWindow()
{
    delete ui;
}

