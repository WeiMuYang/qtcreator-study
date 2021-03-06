#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cthread.h>

namespace Ui {
class MainWindow;
}

class ChangeStatus;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void receiveStatus(int s);

private:
    Ui::MainWindow *ui;
    CThread *m_thrChangeMovie;
    int m_clickNum;
    ChangeStatus *m_changeS;
};

#endif // MAINWINDOW_H
