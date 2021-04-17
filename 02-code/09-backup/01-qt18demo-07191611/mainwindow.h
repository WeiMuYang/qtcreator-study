#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QStackedLayout>
#include <QVector>
#include <QPushButton>
#include <QLabel>

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


private slots:
    void on_pushButton_clicked();






    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    bool m_state;
    QScrollArea *m_ScrollArea;          // 打算装进度条
    QStackedLayout * m_pStackedLayout;  // 存放六个井的widget
    int indexOfWell;                    // 井的编号
    QVector <QPushButton *> m_ButtonOfWell;// 存放六个井的按钮
    QVector <QLabel *> m_LabelOfWell;   // 每个井的标签，22个



};

#endif // MAINWINDOW_H
