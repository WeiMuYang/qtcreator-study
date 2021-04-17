#ifndef MAINWINDOW_H
#define MAINWINDOW_H







#include <QMainWindow>

namespace Ui {
class MainWindow;
}


/**
 * @brief The MainWindow class
 * @contentspage https://www.qt.io/licensing/
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
