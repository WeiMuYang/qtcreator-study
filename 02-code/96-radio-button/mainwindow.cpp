#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

/**
* Copyright (c) 2020 MYWB. All rights reserved
* @projectName   96-radio-button
* @file          mainwindow.cpp
* @brief         单选按钮
* @author        杨伟彬
* @date          2020-10-24 13:15:54
*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton_8->setText("RadioButton&2");
    // 1. 设置一个初选项，否则组内将没有任何一个button被选中，不太符合“one of many”的设计。
    ui->buttonGroup00->buttons().at(0)->setChecked(true);
    ui->buttonGroup01->buttons().at(2)->setChecked(true);
    ui->buttonGroup02->buttons().at(2)->setChecked(true);
    // 2. 设置初始状态。
    for(int i = 0; i < ui->buttonGroup02->buttons().length(); ++i){
        ui->buttonGroup02->buttons().at(i)->setDisabled(true);
        ui->buttonGroup02->buttons().at(i)->setChecked(false);
    }
    for(int i = 0; i < ui->buttonGroup01->buttons().length(); ++i){
        ui->buttonGroup01->buttons().at(i)->setDisabled(false);
        ui->buttonGroup01->buttons().at(i)->setChecked(false);
    }



    // 3. 设置信号槽
    // 按钮组00的切换事件和单击事件
    connect(ui->buttonGroup00, SIGNAL(buttonToggled(int,bool)), this, SLOT(buttonGroup00Toggled(int,bool)));
    connect(ui->buttonGroup00, SIGNAL(buttonClicked(int)), this, SLOT(buttonGroup00Clicked(int)));
    // 按钮组01的切换事件和单击事件
    connect(ui->buttonGroup01, SIGNAL(buttonToggled(int,bool)), this, SLOT(buttonGroup01Toggled(int,bool)));
    connect(ui->buttonGroup01, SIGNAL(buttonClicked(int)), this, SLOT(buttonGroup01Clicked(int)));
    // 按钮组02的切换事件和单击事件
    connect(ui->buttonGroup02, SIGNAL(buttonToggled(int,bool)), this, SLOT(buttonGroup02Toggled(int,bool)));
    connect(ui->buttonGroup02, SIGNAL(buttonClicked(int)), this, SLOT(buttonGroup02Clicked(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief       收到按钮组切换信号
 * @param id    按钮组中变化按钮的ID
 * @param flag  按钮组中变化后按钮的状态
 * @note        一个动作可能触发多个按钮变化，那么会触发多次
 */
void MainWindow::buttonGroup00Toggled(int id, bool flag)
{
    // 1. 获取按钮组中，选中按钮的ID
    int tmp = ui->buttonGroup00->checkedId();
    // 2. 获取按钮组中，选中按钮的文本内容
    QString strText = ui->buttonGroup00->checkedButton()->text();
    // 3. 获取按钮组中，选中按钮的对象名
    QString strobjectName = ui->buttonGroup00->checkedButton()->objectName();

    qDebug()<< ui->buttonGroup00->button(id)->text();
    qDebug()<< "checkedButton Text = " << strText;
    qDebug()<< "checkedButton objectName = " << strobjectName;
    qDebug()<< "id = " << id << ";  checkedButton id = " << tmp;
    qDebug()<< "flag = " << flag;

    // 4. 若text是"RadioButton&1"的按钮被选中，执行下面内容
    if(ui->buttonGroup00->checkedButton()->text() == "RadioButton&1" ){
        for(int i = 0; i < ui->buttonGroup02->buttons().length(); ++i){
            ui->buttonGroup02->buttons().at(i)->setDisabled(true);
            ui->buttonGroup02->buttons().at(i)->setChecked(false);
        }
        for(int i = 0; i < ui->buttonGroup01->buttons().length(); ++i){
            ui->buttonGroup01->buttons().at(i)->setDisabled(false);
            ui->buttonGroup01->buttons().at(i)->setChecked(false);
        }
    }
    // 5. 若text是"RadioButton&2"的按钮被选中，执行下面内容
    if(ui->buttonGroup00->checkedButton()->text() == "RadioButton&2"){
        for(int i = 0; i < ui->buttonGroup01->buttons().length(); ++i){
            ui->buttonGroup01->buttons().at(i)->setDisabled(true);
            ui->buttonGroup01->buttons().at(i)->setChecked(false);
        }
        for(int i = 0; i < ui->buttonGroup02->buttons().length(); ++i){
            ui->buttonGroup02->buttons().at(i)->setDisabled(false);
            ui->buttonGroup02->buttons().at(i)->setChecked(false);
        }
    }



}

/**
 * @brief       收到按钮组单击信号
 * @param id    按钮组单击按钮的ID
 * @note        单击一次触发一次
 */
void MainWindow::buttonGroup00Clicked(int id)
{
    // 打印按钮组中，单击按钮的对象名
    qDebug()<< "-------button Clicked:" << ui->buttonGroup00->button(id)->objectName();

}

void MainWindow::buttonGroup01Toggled(int, bool)
{

}

void MainWindow::buttonGroup01Clicked(int)
{

}

void MainWindow::buttonGroup02Toggled(int, bool)
{

}

void MainWindow::buttonGroup02Clicked(int)
{

}
