#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>

class MyTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit MyTableWidget(QWidget *parent = 0);
    void initTableWgt();

signals:

public slots:
    void searchTableCheck(int row, int col);
};

#endif // MYTABLEWIDGET_H
