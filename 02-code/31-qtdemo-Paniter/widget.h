#ifndef WIDGET_H
#define WIDGET_H
#include "qcw_indicatorlamp.h"

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
    QcwIndicatorLamp qcw;

};

#endif // WIDGET_H
