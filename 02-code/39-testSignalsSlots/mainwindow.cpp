#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyButton *button = new MyButton(ui->widget);


    connect(button, SIGNAL(sigClicked()), this, SLOT(MainWindow::changeLabel()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeLabel()
{
    ui->label->setText("changeLabel()");
}

void MainWindow::changeLabel(bool)
{

}

void MainWindow::changeLabel(bool, int)
{

}
