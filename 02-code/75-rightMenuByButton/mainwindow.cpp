#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mainWindowInit();
    mainWindowConnect();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainWindowInit()
{
    // 1.1 创建菜单   -- 第一个按钮
    m_pMenu_click_1 = new QMenu(ui->pushButton_1);  //这是右击弹出的菜单
    // 1.2  创建菜单选项
    m_paction_add_11 = new QAction("新增",this);
    m_paction_del_11 = new QAction("删除",this);
    // 1.3  给菜单添加菜单项
    m_pMenu_click_1->addAction(m_paction_add_11);
    m_pMenu_click_1->addAction(m_paction_del_11);

    // 2.1 创建菜单   -- 第二个按钮
    m_pMenu_click_2 = new QMenu(ui->pushButton_2);  //这是右击弹出的菜单
    // 2.2  创建菜单选项
    m_paction_add_21 = new QAction("新增",this);
    m_paction_del_21 = new QAction("删除",this);
    // 2.3  给菜单添加菜单项
    m_pMenu_click_2->addAction(m_paction_add_21);
    m_pMenu_click_2->addAction(m_paction_del_21);

    // 3. 初始化ContextMenuPolicy属性
    // 3.1 Mainwindow构造函数时初始化QpushButton的属性ContextMenuPolicy
    ui->pushButton_1->setContextMenuPolicy(Qt::CustomContextMenu);
    // 3.2 Mainwindow构造函数时初始化QpushButton的属性ContextMenuPolicy
    ui->pushButton_2->setContextMenuPolicy(Qt::CustomContextMenu);

}

void MainWindow::mainWindowConnect(){

    // 连接信号与槽
    // triggered:当用户激活某个操作时，会发出此信号；
    // 例如，当用户单击菜单选项、工具栏按钮或按某个操作的快捷组合键时，或在调用trigger（）时发出。
    connect(m_paction_add_11, &QAction::triggered, this, &choicePactionAdd_1);
    connect(m_paction_del_11, &QAction::triggered, this, &choicePactionDel_1);
    connect(m_paction_add_21, &QAction::triggered, this, &choicePactionAdd_2);
    connect(m_paction_del_21, &QAction::triggered, this, &choicePactionDel_2);

}



void MainWindow::choicePactionAdd_1() {
    ui->lineEdit->setText("按钮1->添加");
}

void MainWindow::choicePactionAdd_2() {
    ui->lineEdit->setText("按钮2->添加");
}

void MainWindow::choicePactionDel_1() {
    ui->lineEdit->setText("按钮1->删除");
}

void MainWindow::choicePactionDel_2()  {
    ui->lineEdit->setText("按钮2->删除");
}

void MainWindow::on_pushButton_1_customContextMenuRequested(const QPoint &pos)
{
    // pos = QCursor::pos();
    // 在当前光标位置出现
    m_pMenu_click_1->exec(QCursor::pos());
}

void MainWindow::on_pushButton_2_customContextMenuRequested(const QPoint &pos)
{
    // 在当前光标位置出现
    m_pMenu_click_2->exec(QCursor::pos());
}
