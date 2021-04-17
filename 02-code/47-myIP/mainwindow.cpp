#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtNetwork>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString localHostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug() << "localHostName:" << localHostName << endl;
            << "IP Address:" << info.addresses();

    foreach(QHostAddress address, info.addresses())
    {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            qDebug() << address.toString();
    }

    QHostInfo::lookupHost("www.baidu.com",this,SLOT(lookedUp(QHostInfo));


    QList<QNetworkInterface>list = QNetworkInterface::allInterfaces();





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::lookedUp(const QHostInfo &host)
{
    if(host.error() != QHostInfo::NoError){
        qDebug() << "Lookup failed:" << host.errorString();
        return;
    }
    foreach(const QHostAddress &address, host.addresses())
    {
        qDebug() << "Found address:" << address.toString();
    }
}
