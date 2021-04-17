#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "process_a.h"

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

    void pbnThrAEndclicked();
    void pbnThrBEndclicked();

private:
    Ui::MainWindow *ui;
    ProcessA m_pA1;
    ProcessA m_pA2;
    QThread* m_ThreadA;
    QThread* m_ThreadB;
};

#endif // MAINWINDOW_H
