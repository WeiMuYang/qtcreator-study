#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void buttonGroup00Toggled(int,bool);
    void buttonGroup00Clicked(int);
    void buttonGroup01Toggled(int,bool);
    void buttonGroup01Clicked(int);
    void buttonGroup02Toggled(int,bool);
    void buttonGroup02Clicked(int);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
