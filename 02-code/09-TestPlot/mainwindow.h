#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QVector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    double tempnum[10];
    int n;
    void SimpleDemo(QCustomPlot *customPlot,double tempnum[10],int i);
public slots:
    void SimpleDemo();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
