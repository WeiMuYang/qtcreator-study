#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->combobox->insertItem(3, QIcon( ":/img/new.png" ), "bush");

    // 下拉后字体对齐
    ui->combobox->setItemData(0, Qt::AlignCenter, Qt::TextAlignmentRole);
    ui->combobox->setItemData(1, Qt::AlignCenter, Qt::TextAlignmentRole);
    ui->combobox->setItemData(2, Qt::AlignCenter, Qt::TextAlignmentRole);
    ui->combobox->setItemData(3, Qt::AlignCenter, Qt::TextAlignmentRole);


    connect(ui->combobox, SIGNAL(currentIndexChanged(QString)), this, SLOT(printBoxText(QString )));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printBoxText(QString str)
{
    ui->label->setText(str);
}
