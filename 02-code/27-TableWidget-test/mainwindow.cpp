#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    InitTableWidget();
   //  TableWidgetClear();


  //   setTableWidget();



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::TableWidgetClear(){

    // 1. 删除表格中的所有单元格。这也将删除所有选择和标题。
    // 需要重现创建单元格
    ui->tableWidget->clear();

    ui->tableWidget->setItem(0,1,new QTableWidgetItem("你好吗"));
    //  没有new 的话 Item 不能用
    ui->tableWidget->item(0,1)->setFont(QFont("宋体", 5));

    ui->tableWidget->item(0,1)->setText("试试");


}




void MainWindow::InitTableWidget() {

    for(int i = 0; i < ui->tableWidget->rowCount(); ++i)
        for(int j = 0; j < ui->tableWidget->columnCount(); ++j){
            // 1. 为每个单元格申请空间
            ui->tableWidget->setItem(i,j,new QTableWidgetItem(QString::number(i*ui->tableWidget->columnCount() + j + 1)));
            // 2. 设置每个单元格的字体及字号
            ui->tableWidget->item(i,j)->setFont(QFont("宋体", 12));
            // 3. 设置单元格的对齐方式
            ui->tableWidget->item(i,j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

            // 4. 设置奇数行和偶数行不同背景色
            if(i % 2 == 0)
                ui->tableWidget->item(i,j)->setBackgroundColor(QColor(255,255,180));
            else{
                ui->tableWidget->item(i,j)->setBackgroundColor(QColor(255,255,180, 0));
            }

            // 5. 设置字体的颜色
            ui->tableWidget->item(i,j)->setTextColor(QColor(200,111,30)); //设置文字颜色

            // 6. 设置该单元格为屏蔽状态，不能编辑和选中。
            ui->tableWidget->item(i,j)->setFlags(Qt::ItemIsEditable);
        }

    // 6. 设置每列的宽度
    ui->tableWidget->setColumnWidth(0,110);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,130);
    ui->tableWidget->setColumnWidth(3,140);

    // 7. 设置每行的高度
    ui->tableWidget->setRowHeight(0,60);
    ui->tableWidget->setRowHeight(1,70);
    ui->tableWidget->setRowHeight(2,80);

    // 8. 设置渲染效果:背景色，线的颜色，边界的线宽、线型、颜色
    ui->tableWidget->setStyleSheet("background-color: rgb(85, 255, 255);"\
                                   "gridline-color: rgb(0, 5, 200);" \
                                   "border:2px solid #ffaaff;");



}




void MainWindow::CreateItem() {

    // 方法1：
       QTableWidgetItem *item = new QTableWidgetItem("你好");
       item->setBackgroundColor(QColor(255,255,255));
       item->setFont(QFont("宋体", 5));
       ui->tableWidget->setItem(0,0,item);

       // 方法2：
       ui->tableWidget->setItem(0,1,new QTableWidgetItem("你好吗"));
       //  没有new 的话 Item 不能用
       ui->tableWidget->item(0,1)->setFont(QFont("宋体", 5));

       ui->tableWidget->item(1,1)->setText("试试");
}
