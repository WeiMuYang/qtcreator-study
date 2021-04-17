#include "dialog.h"
#include "ui_dialog.h"


// 1. 定义窗口关闭，线程也跟着关闭
void Dialog::closeEvent(QCloseEvent *event)
{   // 窗口关闭事件，必须结束线程
    // 1.1 如果线程还在启动
    if (threadA.isRunning())    {
        // 1.2 结束线程
        threadA.stopThread();
        // 1.3 阻止线程执行，直到线程结束
        threadA.wait();
    }
    // 1.4 表示子类事件中需要它，
    //     否则可能会在子类部件中清除它
    event->accept();
}

Dialog::Dialog(QWidget *parent) : QDialog(parent),  ui(new Ui::Dialog)
{//构造函数
    ui->setupUi(this);
    // 2. 谁调用这个线程，在谁的构造函数中，定义槽函数，并接收子线程的执行中间结果
    connect(&threadA,SIGNAL(started()),this,SLOT(onthreadA_started()));     // 接收开始信号
    connect(&threadA,SIGNAL(finished()),this,SLOT(onthreadA_finished()));   // 接收结束信号
    connect(&threadA,SIGNAL(newValue(int,int)),this,SLOT(onthreadA_newValue(int,int))); // 接收中间结果
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onthreadA_started()  {//线程的started()信号的响应槽函数
    ui->LabA->setText("Thread状态：thread started");
}

void Dialog::onthreadA_finished()  {//线程的 finished()信号的响应槽函数
    ui->LabA->setText("Thread状态：thread finished");
}

// 6. 定义槽函数：接收线程执行的中间结果
void Dialog::onthreadA_newValue(int seq,int diceValue)  {//QDiceThread的newValue()信号的响应槽函数，显示骰子次数和点数
    // 根据点数和次数实时刷新字符串
    QString  str = QString::asprintf("第 %d 次掷骰子，点数为：%d",seq,diceValue);
    ui->plainTextEdit->appendPlainText(str);

    QPixmap pic; //图片显示
    // 根据点数和次数实时刷新图片
    QString filename = QString::asprintf(":/dice/images/d%d.jpg",diceValue);
    pic.load(filename);
    ui->LabPic->setPixmap(pic);
}

void Dialog::on_btnClear_clicked() { //清空文本 按钮
    ui->plainTextEdit->clear();
}

// 8. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_Paused
void Dialog::on_btnDiceEnd_clicked()  {
    //3. 可以对线程的数据实时修改，暂停 掷骰子按钮
    threadA.dicePause();
    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}

// 9. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_Paused
void Dialog::on_btnDiceBegin_clicked()  {
    //开始 掷骰子按钮
    threadA.diceBegin();
    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(true);
}

// 10. 定义槽函数：通过子线程的成员函数修改子线程的属性成员m_stop
void Dialog::on_btnStopThread_clicked()  {//结束线程 按钮
    threadA.stopThread();   // 结束线程的run()函数执行
    threadA.wait();         // 阻止线程执行，直到线程结束

    ui->btnStartThread->setEnabled(true);
    ui->btnStopThread->setEnabled(false);

    ui->btnDiceBegin->setEnabled(false);
    ui->btnDiceEnd->setEnabled(false);
}

// 11. 定义槽函数：通过调用继承的start()方法来启动子线程
void Dialog::on_btnStartThread_clicked()  {//启动线程 按钮
    threadA.start();

    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);

    ui->btnDiceBegin->setEnabled(true);
    ui->btnDiceEnd->setEnabled(false);
}
