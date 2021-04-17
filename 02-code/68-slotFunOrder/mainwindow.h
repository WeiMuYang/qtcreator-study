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

private slots:
    void Process1Clicked();
    void Process2Clicked();
    void Process3Clicked();
    void Process4Clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
