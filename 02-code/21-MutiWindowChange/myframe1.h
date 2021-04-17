#ifndef MYFRAME1_H
#define MYFRAME1_H

#include <QFrame>

namespace Ui {
class MyFrame1;
}

class MyFrame1 : public QFrame
{
    Q_OBJECT

public:
    explicit MyFrame1(QWidget *parent = 0);
    ~MyFrame1();

private:
    Ui::MyFrame1 *ui;
};

#endif // MYFRAME1_H
