#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file;
    QString f = QFileDialog::getOpenFileName(this, QString("选择文件"), QString("/"),QString("TEXT(*.*o)"));
    file.setFileName(f);
    QFile file2(f +".txt");
    QByteArray t ;


    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"can't open "<<endl;
        exit(EXIT_FAILURE);
    }

    if(!file2.open(QIODevice::WriteOnly | QIODevice::Text| QFile::Truncate))
    {
        qDebug()<<"can't open "<<endl;
        exit(EXIT_FAILURE);
    }


    QTextStream str(&file);
    QString line;
    do
    {
        line = str.readLine();
        QTextStream stream(&file2);
        QString qs = line;
        stream.seek(file2.size());
        stream << qs << "\n";
    }while(line.mid(60,13)!="END OF HEADER");


    int sat_num, epoch_num=0;

    while ((line=str.readLine())!="")
    {
        sat_num=line.mid(33,3).toInt();//每个历元的卫星数目
        for(int i=0;i<sat_num;i++)
        {
            line = str.readLine();
            if(line.mid(0,1) == "C" && line.mid(1,2).toInt() >16){
                ;
            }else{
                QTextStream stream(&file2);
                QString qs = line;
                stream.seek(file2.size());
                stream << qs << "\n";
            }
        }
        epoch_num++;

    }
   QString fff = QString::number(epoch_num,10)  +  "\n文件写入：\n";
    ui->text_r->setText("完成写入！\n历元个数：" +   fff + f +".txt");

    file2.close();
    file.close();


}
