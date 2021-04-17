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


    ui->tableWidget_3->item(0,0)->setBackground(QColor(51, 138, 255));
    ui->tableWidget_3->item(0,1)->setBackground(QColor(233, 233, 241));
    ui->tableWidget_3->item(0,2)->setBackground(QColor(255, 182, 92));
    QStringList header;


   // ui->verticalWidget->setGeometry(QRect(0, 140, 528, 275));


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





