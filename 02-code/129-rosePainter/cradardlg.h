#ifndef ROSE_PIC_H
#define ROSE_PIC_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QMap>
#include "qmath.h"

enum RadarType
{
    Radar=0,  //雷达图
    Spider    //蜘蛛网图
};

enum PointTpye
{
    ScatterPoints=0, //散点图
    LinePoints       //连线图
};

typedef struct RadarData
{
    QColor color;
    QMap<qreal,qreal> datamap;           //key : 角度 value：值
    QMap<qreal,qreal> transitiondatmap;  //key : 角度 value：转换的值


}RadarData;

#define  PI 3.14159

class CRadarDlg  : public QWidget
{
    Q_OBJECT

public:
    CRadarDlg(QWidget *parent = nullptr);
    ~CRadarDlg();

    void setRadarType(RadarType radartype);
    void setPointTpye(PointTpye pointstype);
protected:
    void paintEvent(QPaintEvent *e);

private:
    void init();
    void drawRadarType(QPainter *painter);
    void drawRadar(QPainter *painter);
    void drawSpider(QPainter *painter);
    void drawAxisLabel(QPainter *painter);
    void drawLabel(QPainter *painter);
    void drawData(QPainter *painter);
    void drawScatterPoints(QPainter *painter);
    void drawLinePoints(QPainter *painter);


private:
    RadarType m_radartype;
    PointTpye m_pointstype;
    int m_cylindernum;  //圈数
    int m_lineangle;    //角度，决定多少。默认是30
    int m_Axis_max,m_Axis_min; //最大最小
    QStringList m_AxisLabelList; //标签 刻度标签
    QStringList m_labelList;     //外围标签
    bool m_showAxisLabel;
    bool m_showLabel;

    QMap<int,RadarData> m_datamap;  //key 表示组，value表示对于的值
    QList<QColor> m_colorlist;

};

#endif // ROSE_PIC_H
