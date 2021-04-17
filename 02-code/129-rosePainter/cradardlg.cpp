#include "cradardlg.h"
#include <QPainter>


CRadarDlg ::CRadarDlg (QWidget *parent) : QWidget(parent)
{

    init();

}

CRadarDlg::~CRadarDlg()
{

}

void CRadarDlg::setRadarType( RadarType radartype )
{
    m_radartype = radartype;
}

void CRadarDlg::setPointTpye( PointTpye pointstype )
{
    m_pointstype = pointstype;
}


void CRadarDlg::init()
{
    setRadarType(Radar);
    setPointTpye(LinePoints);    //   ScatterPoints  oR  LinePoints
    m_cylindernum = 5;  //默认6圈
    m_lineangle = 72;   //默认30度
    m_showAxisLabel = true;  // 显示轴标签
    m_showLabel = true;      // 显示外围标签
    m_Axis_min = 0;
    m_Axis_max = 100;
    m_AxisLabelList << "0" << "20" << "40" << "60" << "80" << "100";

    m_colorlist << QColor(136,68,255);
    m_colorlist << QColor(102,170,238);
    m_colorlist << QColor(146,39,143);
    m_colorlist << QColor(238,187,34);
    m_colorlist << QColor(238,187,34);
    m_colorlist << QColor(238,187,34);
    m_colorlist << QColor(141,198,63);
    m_colorlist << QColor(255,242,0);

//    for (int i = 0 ; i < 360; i+=m_lineangle)
//    {
//        m_labelList << QString( char('A' + i) );
//    }
// BUG m_labelList的长度和间隔的角度有关
    m_labelList<<"A" << "E" <<"D" << "C"  << "B";


    RadarData tlist1,tlist2, tlist3;                                // 画的数据和数据的颜色设置地方
    QMap<qreal,qreal> datamap,datamap2, datamap3;
    for (int i = 0; i < 10;++i)
    {
        datamap2 .insert (i*20,i*10);   // (0,0)   ...  (180, 90)   x = 所转的角度   y = 半径
        datamap .insert(i*30,i*5);      // (0,0)   ...  (270, 45)
    }

//    for(int i = 0; i < 5; ++i){
//        datamap3.insert(36, )

//    }
    datamap3.insert(0, 40);     // A
    datamap3.insert(72, 80);    // E
    datamap3.insert(144, 20);   // D
    datamap3.insert(216, 80);   // C
    datamap3.insert(288, 60);   // B


    tlist3.color = QColor(136,68,255, 50);
    tlist2.color = QColor(136,68,255);
    tlist1.color = QColor(146,39,143);;

    tlist1.transitiondatmap = datamap;
    tlist2.transitiondatmap = datamap2;
    tlist3.transitiondatmap = datamap3;

//    m_datamap.insert(0,tlist2);
//    m_datamap.insert(1,tlist1);
//    m_datamap.insert(2,tlist3);
    m_datamap.insert(0,tlist3);


}

/**
 * @brief CRadarDlg::paintEvent
 * @param e
 * @note
当发生一下情况时会产生绘制事件并调用paintEvent()函数:
1.在窗口部件第一次显示时，系统会自动产生一个绘图事件，从而强制绘制这个窗口部件。
2.当重新调整窗口部件的大小时，系统也会产生一个绘制事件。
3.当窗口部件被其他窗口部件遮挡，然后又再次显示出来的时候，就会对那些隐藏的区域产生一个绘制事件。
同时可以调用QWidget::update()或者QWidget::repaint()来强制产生一个绘制事件。二者的区别是:
    repaint()函数会强制产生一个即时的重绘事件,而update()函数只是在Qt下一次处理事件时才调用一次绘制事件。
    如果多次调用update(),Qt会把连续多次的绘制事件压缩成一个单一的绘制事件，这样可避免闪烁现象。
 */
void CRadarDlg::paintEvent( QPaintEvent *e )
{
    QPainter *painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setRenderHint(QPainter::SmoothPixmapTransform);
    painter->setRenderHint(QPainter::TextAntialiasing);

    //添加背景颜色
//  painter->save();
//  painter->setBrush(Qt::blue);
//  painter->drawRect(0,0,width(),height());
//  painter->restore();
//

    drawRadarType(painter);
    drawAxisLabel(painter);
    drawLabel(painter);
    drawData(painter);

}


/**
 * @brief 可以选择蜘蛛图，也可使用雷达图
 * @param painter 默认是雷达图
 */
void CRadarDlg::drawRadarType(QPainter *painter )
{
    switch (m_radartype)
    {
        case Radar:drawRadar(painter);break;
        case Spider:drawSpider(painter);break;
        default:drawRadar(painter);break;
    }
}


/**
 * @brief    实现画雷达底图
 * @param painter
 */
void CRadarDlg::drawRadar(QPainter *painter )
{
    painter->save();
    QPen pen;
    QColor color(Qt::lightGray);
    pen.setWidthF(0.4);
    //pen.setColor(color/*.lighter(100)*/); //添加线的颜色
    painter->setPen(pen);

    QPainterPath looppath;
    int w = width();        // 获取画布的宽度
    int h = height();       // 获取画布的高度

    int count = m_cylindernum;  // 圈数
    int radius = qMin(w,h);     // 直径 = 画布 高度 或者 宽度 的最小值
    int step = radius/(count+1);// 每画一个圆的半径增加的值  加1是为了四周留出空间，写标签
    int x = 0;     // 圆心的x坐标
    int y = 0;     // 圆心的y坐标

    QRectF outrect;
    for (int i = 1; i < count + 1; ++i)
    {
        radius = step*i;
        x = w/2-radius/2;
        y = h/2-radius/2;
        QRectF rect(x,y,radius,radius);  // 圆心和半径确定一个圆  // 只能接收 int 型
        looppath.addEllipse(rect);
        outrect = rect;
    }
    painter->drawPath(looppath);    // 画圆
//

    if (m_lineangle == 0)
    {
        m_lineangle = 90;
    }
    int linecount = 360/m_lineangle;
    int x0 = w/2;    //
    int y0 = h/2;
    int newradius = outrect.height()/2;
    for (int i = 0 ; i < linecount; ++i)
    {
        int x1 = x0 + newradius*qSin(PI*2/linecount*i + PI);   // 加上180度
        int y1 = y0 + newradius*qCos(PI*2/linecount*i + PI);

        painter->drawLine(x0,y0,x1,y1);     // 只能接收 int 型
    }

    painter->restore();

}

void CRadarDlg::drawSpider( QPainter *painter )
{
    painter->save();
    QPen pen;
    QColor color(Qt::lightGray);
    pen.setWidthF(0.4);
    //pen.setColor(color/*.lighter(100)*/); //添加线的颜色
    painter->setPen(pen);

    QPainterPath looppath;
    int w = width();
    int h = height();
    if (m_lineangle == 0)
    {
        m_lineangle =90;
    }

    int  laycount = m_cylindernum;  //默认是几层

    int count = 360/m_lineangle;
    int radius = qMin(w,h)/2;
    int x0 = w/2 ;
    int y0 = h/2;

    for (int j = 1 ; j < laycount+1; ++j)
    {
        int newradius = radius*j/(laycount+1);
        for (int i = 0 ; i < count; ++i)
        {
            int x1 = x0 + newradius*qSin(PI*2/count*i);
            int y1 = y0 + newradius*qCos(PI*2/count*i);
            painter->drawLine(x0,y0,x1,y1);

            int x2;
            int y2;
            if (i == count*2-1)
            {
                x2 = x0 + newradius*qSin(0);
                y2 = y0 + newradius*qCos(0);
            }
            else
            {
                x2 = x0 + newradius*qSin(PI*2/count*(i+1));
                y2 = y0 + newradius*qCos(PI*2/count*(i+1));
            }
            painter->drawLine(x1,y1,x2,y2);
        }
    }
    painter->drawPath(looppath);

    painter->restore();

}

/**
 * @brief     在轴上画刻度标签
 * @param painter
 */
void CRadarDlg::drawAxisLabel( QPainter *painter )
{
    if (!m_showAxisLabel) return;

    painter->save();

    //QPen pen;
    //QColor color(Qt::lightGray);
    //pen.setColor(color/*.lighter(100)*/); //添加线的颜色
    //painter->setPen(pen);


    int  laycount = m_cylindernum;  //默认是几层
    int w = width();
    int h = height();
    int count = 360 / m_lineangle;
    int radius = qMin(w,h)/2;
    int x0 = w/2 ;
    int y0 = h/2;

    QFont font;
    int fontsize = 10;
    if (h > 500)
        fontsize = 15;
    font.setPointSize(fontsize);
    painter->setFont(font);

    for (int j = 0 ; j < laycount+1; ++j)
    {
        int newradius = radius*j/(laycount+1);
        int x1 = x0 + newradius*qSin(PI);
        int y1 = y0 + newradius*qCos(PI)+20;
        if (j < m_AxisLabelList.count())
        {
            painter->drawText(x1,y1,m_AxisLabelList.at(j));
        }
    }

    painter->restore();
}


/**
 * @brief    画外围标签
 * @param painter
 */
void CRadarDlg::drawLabel( QPainter *painter )
{
    if (!m_showLabel)
        return;

    painter->save();

    //QPen pen;
    //QColor color(Qt::lightGray);
    //pen.setColor(color/*.lighter(100)*/); //添加线的颜色
    //painter->setPen(pen);


    int  laycount = m_cylindernum;  //默认是几层
    int w = width();
    int h = height();
    int count = 360/m_lineangle;
    int radius = qMin(w,h)/2;
    int x0 = w/2 ;
    int y0 = h/2;

    QFont font;
    int fontsize = 10;
    if (h > 500)
        fontsize = 15;
    font.setPointSize(fontsize);
    painter->setFont(font);



    for (int i = 0 ; i < count; ++i)
    {
        int newradius = radius*laycount/(laycount+1)+10;
        newradius = newradius+10*qSin(PI*2/count*i);
        int x1 = x0 - newradius*qSin(PI*2/count*i);
        int y1 = y0 - newradius*qCos(PI*2/count*i);

        if (y0 < y1 && x0 < x1)
        {
            y1 -= fontsize*qSin(PI*2/count*i);
        }
        else
        {
            if (x1 < x0)
                x1-=fontsize;
            y1 += fontsize*qSin(PI*2/count*i);
        }

        if (i < m_labelList.count())
        {
            painter->drawText(x1,y1,m_labelList.at(i));
        }

    }

    painter->restore();
}


/**
 * @brief     绘制数据
 * @param painter
 */
void CRadarDlg::drawData( QPainter *painter )
{
    switch(m_pointstype)
    {
    case ScatterPoints:drawScatterPoints(painter);break;
    case LinePoints:drawLinePoints(painter);break;
    default:drawLinePoints(painter);break;
    }

}

/**
 * @brief   将数据画成散点图
 * @param painter
 */
void CRadarDlg::drawScatterPoints( QPainter *painter )
{
    painter->save();

    int w = width();
    int h = height();
    int count = 360/m_lineangle;
    int radius = qMin(w,h)/2*m_cylindernum/(m_cylindernum+1);

    QList<int> keyilist = m_datamap.keys();

    qreal step = 1.0*radius/(m_Axis_max-m_Axis_min);
    foreach (qreal key, keyilist)
    {
        RadarData rdata = m_datamap.value(key);
        QColor color = rdata.color;
        painter->setPen(color.darker(200));
        painter->setBrush(color.darker(200));
        foreach (qreal angle ,rdata.transitiondatmap.keys())
        {
            qreal length = step*rdata.transitiondatmap.value(angle);
            angle+=90; //因为转90
            QPointF certp(w/2 + length*qCos(angle*PI/180),h/2 - length*qSin(angle*PI/180));
            painter->drawEllipse(certp,2,2);

        }
    }

    painter->restore();
}

/**
 * @brief   将数据画成点线图
 * @param painter
 */
void CRadarDlg::drawLinePoints( QPainter *painter )
{
    painter->save();

    int w = width();
    int h = height();
    int count = 360/m_lineangle;
    int radius = qMin(w,h)/2*m_cylindernum/(m_cylindernum+1);

    QList<int> keyilist = m_datamap.keys();

    qreal step = 1.0*radius/(m_Axis_max-m_Axis_min);

    // key代表keyilist中的一个项
    foreach (qreal key, keyilist)
    {
        RadarData rdata = m_datamap.value(key);
        QPainterPath path;
        int  i = 0;
        QPointF startp;

        QColor color = rdata.color;
        painter->setPen(color.darker(200));
        painter->setBrush(color.darker(200));
        foreach (qreal angle ,rdata.transitiondatmap.keys())
        {
            qreal length = step*rdata.transitiondatmap.value(angle);
            angle+=90; //因为转90
            QPointF certp(w/2 + length*qCos(angle*PI/180),h/2 - length*qSin(angle*PI/180));
            painter->drawEllipse(certp,2,2);
            if (i == 0)
            {
                path.moveTo(certp);
                startp = certp;
            }
            else
                path.lineTo(certp);
            ++i;
        }
        path.lineTo(startp);
        painter->setBrush(color.lighter(100));
        painter->drawPath(path);
    }
    painter->restore();
}

