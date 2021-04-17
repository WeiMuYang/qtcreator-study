#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "json\json.h"
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Json::Value root;
        Json::Value arrayObj;
        Json::Value item;


        item["uid"]=Json::Value("http://www.cnblogs.com/chechen/");
        item["fileName"]=Json::Value("mzixi.txt");
        item["time"]=Json::Value("2017.07.28 10:55:22");
        item["type"]=Json::Value("Libcurl HTTP POST JSON");
        item["authList"]=Json::Value("weidong0925@126.com");
        arrayObj.append(item);


        root  = arrayObj;

        QString jsonout = root.toStyledString().c_str();
        QString jsonout1 = item.toStyledString().c_str();

        qDebug().noquote() << jsonout ;
        qDebug().noquote() << jsonout1 ;



//        printf("%s\n",jsonout.c_str());
//        printf("------------------------------------\n");
//        printf("%s",jsonout1.c_str());

//        getchar();



}

MainWindow::~MainWindow()
{
    delete ui;
}
