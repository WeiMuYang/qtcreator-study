#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include "json.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ProcessJson Pro;


}

MainWindow::~MainWindow()
{
    delete ui;
}

/*  Json 格式如下，解析过程，详见 processjson.cpp
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






