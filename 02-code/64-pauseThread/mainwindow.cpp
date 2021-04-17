#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString name) :
    QMainWindow(parent),m_childThread(name),    // 用初始化列表进行初始化
    ui(new Ui::MainWindow) {
{
    ui->setupUi(this);
    ui->pushButton->setText("暂停");
    m_ClickTime = 0;
    m_childThread.ThreadStart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(m_childThread.isRunning())
        m_childThread.ThreadStop();
}

void MainWindow::on_pushButton_clicked()
{
    m_ClickTime++;
    if(m_ClickTime % 2){
        m_childThread.ThreadPause();
        ui->pushButton->setText("继续");
    }
    else{
        m_childThread.ThreadContinue();
        ui->pushButton->setText("暂停");
    }
}
