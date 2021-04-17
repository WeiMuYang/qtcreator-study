#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_n_port = 8888;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_waitConnect_clicked()
{
    server  = new Server(m_n_port);
    connect(server, &Server::serverSigToMain, this, &MainWindow::slotupdateserver);
    ui->textEdit->append("创建成功,可以连接");
    ui->Button_waitConnect->setEnabled(false);
}


void MainWindow::slotupdateserver(QString msg)
{
    ui->textEdit->append(msg);
}

