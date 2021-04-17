#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "mydialog1.h"
#include "mydialog2.h"
#include "myframe1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void GotoMyDialog1();
    void GotoMyDialog2();
    void GetMyDialog2(QString s);

private slots:
    void on_pushButtonMyFrame1_clicked();

private:
    Ui::MainWindow *ui;
    MyDialog1 *m_dialog1;
    MyDialog2 *m_dialog2;
    MyFrame1 *m_frame1;

};

#endif // MAINWINDOW_H
