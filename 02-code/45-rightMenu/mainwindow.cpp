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
    // 方法1：在界面中添加
    //    // 1.1 添加菜单选项
    //    addAction(new QAction("新增",this));
    //    addAction(new QAction("删除",this));
    //    // 1.2 启动菜单
    //    setContextMenuPolicy(Qt::ActionsContextMenu);

    // 方法2：重写mousePressEvent()方法。(方法3：重写菜单事件)
    // 2.1(3.1) 创建菜单
    m_pMenu_press_click = new QMenu;  //这是右击弹出的菜单
    // 2.2(3.2) 创建菜单选项
    m_paction_add_1 = new QAction("新增",this);
    m_paction_del_1 = new QAction("删除",this);
    // 2.3(3.3) 给菜单添加菜单项
    m_pMenu_press_click->addAction(m_paction_add_1);
    m_pMenu_press_click->addAction(m_paction_del_1);


    // 补充：实现二级菜单
    m_paction_add_2 = new QAction("新增-2级",this);
    m_paction_del_2 = new QAction("删除-2级",this);
    m_pMenu_press_click_2 = new QMenu("二级",this);  //这是右击弹出的菜单
    m_pMenu_press_click_2->addAction(m_paction_add_2);
    m_pMenu_press_click_2->addAction(m_paction_del_2);
    // 添加一条线
    m_pMenu_press_click->addSeparator();
    m_pMenu_press_click->addMenu(m_pMenu_press_click_2);
}

void MainWindow::mainWindowConnect(){

    // 连接信号与槽
    // triggered:当用户激活某个操作时，会发出此信号；
    // 例如，当用户单击菜单选项、工具栏按钮或按某个操作的快捷组合键时，或在调用trigger（）时发出。
    connect(m_paction_add_1, &QAction::triggered, this, &choicePactionAdd_1);
    connect(m_paction_del_1, &QAction::triggered, this, &choicePactionDel_1);
    connect(m_paction_add_2, &QAction::triggered, this, &choicePactionAdd_2);
    connect(m_paction_del_2, &QAction::triggered, this, &choicePactionDel_2);

}


// 2.4 完成鼠标事件的定义
void MainWindow::mousePressEvent(QMouseEvent *event)
{
//        // 确保右键点击，然后跳出菜单.
//        if (event->button() == Qt::RightButton)  {
//            // 在鼠标右击的地方弹出菜单
//            m_pMenu_press_click->exec(event->globalPos());
//        }
//        event->accept();
}


// 3.4 完成菜单事件的定义
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    //让菜单移动到鼠标位置并显示.
    m_pMenu_press_click->exec(event->globalPos());
}

void MainWindow::choicePactionAdd_1()
{
    ui->lineEdit->setText("choicePactionAdd_1");
}

void MainWindow::choicePactionAdd_2()
{
    ui->lineEdit->setText("choicePactionAdd_2");
}

void MainWindow::choicePactionDel_1()
{
    ui->lineEdit->setText("choicePactionDel_1");
}

void MainWindow::choicePactionDel_2()
{
    ui->lineEdit->setText("choicePactionDel_2");
}
