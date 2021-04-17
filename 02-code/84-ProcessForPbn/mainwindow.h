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
    void process3();
    void process4();

public slots:

    void process1();
    void process2();
    void process34();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    bool m_bl_process1;
    bool m_bl_process2;
    bool m_bl_process3;
    bool m_bl_process4;


};

#endif // MAINWINDOW_H
