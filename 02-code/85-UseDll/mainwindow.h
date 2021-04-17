#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "function.h"
#include "display_data.h"


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
    void addAndDisplay();

private:
    Ui::MainWindow *ui;



    int m_n_a;
    int m_n_b;

    Function *m_pfun;
    DisplayData *m_pdisplay;


};

#endif // MAINWINDOW_H
