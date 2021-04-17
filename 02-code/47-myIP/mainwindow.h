#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QHostInfo;

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
    void lookedUp(const QHostInfo &host);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
