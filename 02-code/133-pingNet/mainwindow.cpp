#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkConfigurationManager>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer;

    m_timer->setInterval(3000);
    m_timer->start();

    connect(m_timer, &QTimer::timeout, this, &MainWindow::OnlineStatus);

}

bool MainWindow::isNetWorkOnline()
{
    QNetworkConfigurationManager mgr;
    return mgr.isOnline();
}

void MainWindow::displayOnlineStatus()
{
    if(isNetWorkOnline())
        qDebug() << "已经联网";
    else
        qDebug() << "已经断网";
}
void MainWindow::OnlineStatus()
{
    QNetworkConfigurationManager mgr;
    if(mgr.isOnline())
        qDebug() << "已经联网";
    else
        qDebug() << "已经断网";
}




MainWindow::~MainWindow()
{
    delete ui;
}
