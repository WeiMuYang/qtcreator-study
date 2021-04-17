#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QPalette pal = ui->pushButton_3->palette();
    // 1. 设置调色板颜色：红色
    pal.setColor(QPalette::Button,QColor(255,0,0));
    ui->pushButton_3->setPalette(pal);
    // 2. 此属性保存是否自动填充小部件背景。
    ui->pushButton_3->setAutoFillBackground(true);

    // 3.此属性保存按钮边框是否凸起。
    // 此属性的默认值为false。
    // 如果设置了此属性，除非按钮被按下，否则大多数样式不会绘制按钮背景。
    ui->pushButton_3->setFlat(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "press pushButton_2";
}
