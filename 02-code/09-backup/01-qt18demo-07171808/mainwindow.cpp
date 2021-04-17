#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_state = true;
    this->resize(1280,1024);
    QImage imTrue;
    //图片路径可以通过右击工程的图片获取
    imTrue.load(":/img/true.png");
    ui->label->setPixmap(QPixmap::fromImage(imTrue));
//    m_ScrollArea = new QScrollArea(parentWidget());
//    m_ScrollArea->setGeometry(5,20,70,10);
//    m_ScrollArea->setWidget(this);
//    s->setWidget(this);

    // ui->frame->setStyleSheet("border:1px solid rgb(200, 200, 200)");







    // QtableWidget平均分配行列
//    ui->tableWidget12->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget12->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget11->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget11->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget13->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget13->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget21->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget21->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget22->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget22->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget23->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget23->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget31->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget31->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);





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





