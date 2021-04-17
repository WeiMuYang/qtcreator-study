#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置画图的父类
    qcw.setParent(ui->groupBox);
    // 从屏幕上（50，50）位置开始（即为左上角的点）
    // 显示一个50*50的界面（宽30，高35）
    qcw.setGeometry(50,50,50,50);
    qcw.setAlarm(false);
    qcw.show();
}

Widget::~Widget()
{
    delete ui;
}
