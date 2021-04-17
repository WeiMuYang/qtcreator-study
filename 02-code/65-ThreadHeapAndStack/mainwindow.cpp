#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

int GlobalOfMain;
extern int GlobalOfChild;   // 外部引用

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_childOne.setThread("Thread-1", 0, 1, 1);
    m_childTwo.setThread("Thread-2", 0, 2, 2);
    m_childThree.setThread("Thread-3", 0, 3, 3);

    m_mainHeap = new int[5];
    for(int i = 0; i < 5 ; ++i)
        m_mainHeap[i] = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
    m_childOne.threadStart();
}
void MainWindow::on_pushButton_2_clicked()
{
    m_childTwo.threadStart();
}
void MainWindow::on_pushButton_3_clicked()
{
    m_childThree.threadStart();
}



void MainWindow::on_pushButton_4_clicked()
{
    qDebug() << "Thread1 Change GlobalOfMain to 11" ;
    m_childOne.ChangeMainGlobal(11);
    qDebug() << "GlobalOfMain = " << GlobalOfMain;
}

void MainWindow::on_pushButton_5_clicked()
{
    qDebug() << "Thread2 Change GlobalOfMain to 22" ;
    m_childTwo.ChangeMainGlobal(22);
    qDebug() << "GlobalOfMain = " << GlobalOfMain;
}

void MainWindow::on_pushButton_6_clicked()
{
    qDebug() << "Thread3 Change GlobalOfMain to 33" ;
    m_childThree.ChangeMainGlobal(33);
    qDebug() << "GlobalOfMain = " << GlobalOfMain;
}

void MainWindow::on_pushButton_7_clicked()
{
    qDebug() << "Thread1 Change GlobalOfChild to 111" ;
    GlobalOfChild = 111;
    m_childThree.display();
}

void MainWindow::on_pushButton_8_clicked()
{
    qDebug() << "Thread2 Change GlobalOfChild to 222" ;
    GlobalOfChild = 222;
    m_childThree.display();
}

void MainWindow::on_pushButton_9_clicked()
{
    qDebug() << "Thread3 Change GlobalOfChild to 333" ;
    GlobalOfChild = 333;
    m_childThree.display();
}

void MainWindow::on_pushButton_10_clicked()
{
    qDebug() << "Thread1 Change Thread2Heap to 1111" ;
    m_childOne.ChangeThreadHeap(&m_childTwo, 1111);
    m_childTwo.display();
}

void MainWindow::on_pushButton_11_clicked()
{
    qDebug() << "Thread2 Change Thread3Heap to 2222" ;
    m_childTwo.ChangeThreadHeap(&m_childThree, 2222);
    m_childThree.display();
}

void MainWindow::on_pushButton_12_clicked()
{
    qDebug() << "Thread3 Change Thread3Heap to 3333" ;
    m_childThree.ChangeThreadHeap(&m_childOne, 3333);
    m_childOne.display();
}

void MainWindow::on_pushButton_13_clicked()
{
    qDebug() << "Thread1 Change Thread2Attrib to 11111" ;
    m_childOne.ChangeThreadAttrib(&m_childTwo, 11111);
    m_childTwo.display();
}

void MainWindow::on_pushButton_14_clicked()
{
    qDebug() << "Thread2 Change Thread3Attrib to 22222" ;
    m_childOne.ChangeThreadAttrib(&m_childThree, 22222);
    m_childThree.display();
}

void MainWindow::on_pushButton_15_clicked()
{
    qDebug() << "Thread3 Change Thread1Attrib to 11111" ;
    m_childThree.ChangeThreadAttrib(&m_childOne, 33333);
    m_childOne.display();
}

