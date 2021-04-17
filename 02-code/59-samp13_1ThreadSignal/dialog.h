#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

// 1. 声明定义的线程类头文件
#include "qdicethread.h"
namespace Ui {
class Dialog;
}
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
protected:
    // 2. 重写关闭窗口事件：关闭窗口即结束进程
    void closeEvent(QCloseEvent *event);
private:
    // 3. 声明子线程对象，用于运行子线程
    QDiceThread threadA;

private slots:
    // 4. 定义槽函数：接收启动线程信号
    void onthreadA_started();
    // 5. 定义槽函数：接收结束线程信号
    void onthreadA_finished();
    // 6. 定义槽函数：接收线程执行的中间结果
    void onthreadA_newValue(int seq, int diceValue);
    void on_btnClear_clicked();

    // 8. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_Paused
    void on_btnDiceEnd_clicked();
    // 9. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_Paused
    void on_btnDiceBegin_clicked();

    // 10. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_stop
    void on_btnStopThread_clicked();
    // 11. 定义槽函数：通过调用继承的start()方法来启动子线程
    void on_btnStartThread_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
