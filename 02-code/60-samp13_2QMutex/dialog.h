#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
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
    void closeEvent(QCloseEvent *event);

private slots:
    // 1. 定义槽函数：接收启动线程信号
    void onthreadA_started();
    // 2. 定义槽函数：接收结束线程信号
    void onthreadA_finished();
    // 3. 定时处理读取子线程数据 (新增)
    void onTimeOut();

    void on_btnClear_clicked();
    // 4. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_Paused
    void on_btnDiceEnd_clicked();
    // 5. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_Paused
    void on_btnDiceBegin_clicked();
    // 6. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_stop
    void on_btnStopThread_clicked();
    // 7. 定义槽函数：通过调用继承的start()方法来启动子线程
    void on_btnStartThread_clicked();
private:
    Ui::Dialog *ui;
    // 8. 定义属性成员用来存储子线程获取的数据
    int mSeq,mDiceValue;
    // 9. 声明子线程对象，用于运行子线程
    QDiceThread threadA;
    // 10. 声明定时器对象，用于定时
    QTimer mTimer;//定时器
};

#endif // DIALOG_H
