#ifndef QCLICKWIDGET_H
#define QCLICKWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QString>


class QClickWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QClickWidget(QWidget *parent = 0);

signals:
    // 1. 定义一个信号
    void clicked(QString   s);

protected:
    // 3. 重写鼠标单击事件和释放事件
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
private:
    QPoint mousePos;


};

#endif // QCLICKWIDGET_H
