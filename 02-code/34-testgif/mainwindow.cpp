#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_flag = true;

    QMovie *movie = new QMovie(":/img/picture1.gif");


    ui->label->setFixedSize(200,200);
    ui->label->setScaledContents(true);
    ui->label->setMovie(movie);
    movie->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(m_flag){
        QMovie *movie = new QMovie(":/img/picture2.gif");


        QPoint movePoint(15, 15);
        ui->label->move(movePoint);





        ui->label->setMovie(movie);

        ui->label->show();
        movie->start();

        m_flag = !m_flag;

    }else{

        QMovie *movie = new QMovie(":/img/picture1.gif");



        ui->label->setMovie(movie);
        ui->label->show();
        movie->start();


        m_flag = !m_flag;

    }
}
