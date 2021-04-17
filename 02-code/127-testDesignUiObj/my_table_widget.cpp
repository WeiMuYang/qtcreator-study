#include "my_table_widget.h"
#include <QDebug>

MyTableWidget::MyTableWidget(QWidget *parent) : QTableWidget(parent)
{
    this->setStyleSheet("QHeaderView::section,QtableCornerButton:section{ \
font:18px \"等线\";\
color:white;\
border:1px solid  rgb(112, 127, 76);\
background-color: rgb(112, 127, 76);\
height:30px;\
}\
QHeaderView::item:selected{\
                      background-color:rgba(38,185,154,0.4);\
}\
QTableWidget{\
    background-color: rgba(255, 255, 255, 0);\
    alternate-background-color:#ededed;\
font:18px \"等线\";\
color:#677483;\
border:1px solid #ededed;\
    gridline-color:  rgb(237, 237, 237);\
}\
QTableWidget::item\
{  \
font:14px \"等线\";\
color:#677483;\
outline: 0px;\
}\
QTableWidget::item:selected{\
                       background-color:rgba(38,185,154,0.4);\
}\
");
this->setRowCount(3);
this->setColumnCount(6);
initTableWgt();
 connect(this,SIGNAL(cellChanged(int,int)),this,SLOT(searchTableCheck(int,int)));
}

void MyTableWidget::initTableWgt(){
    // 1.tablewidget属性设定
    this->setSelectionBehavior(QAbstractItemView::SelectRows);     //按行选中
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);  //多行选中
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);      //不可编辑
    this->setShowGrid(false);
    this->setAlternatingRowColors(true);
//    this->horizontalHeader()->setHighlightSections(false);  //防止表头塌陷
//    this->horizontalHeader()->setFixedHeight(40); //设置表头高度
//    this->horizontalHeader()->setFocusPolicy(Qt::NoFocus); //设置表头不可选
    this->setColumnWidth(0, 100);                    //  设置表行宽度
    this->setColumnWidth(1, 250);
    this->setColumnWidth(2, 150);
    this->setColumnWidth(3, 150);
    this->setColumnWidth(4, 150);
    this->setColumnWidth(5, 150);
    this->setColumnWidth(6, 150);
    this->setFocusPolicy(Qt::NoFocus);

    // 2.checkBox 设定及searchTablewidget 表格单元初始化
    for(int i = 0;i < this->rowCount(); i++){
        QTableWidgetItem * tempItem = new QTableWidgetItem;
        tempItem->setText(QString::number( i + 1));
        tempItem->setCheckState(Qt::Unchecked);
        this->setItem(i, 0, tempItem);
        //  行高设置
        this->setRowHeight(i, 40);
    }
    for(int i = 0; i < this->rowCount(); i++){
        //  列循环，因为第一列已经初始化完成，所以计数器从1开始
        for(int j = 1 ;j < this->columnCount();j++){
            if(this->item(i,j) != nullptr){
                this->item(i,j)->setTextAlignment(Qt::AlignCenter);
            }else{
                QTableWidgetItem * tempItem = new QTableWidgetItem;
                tempItem->setTextAlignment(Qt::AlignCenter);
                tempItem->setText("ceshi ao tiezhi");
                this->setItem(i ,j ,tempItem);
            }
        }
    }
}

/**
 * @brief searchTable checkbox响应槽函数
 * @param row  行数
 * @param col  列数
 */
void MyTableWidget::searchTableCheck(int row, int col){
    //  选中事件
   qDebug() << "row:" << row;
   qDebug() << "col:" << col;
   for(int i = 0; i < this->columnCount(); ++i)
    this->itemAt(row,i)->setSelected(true);
}
