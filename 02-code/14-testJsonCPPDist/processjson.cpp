#include "processjson.h"
#include <QDebug>

#include <iostream>
using namespace std;

ProcessJson::ProcessJson()
{

    createJson();
    AnalysisJsonByJsonCpp();

    // createJson0();
}

void ProcessJson::ChangeToBytes()
{

    QString jsonout ;

    //  方法1. 从Json::Value转 QString  再转 QByteArray
    jsonout = m_RootJson.toStyledString().c_str();

    //   方法2.从 Json::FastWriter  转 QString  再转 QByteArray
    //    Json::FastWriter fw;
    //    jsonout = fw.write(m_RootJson).c_str();


    QByteArray  m_JsonBytes = jsonout.toLatin1();

}


// 序列化
void ProcessJson::createJson()
{
    QDateTime time = QDateTime::currentDateTime();
    QString date = time.toString("yyyy-MM-dd hh:mm:ss");

    // 1. 如果没有嵌套，直接赋值，如果遇到嵌套，由内而外赋值
    m_RootJson ["type"] = "hakzt";
    m_RootJson["sbdw"] = "A01";

    Json::Value status;


    Json::Value deviceStatus;
    Json::Value mmjk;
    mmjk["code"] = "00001";
    mmjk["fsd"] = 1;
    mmjk["sdsj"] = 1;
    mmjk["status"] = 2;
    mmjk["type"] = 1;
    mmjk["tzy"] = 1;
    mmjk["updatetime"] = date.toStdString();
    deviceStatus["mmjk"] = mmjk;
    status["deviceStatus"] = deviceStatus;

    Json::Value lockStatus;
    Json::Value byb;
    byb["code"] = "02001";
    byb["mode"] = 0x00;
    byb["resultsqjg"] = 0x00;
    byb["resultzxjg"] = 0x00;
    byb["type"] = 2;
    byb["updatetime"] = date.toStdString();
    lockStatus["byb"] = byb;

    Json::Value dh;
    dh["code"] = "04001";
    dh["kxtd"] = 1;
    dh["mode"] = 0x00;
    dh["resultsqjg"] = 0x00;
    dh["resultzxjg"] = 0x00;
    dh["type"] = 4;
    dh["updatetime"] = date.toStdString();
    lockStatus["dh"] = dh;

    Json::Value djmb;
    djmb["code"] = "01001";
    djmb["resultdjmb"] = 0;
    djmb["type"] = 1;
    djmb["updatetime"] = date.toStdString();
    lockStatus["djmb"] = djmb;
    status["lockStatus"] = lockStatus;


    Json::Value weaponstatus;
    weaponstatus["bdnm"] = "A01B01C01D01E01F12";
    weaponstatus["weaponType"] = 3;
    weaponstatus["zbzt"] = 1;

    status["weaponstatus"] = weaponstatus;

    // 2. 先有内部，再构造外部；次序变了，外部可能为空
    m_RootJson["status"] = status;

    // 3. Json::Value 转成 QString
    m_JsonOfQString = m_RootJson.toStyledString().c_str();

    qDebug().noquote() << m_JsonOfQString ;

}

// 反序列化
void ProcessJson::AnalysisJsonByJsonCpp()
{
    // 1. QString 强转成 标准的 String
    std::string strValue = m_JsonOfQString.toStdString();
    Json::Reader reader;
    Json::Value root;

    // 2. 利用Json::Reader 将 String 转成 Json::Value
    reader.parse(strValue, root);

    // 3. 依次根据 键值 来取值：
    //   3.1 如果是string，则asString()；


    std::string type = root["type"].asString();
    qDebug() <<  type.c_str();

    //   3.2 如果是Json::Value，则什么都不写，直接赋值给一个Json::Value对象；
    const Json::Value status = root["status"];
    const Json::Value weaponstatus = status["weaponstatus"];
    std::string bdnm = weaponstatus["bdnm"].asString();
    //   3.3 如果是int，则asInt()；
    int weaponType = weaponstatus["weaponType"].asInt();
    int zbzt = weaponstatus["zbzt"].asInt();

    qDebug() << bdnm.c_str();
    qDebug() << weaponType;
    qDebug() << zbzt;
}
