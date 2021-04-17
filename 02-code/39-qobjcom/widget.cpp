#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 信号和槽建立关联
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
    // 当pushButton被单击时，调用ButtonClicked()槽函数
}

Widget::~Widget()
{
    delete ui;
}

// 槽函数
void Widget::ButtonClicked()
{
    emit SendMsg(tr("this is the message!"));
    // 该槽函数只是完成发射信号
    // 源端只是发送信号，至于谁接收信号源端是不管的
    // 那么谁来接收这个信号？
    // 可以造一个接收SendMsg信号的函数，并将接收到的字符串显示，因此添加一个新类，并编写接收SendMsg信号的槽函数

}



