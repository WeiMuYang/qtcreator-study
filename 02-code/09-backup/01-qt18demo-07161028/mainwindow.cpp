#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_state = true;

    QImage imTrue;
    //图片路径可以通过右击工程的图片获取
    imTrue.load(":/img/true.png");
    ui->label->setPixmap(QPixmap::fromImage(imTrue));




    // QtableWidget平均分配行列
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);




}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    m_state = !m_state;
    QImage image;
    if(m_state){
        image.load(":/img/true.png");
    }else
        image.load(":/img/false.png");
    ui->label->setPixmap(QPixmap::fromImage(image));
    //设置lable相对于父类的位置
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    // https://blog.csdn.net/wuli_dear_wang/java/article/details/82773586
}



