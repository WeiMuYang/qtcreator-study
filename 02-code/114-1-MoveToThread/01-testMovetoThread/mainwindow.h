#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "process_a.h"
#include "process_b.h"

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
    void on_pbnThr01_clicked();

    void on_pbnThr02_clicked();

    void on_pbnThr01_2_clicked();

    void on_pbnThr02_2_clicked();

private:
    Ui::MainWindow *ui;
    ProcessA m_pA;
    ProcessB m_pB;
    QThread* m_ThreadA;
    QThread* m_ThreadB;
};

#endif // MAINWINDOW_H
