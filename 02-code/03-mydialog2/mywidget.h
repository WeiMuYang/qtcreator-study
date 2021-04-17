#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QWizard>
class QErrorMessage;


namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

private slots:
    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MyWidget *ui;
    QErrorMessage *errordlg;

    QWizardPage *createPage1() ;
    QWizardPage *createPage2() ;
    QWizardPage *createPage3() ;

};


#endif // MYWIDGET_H
