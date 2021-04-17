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

    // 1.2 重写菜单事件
    // void contextMenuEvent(QContextMenuEvent *event);


public slots:
    void choicePactionAdd_1();
    void choicePactionAdd_2();
    void choicePactionDel_1();
    void choicePactionDel_2();

private slots:
    void on_pushButton_1_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_2_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    // 1.1 定义菜单指针   -- 第一个PushButton
    QMenu *m_pMenu_click_1;
    // 1.1 定义菜单选项
    QAction *m_paction_add_11;
    QAction *m_paction_del_11;


    // 1.2 定义菜单指针  -- 第二个PushButton
    QMenu *m_pMenu_click_2;

    // 1.2 定义菜单选项
    QAction *m_paction_add_21;
    QAction *m_paction_del_21;


};

#endif // MAINWINDOW_H
