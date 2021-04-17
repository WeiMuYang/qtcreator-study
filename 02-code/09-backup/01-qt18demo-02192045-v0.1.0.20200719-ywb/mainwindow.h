#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QStackedLayout>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include "wellsdata.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void magicTime();

    void mianWindowInit();
private slots:
    void on_pushButton_clicked();






    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    bool m_state;
    QScrollArea *m_ScrollArea;          // 打算装进度条
    QStackedLayout * m_pStackedLayout;  // 存放六个井的widget
    int indexOfWell;                    // 井的编号
    QVector <WellsData> wellsOfSix;     // 6个井的容器
};

#endif // MAINWINDOW_H
