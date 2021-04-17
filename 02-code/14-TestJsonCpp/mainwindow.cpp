#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createJson();
    QString jsonout = m_RootJson.toStyledString().c_str();
    qDebug().noquote() << jsonout ;
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
{
    "type":"nozt",
    "sbdw":"A01B01C01D01E01F12",
    "status": {
        "deStatus" : {
            "mmjk" : {
                "code" : "00001",
                "fsd" : 0,
                "sdsj" : 0,
                "status" : 1,
                "type" : 1,
                "tzy" : 0,
                "updatetime" : "2020-07-15 21:37:17"
            }
        },
        "lockStatus" : {
            "byby" : {
                "code" : "02001",
                "mode" : 0,
                "resultsqjg" : 0,
                "resultzxjg" : 0,
                "type" : 2,
                "updatetime" : "2020-07-15 21:37:17"
            },
            "ddhh" : {
                "code" : "04001",
                "kxtd" : 0,
                "mode" : 0,
                "resultsqjg" : 0,
                "resultzxjg" : 0,
                "type" : 4,
                "updatetime" : "2020-07-15 21:37:17"
            },
            "djmb" : {
                "code" : "01001",
                "resultdjmb" : -1,
                "type" : 1,
                "updatetime" : "2020-07-15 21:37:17"
            }
        },
        "westatus" : {
            "bdnm" : "A01B01C01D01E01F12",
            "weType" : 3,
            "zbzt" : 1
        }
    }
}
*/


void MainWindow::createJson()
{
    QDateTime time = QDateTime::currentDateTime();
    QString date = time.toString("yyyy-MM-dd hh:mm:ss");


    // 1. 创建根结点的三个子结点，由于status是由多个子结点构成，
    // 2. 因此，要由内向外，先写子结点，再赋值给根结点。
    // 3. 次序变了，外部可能为空
    // 4. Value[属性名] = 属性值
    m_RootJson["type"] = "nozt";
    m_RootJson["sbdw"] = "A01";

    Json::Value status;


    Json::Value deStatus;
    Json::Value mmjk;
    mmjk["code"] = "00001";
    mmjk["fsd"] = 1;
    mmjk["sdsj"] = 1;
    mmjk["status"] = 2;
    mmjk["type"] = 1;
    mmjk["tzy"] = 1;
    mmjk["updatetime"] = date.toStdString();
    deStatus["mmjk"] = mmjk;
    status["deStatus"] = deStatus;

    Json::Value lockStatus;
    Json::Value byby;
    byby["code"] = "02001";
    byby["mode"] = 0x00;
    byby["resultsqjg"] = 0x00;
    byby["resultzxjg"] = 0x00;
    byby["type"] = 2;
    byby["updatetime"] = date.toStdString();
    lockStatus["byby"] = byby;

    Json::Value ddhh;
    ddhh["code"] = "04001";
    ddhh["kxtd"] = 1;
    ddhh["mode"] = 0x00;
    ddhh["resultsqjg"] = 0x00;
    ddhh["resultzxjg"] = 0x00;
    ddhh["type"] = 4;
    ddhh["updatetime"] = date.toStdString();
    lockStatus["ddhh"] = ddhh;

    Json::Value djmb;
    djmb["code"] = "01001";
    djmb["resultdjmb"] = 0;
    djmb["type"] = 1;
    djmb["updatetime"] = date.toStdString();
    lockStatus["djmb"] = djmb;
    status["lockStatus"] = lockStatus;


    Json::Value westatus;
    westatus["bdnm"] = "A01B01C01D01E01F12";
    westatus["weType"] = 3;
    westatus["zbzt"] = 1;

    status["westatus"] = westatus;

    // 先有内部，再构造外部；次序变了，外部可能为空
    m_RootJson["status"] = status;

    //直接输出
    qDebug() << "FastWriter:" ;
    Json::FastWriter fw;
    qDebug().noquote() << fw.write(m_RootJson).c_str();

    //缩进输出
    qDebug() << "StyledWriter:";
    Json::StyledWriter sw;
    QString ssss =  sw.write(m_RootJson).c_str();
    qDebug().noquote() << ssss;
}


