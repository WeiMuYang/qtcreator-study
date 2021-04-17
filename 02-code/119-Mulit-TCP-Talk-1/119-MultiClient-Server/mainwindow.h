#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <server.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void slotupdateserver(QString);  //接收server发过来的信号就更新界面信息
    void on_Button_waitConnect_clicked();

private:
    Ui::MainWindow *ui;
    int m_n_port;
    Server *server;
};
#endif // MAINWINDOW_H
