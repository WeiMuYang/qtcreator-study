#ifndef QTHREADFRAME_H
#define QTHREADFRAME_H

#include <QDialog>
#include <QThread>
#include <QTimer>
#include <QImage>

#include "dispwidget.h"

namespace Ui {
    class QThreadFrame;
}

class QThreadFrame : public QDialog {
    Q_OBJECT
public:
    QThreadFrame(QWidget *parent = 0);
    ~QThreadFrame();

    void paintEvent(QPaintEvent *);

protected:
    void changeEvent(QEvent *e);

public slots:
    void slot_timer_out();
    void showImage();

private:
    Ui::QThreadFrame *ui;
    QTimer *timer;

    QThread *dispThread;
    DispWidget *dispWidget;
    QImage image;
};

#endif // QTHREADFRAME_H
