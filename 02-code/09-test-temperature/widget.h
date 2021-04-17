#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QString>


#include "qcustomplot.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
   // void windowInit();
   // void inputdata();
   // void insertTable(QString date, QString t);


private slots:
    // void customplot_init();


    void on_start_clicked();

    void on_pause_clicked();

    void on_clearTable_clicked();

    void on_saveTable_clicked();

    void on_openSerial_clicked();

    void on_closeSerial_clicked();

private:
    Ui::Widget *ui;
    QTimer dataTimer;
    double temperature;

    QTimer *_pTimerUpdate;
    QElapsedTimer _elapsedTimer;
    int fps;
    int interval;
    bool pause;
    double lastPointKey;

};

#endif // WIDGET_H
