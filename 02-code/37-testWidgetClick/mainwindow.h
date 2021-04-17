#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void clicked();
public slots:
    void changeLabel();



private:
    Ui::MainWindow *ui;
protected:
    virtual void mouseReleaseEvent(QMouseEvent * ev);
    virtual void mousePressEvent(QMouseEvent *event);


};

#endif // MAINWINDOW_H
