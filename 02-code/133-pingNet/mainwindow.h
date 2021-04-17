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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool isNetWorkOnline();

public slots:
    void displayOnlineStatus();
    void OnlineStatus();

private:
    Ui::MainWindow *ui;

    QTimer* m_timer;
};

#endif // MAINWINDOW_H
