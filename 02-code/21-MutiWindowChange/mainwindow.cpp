#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 在构造函数中，创建对话框，可以保持，每个MainWindow对象都有一个这样的MyDialog1
    // 若想让MainWindow对象，有多个的MyDialog1对象的话，可以多定义几个成员指针，多new几次
    m_dialog1 = new MyDialog1();
    m_dialog2 = new MyDialog2();
    m_frame1 = new MyFrame1();

    connect(ui->pushButtonMyDialog1,SIGNAL(clicked(bool)),this,SLOT(GotoMyDialog1()));
    connect(ui->pushButtonMyDialog2,SIGNAL(clicked(bool)),this,SLOT(GotoMyDialog2()));
    connect(m_dialog2,SIGNAL(Dialog2Msg(QString)),this,SLOT(GetMyDialog2(QString )));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GotoMyDialog1()
{

    // 非模态：非顶层窗口
    m_dialog1->show();
}

void MainWindow::GotoMyDialog2()
{

    // 模态：顶层窗口
    m_dialog2->exec();
    // 模态解除后，显示Mainwindow
    this->show();

}

void MainWindow::GetMyDialog2(QString s)
{
    ui->label->setText(s);
}


void MainWindow::on_pushButtonMyFrame1_clicked()
{
    m_frame1->show();
}
