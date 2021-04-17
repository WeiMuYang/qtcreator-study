#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox->setStyleSheet(QLatin1String("QCheckBox::indicator:unchecked {\n"
                           "width:80px;height:25px; image:url(:/img/Off.png);\n"
                           "}\n"
                           "QCheckBox::indicator:checked {\n"
                           "width:80px;height:25px; image:url(:/img/On.png);\n"
                           "}"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
