#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_pfun_function = new  Function;

    m_pdisplay_display = new DisplayData;

    connect(ui->pushButton_add,  QPushButton::clicked , this , addAndDisplay);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addAndDisplay()
{
    int r;
    m_n_a = ui->lineEdit_a->text().toInt();
    m_n_b = ui->lineEdit_b->text().toInt();

    r = m_pfun_function->add(m_n_a, m_n_b);

    m_pdisplay_display->setResult(r);

    ui->lineEdit_r->setText(QString::number(r));
}

