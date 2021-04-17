#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QThread>
#include "dataproc.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QDialog {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slot_updata_label(const QString &str);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QThread *childThread;
    DataProc *dataProc;
};

#endif // MAINWINDOW_H
