#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

                ui->tableWidget->horizontalHeader()->setHighlightSections(false);  //防止表头塌陷
                ui->tableWidget->horizontalHeader()->setFixedHeight(40); //设置表头高度
                ui->tableWidget->horizontalHeader()->setFocusPolicy(Qt::NoFocus); //设置表头不可选
}

MainWindow::~MainWindow()
{
    delete ui;
}
