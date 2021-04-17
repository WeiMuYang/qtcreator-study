#include "qclickwidget.h"
#include "mainwindow.h"
#include <QDebug>

QClickWidget::QClickWidget(QWidget *parent) : QWidget(parent)
{
}


void QClickWidget::mousePressEvent(QMouseEvent *ev)
{
    // 将鼠标点击的位置保留在mousePos中
    mousePos = QPoint(ev->x(), ev->y());
}

void QClickWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    // 若鼠标点击的位置和鼠标释放的位置一样，那就发射信号
    // 但是若鼠标按住滑动，那么鼠标点击的位置和鼠标释放的位置不一样，不会发射信号
    if(mousePos == QPoint(ev->x(), ev->y()))
        emit clicked("clicked Widget");
}
