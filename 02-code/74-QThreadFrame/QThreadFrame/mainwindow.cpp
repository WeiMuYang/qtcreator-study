#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataProc = new DataProc;
    childThread = new QThread(this);
    dataProc->moveToThread(childThread);

    connect(ui->exitButton, SIGNAL(clicked()), childThread, SLOT(quit()));
    connect(ui->setButton, SIGNAL(clicked()), dataProc, SLOT(slot_init_value()));
    connect(dataProc, SIGNAL(valueChanged(QString)), this, SLOT(slot_updata_label(QString)));

    childThread->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_updata_label(const QString &str)
{
    qDebug("the slot of main Thread is running in thread : %d", QThread::currentThread());
    ui->label->setText(str);
}

void MainWindow::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
