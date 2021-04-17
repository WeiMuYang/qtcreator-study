#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>

class MyButton:public QWidget
{
    Q_OBJECT         //  添加qt使用信号槽的标记
public:
    // 修改构造函数
    explicit MyButton(QWidget * parent = 0);
signals:
    // 定义信号，信号只需要声明，不需要定义
    void sigClicked();
    void sigClicked(bool check);

};

#endif // MYBUTTON_H
