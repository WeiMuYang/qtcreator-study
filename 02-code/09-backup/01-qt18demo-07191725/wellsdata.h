#ifndef WELLSDATA_H
#define WELLSDATA_H
#include <QVector>
#include <QLabel>
#include <QTableWidget>

class WellsData
{
public:
    WellsData();
    QVector <QLabel *> m_LabelOfWell;         // 井的标签，22个
    QVector <QTableWidget *> m_TableOfWell;   // 井的表，2个
};

#endif // WELLSDATA_H
