#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_state = true;
    this->resize(1595,1120);

    ui->tableWidget_7->item(0,0)->setBackground(QColor(51, 138, 255));
    ui->tableWidget_7->item(0,1)->setBackground(QColor(233, 233, 241));
    ui->tableWidget_7->item(0,2)->setBackground(QColor(255, 182, 92));

//    m_pStackedLayout = new QStackedLayout();
//    m_pStackedLayout->addWidget(ui->verticalWidget_1);
//    m_pStackedLayout->addWidget(ui->verticalWidget_2);
//    m_pStackedLayout->addWidget(ui->verticalWidget_3);
//    m_pStackedLayout->addWidget(ui->verticalWidget_4);
//    m_pStackedLayout->addWidget(ui->verticalWidget_5);
//    m_pStackedLayout->addWidget(ui->verticalWidget_6);









    QImage imTrue;
    //图片路径可以通过右击工程的图片获取
    imTrue.load(":/img/true.png");
    QLabel *aixLabel = new QLabel("指控备心跳正常");
    aixLabel->setFont(QFont("宋体", 11, QFont::Bold));
    //Optional
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框
    statusBar()->setSizeGripEnabled(false); //设置是否显示右边的大小控制点
    statusBar()->addWidget(aixLabel);


    QLabel *perimg = new QLabel(" ", this);
    QLabel *per1 = new QLabel("数据库连接成功", this);
    per1->setFont(QFont("宋体", 11, QFont::Bold));

    QLabel *per2 = new QLabel("传输连接成功", this);
    per2->setFont(QFont("宋体", 11, QFont::Bold));
    //  addPermanentWidget(QWidget * widget, int stretch = 0) 添加永久性部件，
    // 永久意味着它不能被临时消息（showMessage函数）掩盖，位于最右端，stretch伸缩性为0
    perimg->setPixmap(QPixmap::fromImage(imTrue));
    QPixmap pixmap = QPixmap::fromImage(imTrue);
    QPixmap fitpixmap = pixmap.scaled(10, 10, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放


    perimg->setPixmap(fitpixmap);


    statusBar()->insertPermanentWidget(2, perimg)  ;
    statusBar()->addPermanentWidget(perimg ); //现实永久信息
    statusBar()->addPermanentWidget(per1);
    statusBar()->addPermanentWidget(perimg ); //现实永久信息
    statusBar()->addPermanentWidget(per2);
    statusBar()->addPermanentWidget(perimg ); //现实永久信息



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




void MainWindow::on_pushButton_12_clicked()
{
    ui->verticalWidget_2->setStyleSheet("background-color: rgb(255, 255, 255)");
    ui->verticalWidget_1->setStyleSheet("");
    ui->verticalWidget_3->setStyleSheet("");
    ui->verticalWidget_4->setStyleSheet("");
    ui->verticalWidget_5->setStyleSheet("");
    ui->verticalWidget_6->setStyleSheet("");

   //  m_pStackedLayout->setCurrentIndex(0);
//    ui->gridWidget11->setStyleSheet("background-color: rgb(255, 255, 255)");
//    ui->gridWidget12->setStyleSheet("");
//    ui->gridWidget13->setStyleSheet("");
}
