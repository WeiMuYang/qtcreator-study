#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <function.h>
#include <display_data.h>

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

    Function *m_pfun_function;
    DisplayData *m_pdisplay_display;

    int m_n_a;
    int m_n_b;


};

#endif // MAINWINDOW_H
