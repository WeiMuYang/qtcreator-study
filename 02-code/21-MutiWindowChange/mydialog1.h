#ifndef MYDIALOG1_H
#define MYDIALOG1_H

#include <QDialog>

namespace Ui {
class MyDialog1;
}

class MyDialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog1(QWidget *parent = 0);
    ~MyDialog1();



private:
    Ui::MyDialog1 *ui;
};

#endif // MYDIALOG1_H
