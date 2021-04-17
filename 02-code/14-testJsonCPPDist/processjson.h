#ifndef PROCESSJSON_H
#define PROCESSJSON_H


#include "json.h"
#include <QDate>
#include <QString>
#include <QByteArray>

class ProcessJson
{
public:
    ProcessJson();

    QString m_JsonOfQString;

    Json::Value m_RootJson;

    void AnalysisJsonByJsonCpp();

    void ChangeToBytes();
    void createJson();

};

#endif // PROCESSJSON_H
