#include "qcw_indicatorlamp.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>
QcwIndicatorLamp::QcwIndicatorLamp(QWidget *parent): QWidget(parent)
{
    m_alarm = false;
    m_state = false;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(setState()));
    timer->start(500);


}

void QcwIndicatorLamp::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); 	/* 使用反锯齿(如果可用) */
    painter.translate(width() / 2, height() / 2);	/* 坐标变换为窗体中心 */
    int side = qMin(width(), height());
    painter.scale(side / 200.0, side / 200.0);		/* 比例缩放 */
    painter.setPen(Qt::NoPen);

    int radius = 100;

    /* 外边框 */
    // 线性渐变
    // 其中x1,y1表示渐变起始坐标, x2,y2表示渐变终点坐标
    // 如果只有x相等,则表示垂直线性渐变,如果只有y相等,则表示平行线性渐变,否则就是斜角线性渐变
    QLinearGradient lg1(0, -radius, 0, radius);
    lg1.setColorAt(0, QColor(255, 255, 255));
    lg1.setColorAt(1, QColor(255, 255, 255));
    painter.setBrush(lg1);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);

    /* 内边框 */
    radius -= 8;
    QLinearGradient lg2(0, -radius, 0, radius);
    lg2.setColorAt(0, QColor(255, 255, 255));
    lg2.setColorAt(1, QColor(255, 255, 255));
    painter.setBrush(lg2);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);

    /* 内部指示颜色 */
    radius -= 4;
   // 辐射渐变
  //  QRadialGradient Radial(0,0,120,0,60);    //设置焦点在(0,60),半径120
    QRadialGradient rg(0, 0, radius, 0, -50);
   // 弧度渐变



    if(m_state==false)
    {
                rg.setColorAt(0, QColor(255, 255, 255));
                rg.setColorAt(0.1, QColor(250, 250, 250));
                rg.setColorAt(0.6, QColor(210, 230, 210));
                rg.setColorAt(1, QColor(194, 194, 194));
    }
    else
    {



        rg.setColorAt(0, QColor(255, 255, 255));
        rg.setColorAt(0.1, QColor(150, 240, 155));
        rg.setColorAt(0.6, QColor(80, 230, 80));
        rg.setColorAt(1, QColor(0, 210, 0));
    }

    painter.setBrush(rg);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);
}

void QcwIndicatorLamp::setAlarm(bool alarm)
{
    //	m_alarm = alarm;
    //	update();
}
void QcwIndicatorLamp::setState()
{
    if(m_state==true)
        m_state=false;
    else
        m_state=true;
    update();

}
