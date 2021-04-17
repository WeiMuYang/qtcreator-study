#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    // 1. 字节数组 --> 十六进制QString
    QString byteArrayToHexStr(const QByteArray &data);
    // 2. 十六进制QString  --> 字节数组
    QByteArray hexStrToByteArray(const QString &str);
    // 3. CRC8
    unsigned char crc_high_first(unsigned char *ptr, unsigned char len);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
