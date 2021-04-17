#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

signals:    // 添加自定义信号
    // 信号只需要声明，不要给信号写实体代码
    void SendMsg(QString str);

public slots:
    void ButtonClicked();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
