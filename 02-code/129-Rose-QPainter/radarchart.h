#ifndef RADARCHART_H
#define RADARCHART_H

#include <QWidget>
#include <QMap>
#include <QVector>

#ifdef qct
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif

class QDESIGNER_WIDGET_EXPORT RadarChart : public QWidget
#else
class RadarChart : public QWidget
#endif

{
    Q_OBJECT

    Q_PROPERTY(int scalePos READ getScalePos WRITE setScalePos)
    Q_PROPERTY(double startAngle READ getStartAngle WRITE setStartAngle)
    Q_PROPERTY(int sides READ getSides WRITE setSides)
    Q_PROPERTY(int level READ getLevel WRITE setLevel)
    Q_PROPERTY(bool isShowScale READ getIsShowScale WRITE setIsShowScale)
    Q_PROPERTY(bool isShowLegend READ getIsShowLegend WRITE setIsShowLegend)

public:

    explicit RadarChart(QWidget *parent = 0);
    ~RadarChart();

protected:
    void paintEvent(QPaintEvent *);
    void drawPolygon(QPainter *painter);
    void drawLine(QPainter *painter);
    void drawCategories(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawValues(QPainter *painter);
    void drawLegends(QPainter *painter);
    void drawLightRing(QPainter *painter);

private slots:

private:
    double startAngle;    /*开始角度*/
    int sides;      /*几条边*/
    int level;      /*画几层*/
    QVector<QString> categories;     /*各项含义与边数相同*/
    QList<QList<float>> valueList;  /*数据*/

    float maxValue;     /*最大值*/
    float minValue;     /*最小值*/

    int scalePos;       /*标尺位置*/
    bool isShowScale;   /*是否显示标尺*/
    bool isShowLegend;   /*是否显示图例*/

    QColor polygonLineColor;    /*多边形边颜色*/
    QColor polygonColor;        /*多边形颜色*/
    int lineWidth;              /*边宽*/
    QColor lineColor;           /*线颜色*/
    QColor categoriesColor;     /*小标题颜色*/

    QMap<QString, QVector<float>> dataMap;
    QMap<QString, QColor> dataColorMap;

    int randColorValue(int value);

public:
    QSize sizeHint()                        const;
    QSize minimumSizeHint()                 const;

    double getStartAngle()                  const;
    int getSides()                          const;
    int getLevel()                          const;
    int getScalePos()                       const;
    bool getIsShowScale()                   const;
    bool getIsShowLegend()                   const;

    void addData(QString key, QVector<float> list);
    void removeData(QString key);
    void clearDatas();

    void setDataColor(QString key, QColor);

public Q_SLOTS:
    void setStartAngle(double startAngle);
    void setSides(int sides);
    void setLevel(int level);
    void setScalePos(int scalePos);
    void setIsShowScale(bool isShowScale);
    void setIsShowLegend(bool isShowLegend);
    void setCategories(QVector<QString> categories);

};

#endif //RADARCHART_H
