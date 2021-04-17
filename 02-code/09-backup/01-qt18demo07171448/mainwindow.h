#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

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

    void on_checkBox_stateChanged(int arg1);


    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    bool m_state;
};

#endif // MAINWINDOW_H
