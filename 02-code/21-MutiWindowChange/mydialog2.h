#ifndef MYDIALOG2_H
#define MYDIALOG2_H

#include <QDialog>
#include <QString>

namespace Ui {
class MyDialog2;
}

class MyDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog2(QWidget *parent = 0);
    ~MyDialog2();

signals:
    void Dialog2Msg(QString m_Msg);


private slots:
    void on_pushButton_clicked();

private:
    Ui::MyDialog2 *ui;
    QString m_Msg;
};

#endif // MYDIALOG2_H
