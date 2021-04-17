#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_state = true;
    this->resize(1595,1200);
    QImage imTrue;
    //图片路径可以通过右击工程的图片获取
    imTrue.load(":/img/true.png");



    ui->tableWidget_3->item(0,0)->setBackground(QColor(51, 138, 255));
    ui->tableWidget_3->item(0,1)->setBackground(QColor(233, 233, 241));
    ui->tableWidget_3->item(0,2)->setBackground(QColor(255, 182, 92));
   // ui->verticalWidget->setGeometry(QRect(0, 140, 528, 275));


    QScrollArea *s = new QScrollArea(this);
        s->setGeometry(0, 0, 200, 200);
        //垂直滚动条不可见，只能通过鼠标滑动
        s->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        //窗体1，其父窗体为滚动区域
        QWidget *w = new QWidget(s);
        //设置滚动区域的窗体
        s->setWidget(w);
        w->setGeometry(0, 0, 300, 300);

        //在窗体1上添加按钮

  // ：https://blog.csdn.net/u012319493/java/article/details/52155284








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

    //设置lable相对于父类的位置
}






