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

    void MySleep(double sec);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void getInputSignal(int bit);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
