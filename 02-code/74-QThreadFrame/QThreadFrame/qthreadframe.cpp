#include "qthreadframe.h"
#include "ui_qthreadframe.h"

#include <QTimer>
#include <QDebug>

QThreadFrame::QThreadFrame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QThreadFrame)
{
    ui->setupUi(this);

    timer = new QTimer;

    dispThread = new QThread;
    dispWidget = new DispWidget;
    dispWidget->moveToThread(dispThread);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(slot_timer_out()));
    QObject::connect(dispWidget, SIGNAL(signal_disp_send()), this, SLOT(showImage()));
    dispThread->start();

    timer->start(500);


}

QThreadFrame::~QThreadFrame()
{
    delete ui;
}

void QThreadFrame::changeEvent(QEvent *e)
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

void QThreadFrame::paintEvent(QPaintEvent *)
{

    QPainter paint(this);
    paint.drawImage(QPoint(0,0), dispWidget->image);
}

void QThreadFrame::slot_timer_out()
{
    dispWidget->showImage();
    timer->stop();
}

void QThreadFrame::showImage()
{
    qDebug()<<"mainThread: "<<QThread::currentThreadId();
    repaint();
}

