#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qclickwidget.h"

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
    // 2. 定义Widget单击的槽函数
    void mouseClickedWidget(QString s);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
