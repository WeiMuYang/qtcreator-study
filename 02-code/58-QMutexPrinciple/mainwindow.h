#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMutex>
#include <mythread.h>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString s = "");
    ~MainWindow();
protected:
    void closeEvent(QEvent *event);
private slots:
    void on_pushButton1_clicked();

private:
    Ui::MainWindow *ui;
    MyThread m_mythread;
};

#endif // MAINWINDOW_H
