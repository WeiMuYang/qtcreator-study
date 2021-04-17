#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->widget,SIGNAL(clicked()),this,SLOT(changeLabel()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeLabel()
{
    ui->label->setText("Widget单击");
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    emit clicked();
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // 如果是鼠标左键按下
    if(event->button() == Qt::LeftButton)
    {
        ui->label->setText("左键按下");
    }
    // 如果是鼠标右键按下
    else if(event->button() == Qt::RightButton)
    {
        ui->label->setText("右键键按下");
    }
}

