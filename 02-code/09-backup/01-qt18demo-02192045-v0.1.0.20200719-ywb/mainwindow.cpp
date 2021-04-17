#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCheckBox>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_state = true;
    this->resize(1600,1120);

    ui->tableWidget_7->item(0,0)->setBackground(QColor(51, 138, 255));
    ui->tableWidget_7->item(0,1)->setBackground(QColor(233, 233, 241));
    ui->tableWidget_7->item(0,2)->setBackground(QColor(255, 182, 92));



    // scrollArea->setWidget(sw);滚动区域和内容窗口绑定` scrollArea->setGeometry(0, 0, 720, 1000); sw->setGeometry(0, 0, 800, 1200);

















    QImage imTrue;
    //图片路径可以通过右击工程的图片获取
    imTrue.load(":/img/true.png");
    QLabel *aixLabel = new QLabel("指控备心跳正常");
    aixLabel->setFont(QFont("宋体", 11, QFont::Bold));
    //Optional
    statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框
    statusBar()->setSizeGripEnabled(false); //设置是否显示右边的大小控制点
    statusBar()->addWidget(aixLabel);


    QLabel *perimg1 = new QLabel(" ", this);
    QLabel *perimg2 = new QLabel(" ", this);
    QLabel *per1 = new QLabel("数据库连接成功", this);
    per1->setFont(QFont("宋体", 11, QFont::Bold));

    QLabel *per2 = new QLabel("传输连接成功", this);
    per2->setFont(QFont("宋体", 11, QFont::Bold));
    //  addPermanentWidget(QWidget * widget, int stretch = 0) 添加永久性部件，
    // 永久意味着它不能被临时消息（showMessage函数）掩盖，位于最右端，stretch伸缩性为0
    perimg1->setPixmap(QPixmap::fromImage(imTrue));
    perimg2->setPixmap(QPixmap::fromImage(imTrue));
    QPixmap pixmap = QPixmap::fromImage(imTrue);
    QPixmap fitpixmap = pixmap.scaled(10, 10, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 按比例缩放


    perimg1->setPixmap(fitpixmap);
    perimg2->setPixmap(fitpixmap);


    statusBar()->addPermanentWidget(perimg1 ); //现实永久信息
    statusBar()->addPermanentWidget(per1);
    statusBar()->addPermanentWidget(perimg2 ); //现实永久信息
    statusBar()->addPermanentWidget(per2);



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




void MainWindow::mianWindowInit(){

     WellsData Well;
     for(int i = 0; i < 22; ++i) {
         Well.m_LabelOfWell.append(ui->label_101);
         Well.m_LabelOfWell.append(ui->label_102);
         Well.m_LabelOfWell.append(ui->label_103);
         Well.m_LabelOfWell.append(ui->label_104);
         Well.m_LabelOfWell.append(ui->label_105);
         Well.m_LabelOfWell.append(ui->label_106);
         Well.m_LabelOfWell.append(ui->label_107);
         Well.m_LabelOfWell.append(ui->label_108);
         Well.m_LabelOfWell.append(ui->label_109);
         Well.m_LabelOfWell.append(ui->label_110);
         Well.m_LabelOfWell.append(ui->label_111);
         Well.m_LabelOfWell.append(ui->label_112);
         Well.m_LabelOfWell.append(ui->label_113);
         Well.m_LabelOfWell.append(ui->label_114);
         Well.m_LabelOfWell.append(ui->label_115);
         Well.m_LabelOfWell.append(ui->label_116);
         Well.m_LabelOfWell.append(ui->label_117);
         Well.m_LabelOfWell.append(ui->label_118);
         Well.m_LabelOfWell.append(ui->label_119);
         Well.m_LabelOfWell.append(ui->label_120);
         Well.m_LabelOfWell.append(ui->label_121);
         Well.m_LabelOfWell.append(ui->label_122);

     }
     for(int i = 0; i < 2; ++i) {
         Well.m_TableOfWell.append(ui->tableWidget_1);
         Well.m_TableOfWell.append(ui->tableWidget_11);
     }

     wellsOfSix.append(Well);
     Well.m_LabelOfWell.clear();
     Well.m_TableOfWell.clear();


     for(int i = 0; i < 22; ++i) {
         Well.m_LabelOfWell.append(ui->label_201);
         Well.m_LabelOfWell.append(ui->label_202);
         Well.m_LabelOfWell.append(ui->label_203);
         Well.m_LabelOfWell.append(ui->label_204);
         Well.m_LabelOfWell.append(ui->label_205);
         Well.m_LabelOfWell.append(ui->label_206);
         Well.m_LabelOfWell.append(ui->label_207);
         Well.m_LabelOfWell.append(ui->label_208);
         Well.m_LabelOfWell.append(ui->label_209);
         Well.m_LabelOfWell.append(ui->label_210);
         Well.m_LabelOfWell.append(ui->label_211);
         Well.m_LabelOfWell.append(ui->label_212);
         Well.m_LabelOfWell.append(ui->label_213);
         Well.m_LabelOfWell.append(ui->label_214);
         Well.m_LabelOfWell.append(ui->label_215);
         Well.m_LabelOfWell.append(ui->label_116);
         Well.m_LabelOfWell.append(ui->label_117);
         Well.m_LabelOfWell.append(ui->label_118);
         Well.m_LabelOfWell.append(ui->label_119);
         Well.m_LabelOfWell.append(ui->label_120);
         Well.m_LabelOfWell.append(ui->label_121);
         Well.m_LabelOfWell.append(ui->label_122);

     }
     for(int i = 0; i < 2; ++i) {
         Well.m_TableOfWell.append(ui->tableWidget_2);
         Well.m_TableOfWell.append(ui->tableWidget_12);
     }

     wellsOfSix.append(Well);
     Well.m_LabelOfWell.clear();
     Well.m_TableOfWell.clear();

     for(int i = 0; i < 22; ++i) {
         Well.m_LabelOfWell.append(ui->label_301);
         Well.m_LabelOfWell.append(ui->label_302);
         Well.m_LabelOfWell.append(ui->label_303);
         Well.m_LabelOfWell.append(ui->label_304);
         Well.m_LabelOfWell.append(ui->label_305);
         Well.m_LabelOfWell.append(ui->label_306);
         Well.m_LabelOfWell.append(ui->label_307);
         Well.m_LabelOfWell.append(ui->label_308);
         Well.m_LabelOfWell.append(ui->label_309);
         Well.m_LabelOfWell.append(ui->label_310);
         Well.m_LabelOfWell.append(ui->label_311);
         Well.m_LabelOfWell.append(ui->label_312);
         Well.m_LabelOfWell.append(ui->label_313);
         Well.m_LabelOfWell.append(ui->label_314);
         Well.m_LabelOfWell.append(ui->label_315);
         Well.m_LabelOfWell.append(ui->label_316);
         Well.m_LabelOfWell.append(ui->label_317);
         Well.m_LabelOfWell.append(ui->label_318);
         Well.m_LabelOfWell.append(ui->label_319);
         Well.m_LabelOfWell.append(ui->label_320);
         Well.m_LabelOfWell.append(ui->label_321);
         Well.m_LabelOfWell.append(ui->label_322);

     }
     for(int i = 0; i < 2; ++i) {
         Well.m_TableOfWell.append(ui->tableWidget_3);
         Well.m_TableOfWell.append(ui->tableWidget_13);
     }

     wellsOfSix.append(Well);
     Well.m_LabelOfWell.clear();
     Well.m_TableOfWell.clear();



 }







//    图层叠置
//    m_pStackedLayout = new QStackedLayout();
//    m_pStackedLayout->addWidget(ui->verticalWidget_1);
//    m_pStackedLayout->addWidget(ui->verticalWidget_2);
//    m_pStackedLayout->addWidget(ui->verticalWidget_3);
//    m_pStackedLayout->addWidget(ui->verticalWidget_4);
//    m_pStackedLayout->addWidget(ui->verticalWidget_5);
//    m_pStackedLayout->addWidget(ui->verticalWidget_6);
