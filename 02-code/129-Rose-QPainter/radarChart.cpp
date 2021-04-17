#pragma execution_character_set("utf-8")

#include "radarchart.h"
#include "qpainter.h"
#include "qmath.h"
#include "qtimer.h"
#include <QDebug>
#include <QTime>

RadarChart::RadarChart(QWidget *parent) : QWidget(parent)
{
    startAngle = 270.0;  //  起始角度
    sides = 5;
    level = 5;
    maxValue = 100;
    minValue = 0;

    scalePos = 0;
    isShowScale = true;
    isShowLegend = true;

    for (int i = 0 ; i < sides; i++)
    {
        categories <<  QString('A' + i);
    }


    polygonLineColor = QColor(Qt::lightGray);
    //polygonColor;
    lineWidth = 0.4;
    lineColor = QColor(Qt::lightGray);
    categoriesColor =  QColor(Qt::lightGray);
}

void RadarChart::addData(QString key, QVector<float> list)
{
    dataMap[key] = list;
    qsrand(QTime(0, 0, 0).msecsTo(QTime::currentTime()));
    dataColorMap[key] = QColor(randColorValue(255), randColorValue(255), randColorValue(255));
    update();
}

void RadarChart::removeData(QString key)
{
    dataMap.remove(key);
    dataColorMap.remove(key);
    update();
}

void RadarChart::clearDatas()
{
    dataMap.clear();
    dataColorMap.clear();
    update();
}

void RadarChart::setDataColor(QString key, QColor color)
{
    qsrand(QTime(0, 0, 0).msecsTo(QTime::currentTime()));
    dataColorMap[key] = color;
    update();
}

void RadarChart::setCategories(QVector<QString> categories)
{
    this->categories = categories;
    update();
}

int RadarChart::randColorValue(int value)
{
    int v = rand() % value;
    return v;
}

RadarChart::~RadarChart()
{

}

int RadarChart::getScalePos() const
{
    return this->scalePos;
}

double RadarChart::getStartAngle() const
{
    return this->startAngle;
}

int RadarChart::getSides() const
{
    return this->sides;
}

int RadarChart::getLevel() const
{
    return this->level;
}

bool RadarChart::getIsShowScale() const
{
    return this->isShowScale;
}

bool RadarChart::getIsShowLegend() const
{
    return this->isShowLegend;
}

void RadarChart::setStartAngle(double startAngle)
{
    if(startAngle >= 0 && startAngle < 360)
    {
        if (this->startAngle != startAngle)
        {
            this->startAngle = startAngle;
            update();
        }
    }
}

void RadarChart::setSides(int sides)
{
    if(sides >= 3)
    {
        if (this->sides != sides)
        {
            this->sides = sides;
            if(categories.size() < sides)
            {
                for (int i = sides - categories.size() - 1 ; i < sides; i++)
                {
                    categories << QString("null%0").arg(i);
                }
            }
            update();
        }
    }

}

void RadarChart::setLevel(int level)
{
    if(level > 0)
    {
        if (this->level != level)
        {
            this->level = level;
            update();
        }
    }
}

void RadarChart::setScalePos(int scalePos)
{
    if(scalePos >= 0 && scalePos < sides)
    {
        if (this->scalePos != scalePos)
        {
            this->scalePos = scalePos;
            update();
        }
    }
}

void RadarChart::setIsShowScale(bool isShowScale)
{
    if (this->isShowScale != isShowScale)
    {
        this->isShowScale = isShowScale;
        update();
    }
}

void RadarChart::setIsShowLegend(bool isShowLegend)
{
    if (this->isShowLegend != isShowLegend)
    {
        this->isShowLegend = isShowLegend;
        update();
    }
}

void RadarChart::paintEvent(QPaintEvent *)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    //绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.translate(width / 2, height / 2);
    painter.scale(side / 200.0, side / 200.0);

    //drawLightRing(&painter);
    drawPolygon(&painter);
    drawLine(&painter);
    drawCategories(&painter);
    if(isShowScale)
        drawScaleNum(&painter);
    drawValues(&painter);

    if(isShowLegend)
        drawLegends(&painter);
}

void RadarChart::drawLightRing(QPainter *painter)
{
    int radius = 99;
    painter->save();

    QRadialGradient g(QPoint(0, 0), radius);

    QColor bgColor = QColor(100, 100, 255);

    bgColor.setAlpha(0);
    g.setColorAt(0.1, bgColor);
    bgColor.setAlpha(60);
    g.setColorAt(1.0, bgColor);


    painter->setPen(Qt::NoPen);
    painter->setBrush(g);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);

    painter->restore();
}

void RadarChart::drawPolygon(QPainter *painter)
{
    painter->save();
    QPen pen;
    pen.setWidthF(lineWidth);
    pen.setColor(polygonLineColor); //添加线的颜色
    painter->setPen(pen);

    double startRad = (360 - startAngle) * (3.14 / 180);
    double deltaRad = 360 * (3.14 / 180) / sides;
    double radiusPer = 80.0 / level ;

    double sina, cosa;
    int x, y;
    for(int j = 0 ; j < level ; j++ )
    {
        float newR = radiusPer * (j + 1);
        QPolygonF polygon;
        for (int i = 0; i < sides; i++)
        {
            sina = sin(startRad - i * deltaRad);
            cosa = cos(startRad - i * deltaRad);

            x = newR * cosa;
            y = -newR * sina;
            QPointF point(x, y);
            polygon.append(point);
        }
        painter->drawPolygon(polygon);
    }
    painter->restore();
}

void RadarChart::drawLine(QPainter *painter)
{
    painter->save();
    QPen pen;
    pen.setWidthF(lineWidth);
    pen.setColor(lineColor); //添加线的颜色
    painter->setPen(pen);

    double radius = 80.0 ;

    double startRad = (360 - startAngle) * (3.14 / 180);
    double deltaRad = 360 * (3.14 / 180) / sides;

    double sina, cosa;
    int x, y;

    for (int i = 0; i < sides; i++)
    {
        sina = sin(startRad - i * deltaRad);
        cosa = cos(startRad - i * deltaRad);

        x = radius * cosa;
        y = -radius * sina;
        QPointF point(x, y);
        painter->drawLine(QPointF(0, 0), point);
    }

    painter->restore();
}

void RadarChart::drawCategories(QPainter *painter)
{
    painter->save();
    QPen pen;
    pen.setColor(categoriesColor); //添加线的颜色
    painter->setPen(pen);

    QFont font("Arial", 5, QFont::Bold, false);
    //设置字体的类型，大小，加粗，斜体
    painter->setFont(font);
    QFontMetrics fm = painter->fontMetrics();

    double radius = 80.0 ;

    double startRad = (360 - startAngle) * (3.14 / 180);
    double deltaRad = 360 * (3.14 / 180) / sides;

    double sina, cosa;
    int x, y;

    for (int i = 0; i < sides; i++)
    {
        sina = sin(startRad - i * deltaRad);
        cosa = cos(startRad - i * deltaRad);

        x = radius * cosa;
        y = -radius * sina;
        QPointF point(x, y);

        QRectF titleRect;
        //分8个方向
        if(x == 0 && y > 0)
            //正下
            titleRect = QRectF(point.x() - fm.width(categories.at(i)) / 2, point.y(), fm.width(categories.at(i)), fm.height());
        else if(x == 0 && y < 0)
            //正上
            titleRect = QRectF(point.x() - fm.width(categories.at(i)) / 2, point.y() - fm.height(), fm.width(categories.at(i)), fm.height());
        else if(x > 0 && y == 0)
            //正右
            titleRect = QRectF(point.x(), point.y() - fm.height() / 2, fm.width(categories.at(i)), fm.height());
        else if(x < 0 && y == 0)
            //正左
            titleRect = QRectF(point.x() - fm.width(categories.at(i)), point.y() - fm.height() / 2, fm.width(categories.at(i)), fm.height());
        else if(x > 0 && y > 0)
            //右下
            titleRect = QRectF(point.x(), point.y(), fm.width(categories.at(i)), fm.height());
        else if(x > 0 && y < 0)
            //右上
            titleRect = QRectF(point.x(), point.y() - fm.height(), fm.width(categories.at(i)), fm.height());
        else if(x < 0 && y < 0)
            //左上
            titleRect = QRectF(point.x() - fm.width(categories.at(i)), point.y() - fm.height(), fm.width(categories.at(i)), fm.height());
        else if(x < 0 && y > 0)
            //左下
            titleRect = QRectF(point.x() - fm.width(categories.at(i)), point.y(), fm.width(categories.at(i)), fm.height());
        else
            titleRect = QRectF(point.x(), point.y(), fm.width(categories.at(i)), fm.height());

        painter->drawText(titleRect, Qt::AlignCenter | Qt::AlignTop, categories.at(i));
    }

    painter->restore();
}

void RadarChart::drawScaleNum(QPainter *painter)
{
    painter->save();
    QPen pen;
    pen.setColor(categoriesColor); //添加线的颜色
    painter->setPen(pen);

    QFont font("Arial", 3, QFont::Bold, false);
    //设置字体的类型，大小，加粗，斜体
    painter->setFont(font);
    QFontMetrics fm = painter->fontMetrics();

    double startRad = (360 - startAngle) * (3.14 / 180);
    double deltaRad = 360 * (3.14 / 180) / sides;
    double radiusPer = 80.0 / level ;

    double sina, cosa;
    int x, y;
    float scaleStep = (maxValue - minValue) / level * 1.0;

    for(int j = 0 ; j < level + 1 ; j++ )
    {
        QPointF point;
        if(j <= 0)
        {
            point = QPointF(0.0, 0.0);
        }
        else
        {
            float newR = radiusPer * j;
            sina = sin(startRad - scalePos * deltaRad);
            cosa = cos(startRad - scalePos * deltaRad);

            x = newR * cosa;
            y = -newR * sina;
            point = QPointF(x, y);
        }

        QString scaleNum = QString::number(scaleStep * j + minValue, 'f', 0);

        QRectF titleRect = QRectF(point.x() - fm.width(scaleNum) - 2, point.y(), fm.width(scaleNum), fm.height());

        painter->drawText(titleRect, Qt::AlignCenter | Qt::AlignTop, scaleNum);
    }

    painter->restore();
}

void RadarChart::drawValues(QPainter *painter)
{
    painter->save();

    double startRad = (360 - startAngle) * (3.14 / 180);
    double deltaRad = 360 * (3.14 / 180) / sides;
    double radius = 80.0;

    double sina, cosa;
    int x, y;

    QMap<QString, QVector<float>>::const_iterator it = dataMap.constBegin();
    while (it != dataMap.constEnd())
    {

        QVector<float> data = it.value();
        QPolygonF polygon;
        QColor dataColor = dataColorMap[it.key()];
        QPen dataPen;

        for(int j = 0 ; j < sides; j++)
        {
            sina = sin(startRad - j * deltaRad);
            cosa = cos(startRad - j * deltaRad);
            double r;
            //QPen pointPen;

            float value;
            if(j >= data.size())
            {
                value = minValue;
                r = qAbs( minValue / (maxValue - minValue)) * radius;
            }
            else
            {
                value = data.at(j) ;
                if(value < minValue)
                    value = minValue;
                else if(value > maxValue)
                    value = maxValue;
            }
            r = qAbs((value - minValue) / (maxValue - minValue))  * radius;

            x = r * cosa;
            y = -r * sina;
            QPointF point(x, y);
            polygon.append(point);

            dataPen.setWidthF(1.5);
            dataColor.setAlpha(150);
            dataPen.setColor(dataColor); //添加线的颜色

            painter->setPen(dataPen);
            painter->drawPoint(point);
        }

        QPainterPath painterPath;
        painterPath.addPolygon(polygon);
        painterPath.closeSubpath();

        dataPen.setWidthF(lineWidth);
        //线条色
        dataColor.setAlpha(255);
        dataPen.setColor(dataColor);
        painter->setPen(dataPen);

        painter->drawPath(painterPath);

        //填充色
        dataColor.setAlpha(100);
        painter->fillPath( painterPath, dataColor);

        ++it;
    }

    painter->restore();
}

void RadarChart::drawLegends(QPainter *painter)
{
    painter->save();

    QPen pen;
    pen.setColor(categoriesColor); //添加线的颜色
    painter->setPen(pen);

    QFont font("Arial", 3, QFont::Bold, false);
    //设置字体的类型，大小，加粗，斜体
    painter->setFont(font);
    QFontMetrics fm = painter->fontMetrics();

    float sx = 100 - 1;
    float sy = -100 + 1;

    int i = 0;

    int maxW = 0;
    QMap<QString, QVector<float>>::const_iterator it = dataMap.constBegin();
    while (it != dataMap.constEnd())
    {
        int w = fm.width(it.key());
        if(w > maxW)
            maxW = w;
        ++it;
    }


    QMap<QString, QVector<float>>::const_iterator it2 = dataMap.constBegin();
    while (it2 != dataMap.constEnd())
    {

        QRectF legendNameRect = QRectF(sx - maxW, sy + (fm.height() + 1) * i, fm.width(it2.key()), fm.height());
        QRectF legendColorRect = QRectF(sx - maxW - 1.5 - fm.height(), sy + (fm.height() + 1) * i, fm.height(), fm.height());

        painter->drawText(legendNameRect, Qt::AlignCenter | Qt::AlignTop, it2.key());
        //painter->drawRect(legendColorRect);
        painter->fillRect(legendColorRect, dataColorMap[it2.key()]);
        i++;

        ++it2;
    }


    painter->restore();
}

QSize RadarChart::sizeHint() const
{
    return QSize(100, 100);
}

QSize RadarChart::minimumSizeHint() const
{
    return QSize(50, 50);
}




