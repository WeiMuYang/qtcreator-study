#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_bl_minMaxFlag = true;

    // 1. 初始化
    // 1.1 去掉白条
    this->setWindowFlags(Qt::Widget|Qt::FramelessWindowHint);

    // 1.2 设置Tip
    ui->pbnMinMax->setToolTip("最大化");
    ui->pbnHide->setToolTip("最小化");
    ui->pbnClose->setToolTip("关闭");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbnClose_clicked()
{
    // 2. 关闭窗口

    this->close();
}

void MainWindow::on_pbnMinMax_clicked()
{
    // 3. 判断点击次数
    if(m_bl_minMaxFlag){
        // 3.1 偶数是常规
        ui->pbnMinMax->setText("常规");
        ui->pbnMinMax->setToolTip("向下还原");
        this->showMaximized();
    }
    else{
        // 3.2 奇数是最大
        ui->pbnMinMax->setText("最大");
        ui->pbnMinMax->setToolTip("最大化");
        this->showNormal();
    }
    m_bl_minMaxFlag = (!m_bl_minMaxFlag);
}

void MainWindow::on_pbnHide_clicked()
{
    // 4. 最小化窗口
    this->showMinimized();
}
// 5. 下面3个鼠标事件
// 5.1 鼠标点击事件
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    // 当鼠标点到上面的widget的左半部分时，获取点击位置的坐标
    if(e->x() > ui->wgtTop->x() && e->x() < ui->wgtMinMaxCls->x()
            && e->y() > ui->wgtTop->y() && e->y() < ui->wgtTop->y() + ui->wgtMinMaxCls->height() )

        m_pos_lastPos = e->globalPos();
}
// 5.2 鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    // 当鼠标点到上面的widget的左半部分移动,那么窗体也跟着相应移动
    if(e->x() > ui->wgtTop->x() && e->x() < ui->wgtMinMaxCls->x()
            && e->y() > ui->wgtTop->y() && e->y() < ui->wgtTop->y() + ui->wgtMinMaxCls->height() ){
        int dx = e->globalX() - m_pos_lastPos.x();
        int dy = e->globalY() - m_pos_lastPos.y();
        m_pos_lastPos = e->globalPos();
        this->move(x()+dx, y()+dy);
    }
}
// 5.3 鼠标释放事件(可以不写，作用和移动事件一样)
void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    // 当鼠标点到上面的widget的左半部分移动,那么窗体也跟着相应移动
    if(e->x() > ui->wgtTop->x() && e->x() < ui->wgtMinMaxCls->x()
            && e->y() > ui->wgtTop->y() && e->y() < ui->wgtTop->y() + ui->wgtMinMaxCls->height() ){
        int dx = e->globalX() - m_pos_lastPos.x();
        int dy = e->globalY() - m_pos_lastPos.y();
        this->move(x()+dx, y()+dy);
    }
}



