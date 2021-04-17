#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 启动移动事件
    this->setMouseTracking(true);
    ui->centralWidget->setMouseTracking(true);
    ui->label_1->setMouseTracking(true);
    ui->label_2->setMouseTracking(true);
    ui->label_3->setMouseTracking(true);
    ui->label_4->setMouseTracking(true);
    ui->label_5->setMouseTracking(true);
    ui->verticalWidget->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 1. 鼠标的点击事件
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // x()和y()返回距离窗体的相对位置，返回值是int
    ui->label_1->setText("点击：\n" + QString("X = ") + QString::number(event->x()) +"\n" + "Y = " + QString::number(event->y()));
    if(event->button() == Qt::LeftButton)
        ui->label_2->setText("左键");
    else if(event->button() == Qt::RightButton)
        ui->label_2->setText("右键");


    int x_min = ui->label_6->pos().x();
    int y_min = ui->label_6->pos().y();
    int x_max = x_min + ui->label_6->width();
    int y_max = y_min + ui->label_6->height();

    if(event->button() == Qt::LeftButton &&
            event->x() > x_min && event->x() < x_max &&
            event->y() > y_min && event->y() < y_max)
        ui->label_6->setText("左击点在此区域");
    else if(event->button() == Qt::RightButton &&
            event->x() > x_min && event->x() < x_max &&
            event->y() > y_min && event->y() < y_max)
        ui->label_6->setText("右击点在此区域");
    else
        ui->label_6->setText(" ");
}
// 2. 鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

    statusBar()->showMessage("移动位置：" + QString("X：") + QString::number(event->x()) + "Y：" + QString::number(event->y()));
}
// 3. 鼠标释放事件
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    ui->label_3->setText("鼠标释放绝对位置：\n" + QString("X：") + QString::number(event->globalX()) + "\nY：" + QString::number(event->globalY())
                      +"\n鼠标释放相对位置：\n" + QString("X：") + QString::number(event->x()) + "\nY：" + QString::number(event->y()));
}
// 4. 鼠标双击事件
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{                                                                       // QString::number(value, 'f', 2);
    ui->label_4->setText("鼠标双击位置：\n" + QString("X：") + QString::number(event->x()) + "\nY：" + QString::number(event->y()));

}
// 5. 滚轮事件
void MainWindow::wheelEvent(QWheelEvent *event)
{

    if(event->delta()>0)
        ui->label_5->setText("上滚");
    else if(event->delta() < 0)
        ui->label_5->setText("下滚");
    else
        ui->label_5->setText("未滚");
}

//键盘事件
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    switch (event->key())
    {
    case Qt::Key_Escape:
        qDebug() <<"ESC";
        break;
    case Qt::Key_F1:
        qDebug() <<"F1";
        break;
    case Qt::Key_F2:
        qDebug() <<"F2";
        break;
    case Qt::Key_5:
        qDebug() <<"5";
        break;
    case Qt::Key_Back:
        qDebug() <<"Back";
        break;
    case Qt::Key_Enter:
        qDebug() <<"Enter";
        break;
    case Qt::Key_A:
        qDebug() <<"A";
        break;
    case Qt::Key_B:
        qDebug() <<"B";
        break;
    case Qt::Key_C:
        qDebug() <<"C";
        break;
    default:
        qDebug() << event->key();
        break;
    }
}




