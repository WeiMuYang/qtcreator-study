#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QTimer>
#include <QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i=0;i<10;i++)
    {
        tempnum[i] = 0;
    }
    n=0;
    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(SimpleDemo()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SimpleDemo()
{

    QTime t;
    t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    n=qrand()%50+5;
    SimpleDemo(ui->qCustomPlot,tempnum,n);
}
void MainWindow::SimpleDemo(QCustomPlot *CustomPlot,double tempnum[10],int i)
{
    QVector<double> temp(10);
    QVector<double> temp1(10);

    for(int i=8;i>=0;i--)
    {
        tempnum[i+1]=tempnum[i];
    }
    tempnum[0]=n;
    for(int i=0;i<10;i++)
    {

        temp[i] = i;
        temp1[i] =tempnum[i];
    }
    CustomPlot->addGraph();
    CustomPlot->graph(0)->setPen(QPen(Qt::red));
    CustomPlot->graph(0)->setData(temp,temp1);

    CustomPlot->xAxis->setLabel("time");
    CustomPlot->yAxis->setLabel("tempreture/humidity");

    CustomPlot->xAxis->setRange(0,11);
    CustomPlot->yAxis->setRange(0,100);
    CustomPlot->replot();
}
