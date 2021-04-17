#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_start_clicked()
{

}

void Widget::on_pause_clicked()
{

}

void Widget::on_clearTable_clicked()
{

}

void Widget::on_saveTable_clicked()
{

}

void Widget::on_openSerial_clicked()
{

}

void Widget::on_closeSerial_clicked()
{

}
