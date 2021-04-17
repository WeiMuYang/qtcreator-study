#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    QString JsonToQString(QJsonObject jsonObject);
    QJsonObject QStringToJson(QString jsonString);
    void AnalysisJsonByQJson();


    void CreateJson1();
    void CreateJson2();



private:
    Ui::MainWindow *ui;
    QByteArray m_byteArray;

};

#endif // MAINWINDOW_H
