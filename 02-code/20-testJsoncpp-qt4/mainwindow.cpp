#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_btnParseJson_clicked()
{
    qDebug()<<"begin"<<QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss.zzz]");
    ui->textEditJson->clear();
    QString strValue;
    QString strJson = ui->textEditSource->toPlainText();
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(strJson.toStdString(), root)) {
        qDebug()<<"Failed to parse json";
        return;
    }

    if(root.isMember("state_type"))
    {
        strValue = "state_type";
        strValue = strValue + ":" + root["state_type"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("position"))
    {
        strValue = "position";
        strValue = strValue + ":" + root["position"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result1"))
    {
        strValue = "result1";
        strValue = strValue + ":" + root["result1"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result2"))
    {
        strValue = "result2";
        strValue = strValue + ":" + root["result2"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result3"))
    {
        strValue = "result3";
        strValue = strValue + ":" + root["result3"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result4"))
    {
        strValue = "result4";
        strValue = strValue + ":" + root["result4"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result5"))
    {
        strValue = "result5";
        strValue = strValue + ":" + root["result5"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result11"))
    {
        strValue = "result11";
        strValue = strValue + ":" + root["result11"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result22"))
    {
        strValue = "result22";
        strValue = strValue + ":" + root["result22"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result33"))
    {
        strValue = "result33";
        strValue = strValue + ":" + root["result33"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result44"))
    {
        strValue = "result44";
        strValue = strValue + ":" + root["result44"].asCString();
        ui->textEditJson->append(strValue);
    }
    if(root.isMember("result55"))
    {
        strValue = "result55";
        strValue = strValue + ":" + root["result55"].asCString();
        ui->textEditJson->append(strValue);
    }
    qDebug()<<"end"<<QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss.zzz]");
}

void MainWindow::on_btnBuildJson_clicked()
{
    qDebug()<<"begin"<<QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss.zzz]");
    Json::Value result;
    result["state_type"] = "123456";
    result["position"] = "987";
    result["result1"] = "1";
    result["result2"] = "2";
    result["result3"] = "3";
    result["result4"] = "4";
    result["result5"] = "5";
    result["result11"] = "11";
    result["result22"] = "22";
    result["result33"] = "33";
    result["result44"] = "44";
    result["result55"] = "55";

    Json::FastWriter write;
    QByteArray baValue = write.write(result).c_str();

    ui->textEditSource->setText(baValue);
    qDebug()<<"end"<<QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss.zzz]");
}
