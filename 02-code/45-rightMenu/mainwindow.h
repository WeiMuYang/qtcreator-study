#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMouseEvent>
#include <QContextMenuEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mainWindowInit();
    void mainWindowConnect();

    // 2.2 重写鼠标事件
    void mousePressEvent(QMouseEvent *event);

    // 3.2 重写菜单事件
    void contextMenuEvent(QContextMenuEvent *event);

public slots:
    void choicePactionAdd_1();
    void choicePactionAdd_2();
    void choicePactionDel_1();
    void choicePactionDel_2();

private:
    Ui::MainWindow *ui;
    // 2.1.1 定义菜单指针
    QMenu *m_pMenu_press_click;
    QMenu *m_pMenu_press_click_2;

    // 2.1.2 定义菜单选项
    QAction *m_paction_add_1;
    QAction *m_paction_del_1;
    QAction *m_paction_add_2;
    QAction *m_paction_del_2;
};

#endif // MAINWINDOW_H
