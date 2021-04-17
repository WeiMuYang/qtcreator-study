#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    // 1. 鼠标点击事件
    void mousePressEvent(QMouseEvent * event);

    // 2. 鼠标移动事件
    void mouseMoveEvent(QMouseEvent * event);

    // 3. 鼠标松开(释放)事件
    void mouseReleaseEvent(QMouseEvent * event);

    // 4. 鼠标双击事件
    void mouseDoubleClickEvent(QMouseEvent * event);

    // 5. 滚轮事件
    void wheelEvent(QWheelEvent * event);
    void keyPressEvent(QKeyEvent * event);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
