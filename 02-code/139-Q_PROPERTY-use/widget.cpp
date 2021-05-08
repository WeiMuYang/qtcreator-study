#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    minValue = 0;

}

double Widget::getMinValue() const
{
    return this->minValue;
}

void Widget::setMinValue(double minValue)
{
    this->minValue = minValue;
    update();
}


Widget::~Widget()
{
    delete ui;
}
