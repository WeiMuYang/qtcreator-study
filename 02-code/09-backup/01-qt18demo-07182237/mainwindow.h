#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>

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






private:
    Ui::MainWindow *ui;
    bool m_state;
    QScrollArea *m_ScrollArea;
};

#endif // MAINWINDOW_H
