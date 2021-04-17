#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 1. new出来的对象可以正常运行，因此一定要保证对象是new出来的
    A* m_pa = new A;
    connect(ui->pushButton,SIGNAL(clicked()), m_pa, SLOT(process()));


    // 2. 栈区对象放在这里单击按钮，没有反应，
    //    放在属性成员里面单击有反应，但是提示： HEAP[116-testdeleteLater.exe]
    // A m_a;
    //  connect(ui->pushButton,SIGNAL(clicked()), &m_a, SLOT(process()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

