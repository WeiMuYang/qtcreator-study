#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->widget, SIGNAL(clicked(QString)), this, SLOT(mouseClickedWidget(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseClickedWidget(QString s)
{
    static int f = 1;

    if(f){
        ui->widget->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui->label->setText(s + f);
    }else{
        ui->widget->setStyleSheet("background-color: rgb(255, 255, 0);");
        ui->label->setText(s + f);
    }
    f = !f;
}
