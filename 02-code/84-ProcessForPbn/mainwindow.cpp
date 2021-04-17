#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_bl_process1 = false;
    m_bl_process2 = false;
    m_bl_process3 = false;
    m_bl_process4 = false;

    connect(ui->pushButton,SIGNAL(clicked(bool)), this, SLOT(process1()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)), this, SLOT(process2()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)), this, SLOT(process34()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::process1()
{
    if(!m_bl_process1  && !m_bl_process2  && !m_bl_process3  && !m_bl_process4)
    {

        // ui->pushButton->blockSignals(true);

        for(int i = 0; i < 6; ++i){
            qDebug() << i+1 << "process1 running";
            QThread::sleep(1);
        }
        m_bl_process1 = true;

        // ui->pushButton->blockSignals(false);
    }else{

        qDebug() << "m_bl_process1 error";
    }
}

void MainWindow::process2()
{
    if(m_bl_process1  && !m_bl_process2  && !m_bl_process3  && !m_bl_process4)
    {
        // ui->pushButton_2->blockSignals(true);

        for(int i = 0; i < 6; ++i){
            qDebug() << i+1 << "process2 running";


            ui->textEdit_2->append(QString::number(i +1) + "process2 running");
            ui->textEdit_2->repaint();


            if(i % 2 == 0)
                ui->label->setStyleSheet("border-image: url(:/img/true.png);");
            else
                ui->label->setStyleSheet("border-image: url(:/img/error.png);");


            QThread::sleep(1);
            m_bl_process2 = true;

            // ui->pushButton_2->blockSignals(false);
        }
    }else{

        qDebug() << "m_bl_process2 error";
    }
}



void MainWindow::process34(){



    process3();

    QThread::sleep(2);

    process4();

}


void MainWindow::process3()
{
    if(m_bl_process1  && m_bl_process2  && !m_bl_process3  && !m_bl_process4)
    {


       // ui->pushButton_3->blockSignals(true);
        for(int i = 0; i < 6; ++i){

            qDebug() << i+1 << "process3 running";
            QThread::sleep(1);
            m_bl_process3 = true;

          //   ui->pushButton_3->blockSignals(false);
        }
    }else{

        qDebug() << "m_bl_process3 error";
    }
}

void MainWindow::process4()
{
    if(m_bl_process1  && m_bl_process2  &&m_bl_process3  && !m_bl_process4)
    {
        for(int i = 0; i < 6; ++i){
            qDebug() << i+1 << "process4 running";
            QThread::sleep(1);
            m_bl_process4 = true;
        }
    }else{

        qDebug() << "m_bl_process 4 error";
    }
}




void MainWindow::on_pushButton_4_clicked()
{

    ui->textEdit_2->clear();
    m_bl_process1 = false;
    m_bl_process2 = false;
    m_bl_process3 = false;
    m_bl_process4 = false;
}
